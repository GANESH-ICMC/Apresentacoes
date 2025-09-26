#include <windows.h>
#include <stdio.h>

// argc = número de argumentos, argv = array dos argumentos passados no terminal
int main(int argc, char** argv) {
	if (argc != 3) {
        /* 
         * O EXE recebe dois parâmetros: caminho completo para nossa DLL
         * e o ID do processo em que queremos injetar a DLL
         * 
         * O ID pode ser obtido com uma ferramenta como process hacker.
         * Ou pode ser obtido via código, pegando um snapshot de todos os 
         * processos e procurando por um programa específico e seu ID.
        */
        printf("usage: dll-injector.exe <path-to-dll> <PID>\n");
		return 1;
	}
	
	// Captura caminho (COMPLETO) da DLL (primeiro argumento)
	PCSTR dll_path = argv[1];
	// Captura PID do processo alvo (segundo argumento). Converte string ASCII para inteiro
	DWORD PID = atoi(argv[2]);
	
	// Obtém handle (identificador do SO) do processo
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (hProcess == NULL) {
		printf("Failed to retrieve handle to remote process: %d\n", GetLastError());
		return 1;
	}
	
	// Aloca memória dentro do processo alvo para armazenar o caminho da DLL
	LPVOID allocated_mem = VirtualAllocEx(hProcess, NULL, strlen(dll_path) + 1, (MEM_COMMIT | MEM_RESERVE), PAGE_READWRITE);
	if (allocated_mem == NULL) {
		printf("Failed to allocate memory in remote process: %d\n", GetLastError());
		return 1;
	}
	
	// Imprime endereço da memória alocada no processo remoto
	printf("Memory allocated at: %p\n", allocated_mem);
	
	// Escreve o caminho da DLL na memória alocada do processo remoto
	BOOL write_result = WriteProcessMemory(hProcess, allocated_mem, dll_path, strlen(dll_path) + 1, NULL);
	if (!write_result) {
		printf("Failed to write DLL path to remote memory: %d\n", GetLastError());
		return 1;
	}
	
	// Obtém handle (base address) da DLL kernel32.dll
	HMODULE kernel32Base = GetModuleHandleW(L"kernel32.dll");
	if (kernel32Base == NULL) {
		printf("Failed to retrieve handle to kernel32.dll: %d\n", GetLastError());
		return 1;
	}
	
	// Obtém endereço da função LoadLibraryA dentro da kernel32.dll
	FARPROC load_library_address = GetProcAddress(kernel32Base, "LoadLibraryA");	
	// Cria uma thread remota no processo alvo que executará LoadLibraryA
	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)load_library_address, allocated_mem, 0, NULL);
	if (hThread == NULL) {
		printf("Failed to create thread in remote process: %d\n", GetLastError());
		return 1;
	}
	
	// Aguarda a thread remota terminar sua execução
	WaitForSingleObject(hThread, INFINITE);
	
	// Limpeza: fecha os handles abertos
	CloseHandle(hProcess);

	printf("DLL injection completed successfully!\n");
	return 0;
}