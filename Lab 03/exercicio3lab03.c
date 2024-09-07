#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Cria o processo filho

    if (pid < 0) {
        // Verifica se houve erro na criação do processo filho
        perror("Erro ao criar o processo filho");
        return 1;
    }

    if (pid == 0) {
        // Código do processo filho
        printf("Processo filho (PID: %d) executando 'ls'.\n", getpid());

        // Substitui o código do processo filho pelo programa 'ls' usando exec()
        execlp("ls", "ls", "-l", NULL);

        // Se exec falhar, exibe uma mensagem de erro
        perror("Erro ao executar o comando 'ls'");
        return 1;
    } else {
        // Código do processo pai
        printf("Processo pai (PID: %d) aguardando o término do processo filho (PID: %d).\n", getpid(), pid);

        // O processo pai espera o processo filho terminar
        wait(NULL);

        // Após o término do filho
        printf("Processo filho terminou.\n");
    }

    return 0;
}
