#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <string.h>
#include <stdlib.h>

// Função para converter caminho relativo para absoluto
char* GetAbsolutePath(const char* relativePath) {
    char absolutePath[MAX_PATH];
    
    // Se já é caminho absoluto (começa com C:\, etc), retorna cópia
    if (strlen(relativePath) > 2 && relativePath[1] == ':') {
        return _strdup(relativePath);
    }
    
    // Converter para caminho absoluto
    if (_fullpath(absolutePath, relativePath, MAX_PATH) == NULL) {
        printf("[ERROR] Failed to convert path to absolute: %s\n", relativePath);
        return NULL;
    }
    
    printf("[INFO] Converted path: %s -> %s\n", relativePath, absolutePath);
    return _strdup(absolutePath);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("usage: dll-injector.exe <path-to-dll> <PID>\n");
        return 1;
    }
    
    // Converter para caminho absoluto
    char* absolute_dll_path = GetAbsolutePath(argv[1]);
    if (absolute_dll_path == NULL) {
        printf("[ERROR] Invalid DLL path\n");
        return 1;
    }
    
    DWORD PID = atoi(argv[2]);
    
    printf("[INFO] Target PID: %d\n", PID);
    printf("[INFO] DLL absolute path: %s\n", absolute_dll_path);
    
    // Verificar se o arquivo existe
    if (GetFileAttributesA(absolute_dll_path) == INVALID_FILE_ATTRIBUTES) {
        printf("[ERROR] DLL file not found: %s\n", absolute_dll_path);
        free(absolute_dll_path);
        return 1;
    }
    
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
    if (hProcess == NULL) {
        printf("[ERROR] OpenProcess failed: %d\n", GetLastError());
        free(absolute_dll_path);
        return 1;
    }
    
    // Alocar memória
    SIZE_T path_len = strlen(absolute_dll_path) + 1;
    LPVOID allocated_mem = VirtualAllocEx(hProcess, NULL, path_len, 
                                         MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (allocated_mem == NULL) {
        printf("[ERROR] VirtualAllocEx failed: %d\n", GetLastError());
        CloseHandle(hProcess);
        free(absolute_dll_path);
        return 1;
    }
    
    printf("[INFO] Memory allocated at: %p (size: %zu bytes)\n", allocated_mem, path_len);
    
    // Escrever caminho absoluto
    SIZE_T bytesWritten = 0;
    BOOL writeResult = WriteProcessMemory(hProcess, allocated_mem, absolute_dll_path, path_len, &bytesWritten);
    
    printf("[DEBUG] WriteProcessMemory - Result: %d, Bytes written: %zu/%zu\n", 
           writeResult, bytesWritten, path_len);
    
    if (!writeResult || bytesWritten != path_len) {
        printf("[ERROR] WriteProcessMemory failed: %d\n", GetLastError());
        VirtualFreeEx(hProcess, allocated_mem, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        free(absolute_dll_path);
        return 1;
    }
    
    HMODULE kernel32Base = GetModuleHandleA("kernel32.dll");
    FARPROC load_library_address = GetProcAddress(kernel32Base, "LoadLibraryA");
    
    printf("[INFO] LoadLibraryA address: %p\n", load_library_address);
    
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, 
                                       (LPTHREAD_START_ROUTINE)load_library_address, 
                                       allocated_mem, 0, NULL);
    if (hThread == NULL) {
        printf("[ERROR] CreateRemoteThread failed: %d\n", GetLastError());
        VirtualFreeEx(hProcess, allocated_mem, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        free(absolute_dll_path);
        return 1;
    }
    
    printf("[INFO] Remote thread created: %p\n", hThread);
    
    WaitForSingleObject(hThread, INFINITE);
    
    DWORD exitCode;
    if (GetExitCodeThread(hThread, &exitCode)) {
        if (exitCode == 0) {
            printf("[ERROR] LoadLibrary failed! Error: %d\n", GetLastError());
        } else {
            printf("[SUCCESS] DLL loaded at base address: %p\n", exitCode);
        }
    }
    
    CloseHandle(hThread);
    CloseHandle(hProcess);
    free(absolute_dll_path);
    
    return 0;
}