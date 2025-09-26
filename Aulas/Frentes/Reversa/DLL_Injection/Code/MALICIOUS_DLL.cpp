#include <windows.h>

// "Main" da nossa DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    // Dependendo do callback, retorna uma mensagem diferente
    switch (ul_reason_for_call) {
    // DLL é carregada/injetada no espaço de memória
    case DLL_PROCESS_ATTACH:
        MessageBoxA(NULL, "DLL Maliciosa inserida e executada!", "WARNING", MB_ICONEXCLAMATION);
        break;
    // DLL é descarregada/liberada do espaço de memória
    case DLL_PROCESS_DETACH:
        MessageBoxA(NULL, "DLL Maliciosa Liberada!", "WARNING", MB_ICONEXCLAMATION);
        break;
    // Thread criada
    case DLL_THREAD_ATTACH:
        MessageBoxA(NULL, "Thread Criada!", "WARNING", MB_ICONEXCLAMATION);
        break;
    // Thread encerrada
    case DLL_THREAD_DETACH:
        MessageBoxA(NULL, "Thread Encerrada!", "WARNING", MB_ICONEXCLAMATION);
        break;
    }
    return TRUE;
}