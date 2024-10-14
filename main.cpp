#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        cerr << "Error al intentar crear el proceso hijo." << endl;
        return 1;
    }

    if (pid == 0) {
        // Este es el proceso hijo
        cout << "Proceso hijo iniciado. PID: " << getpid() << endl;
        cout << "Proceso hijo trabajando..." << endl;
        sleep(2); // Simulamos que el hijo está haciendo algún trabajo
        cout << "Proceso hijo finalizado." << endl;
    } 
    else {
        // Este es el proceso padre
        cout << "Proceso padre. PID: " << getpid() << endl;
        cout << "Esperando que el proceso hijo termine..." << endl;

        // Esperamos a que el proceso hijo termine
        wait(NULL);
        cout << "El proceso hijo ha terminado." << endl;
    }

    return 0;
}
