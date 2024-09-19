#include <unistd.h>  // Librería para manejo de procesos y funciones como fork(), execv(), sleep()
#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

int main(int argc, char *argv[]) { // Corregido 'arc' por 'argc'
    int i;
    
    // Mostrar los argumentos con los que fue llamado el programa
    printf("Ejecutando el programa invocador(execprog1). Sus argumentos son:\n");
    
    // Ciclo para imprimir los argumentos (corregido el segundo for innecesario)
    for(i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    sleep(10); // Suspende el proceso durante 10 segundos
    
    // Cambiar el nombre del primer argumento a "execprog2"
    strcpy(argv[0], "execprog2");
    
    // Invocar un nuevo programa llamado "execprog2"
    if(execv("./execprog2", argv) < 0) {
        // Si execv falla, mostrar un mensaje de error y salir con código 1
        printf("Error en la invocacion a execprog2\n");
        exit(1);
    }
    
    exit(0); // Terminar el proceso de manera limpia
}
