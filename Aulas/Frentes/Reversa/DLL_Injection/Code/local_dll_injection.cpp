#include <windows.h>
#include <stdio.h> // Para operações input/output (print)

DWORD WINAPI threadFunc(LPVOID lpParam) {
	// Código a ser rodado pela thread
	printf("Thread is running...\n");
	return 0;
}

int main(int argc, char **argv) {
	// Parâmetro que recebe: caminho da nossa DLL
	PCSTR path_to_dll = argv[1];

    /*
    * API Windows LoadLibrary - Carrega nossa DLL maliciosa no espaço de 
	* memória do nosso processo no disco.
    *
    * Se essa call é feita com sucesso, vai ativar o trigger do 
    * callback DLL_PROCESS_ATTACH, que executa nosso código malicioso
    * (MessageBox)
    */

    // Carrega nossa DLL no espaço de memória do nosso processo no disco
    HINSTANCE hDll = LoadLibraryA(argv[1]);
	if (hDll == NULL) {
		printf("Failed to load DLL.\n");
		return 1;
	}

    /*
    * Para ativar o DLL_THREAD_ATTACH, apenas precisamos criar uma thread 
    * que não faz absolutamente nada.
    * 
    * Uso da API CreateThread. Se a thread for criada, a segunda
    * MessageBox vai ser mostrada.
    */

	// Cria uma thread, e passamos para ela uma função boba
	HANDLE hThread = CreateThread(NULL, 0, threadFunc, NULL, 0, NULL);
	if (hThread == NULL) {
		printf("Failed to create thread: %d\n", GetLastError());
		return 1;
	}

    /*
    * A API WaitForSingleObject para o fluxo de execução do programa
    * até que a thread especificada retorne ou termine.
    * 
    * QUando a thread termina, o callback vai ser ativado e a
    * MessageBox API vai rodar.
    */

	// Wait for a short time
	WaitForSingleObject(hThread, INFINITE);

	// Close the thread handle
	CloseHandle(hThread);

    /*
    * A API FreeLibrary faz o unload da nossa DLL maliciosa e ativa
    * o último callback
    */

	// Free the DLL
	FreeLibrary(hDll);

	return 0;
}