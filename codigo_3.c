#include <unistd.h>  // Librería para manejo de procesos y funciones como fork(), sleep(), getpid(), getppid()
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t rf; // Variable para almacenar el resultado de fork()
    
    // Crear un nuevo proceso con fork()
    rf = fork();
    
    // Evaluar el valor devuelto por fork()
    switch (rf) {
        case -1:
            // Si fork() devuelve -1, hubo un error al crear el proceso hijo
            printf("No he podido crear el proceso hijo\n");
            break;
        
        case 0:
            // Si fork() devuelve 0, estamos en el proceso hijo
            printf("Soy el hijo, mi PID es %d y mi PPID es %d\n", getpid(), getppid());
            sleep(20); // Suspender el proceso hijo por 20 segundos
            break;
        
        default:
            // Si fork() devuelve un valor positivo, estamos en el proceso padre
            // Corregido error de sintaxis en el printf (falta de paréntesis) y añadido salto de línea
            printf("Soy el padre, mi PID es %d y el PID de mi hijo es %d\n", getpid(), rf);
            sleep(30); // Suspender el proceso padre por 30 segundos (acaba antes el hijo)
    }
    
    // Este código se ejecuta tanto en el proceso padre como en el hijo
    printf("Final de ejecución de %d\n", getpid());
    exit(0); // Terminar el proceso de manera limpia
}
