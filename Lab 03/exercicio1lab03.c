#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // fork(), exec()
#include<sys/types.h> //tipos de dados como pid_t
#include <sys/wait.h>//wait()

int main()
{
    int pid;
    pid=fork();
    
    if(pid<0){ //erro ao inicializar o fork
        printf("\n\nErro fork.\n\n");
        exit(1);
    }
    
    if(pid>0){ // processo pai
        printf("\nProcesso Pai: id é %d, pid(filho) é %d\n", getpid(), pid);
        sleep(3); // sleep de 3 segundos no processo pai para que o filho possa executar algo
    }else{ // processo filho
        printf("\nProcesso Filho: id é %d, pid(valor) é %d\n", getpid(), pid);
        for(int i=0; i<5; i++){//looping de mensagens
            printf("\nMensagem repetida no processo filho. Num %d",i);
            sleep(1);
        }
        
    }
    return 0;
}
