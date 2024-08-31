#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   


int main() {
    int fileDescriptor;
    char buffer[128];
    ssize_t bytesRead;
    int lineCount = 1;

    // Abre o arquivo para leitura
    fileDescriptor = open("lab2_ex2.txt", O_RDONLY);

    // Verifica se o arquivo foi aberto com sucesso
    if (fileDescriptor < 0) {
        // Se deu erro encerre o programa
        printf("Erro ao abrir o arquivo");
        return -1; 
    }

    // Le o conteúdo do arquivo para o buffer
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1)) > 0) {

        // Contar o número de quebras de linha
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
            }
        }
    }

    // Printa a quantidade de linhas ("\n" contidos no arquivo) na tela
    printf("Numero total de linhas: %d\n", lineCount);

    // Feche o arquivo após a leitura
    close(fileDescriptor);

    return 0;
}
