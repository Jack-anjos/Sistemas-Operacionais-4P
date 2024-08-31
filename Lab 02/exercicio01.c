#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   


int main() {
    int fileDescriptor;
    char buffer[128];
    ssize_t bytesRead;

    // Abre o arquivo para leitura
    fileDescriptor = open("lab2_ex1.txt", O_RDONLY);

    // Verifica se o arquivo foi aberto com sucesso
    if (fileDescriptor < 0) {
        // Se deu erro encerre o programa
        printf("Erro ao abrir o arquivo");
        return -1; 
    }

    // Le o conteúdo do arquivo para o buffer
    bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);

    // Adicionar um caractere nulo ao final do buffer
    buffer[bytesRead] = '\0';

    // Printa o conteúdo lido na tela
    printf("Conteudo do arquivo:\n%s\n", buffer);

    // Feche o arquivo após a leitura
    close(fileDescriptor);

    return 0;
}
