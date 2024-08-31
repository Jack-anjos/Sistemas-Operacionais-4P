#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   

int main(){
    int fileDescriptor;
    char buffer[128];
    ssize_t bytesRead;
    
    // Abre o arquivo origem
    fileDescriptor = open("lab2_ex3_origem.txt", O_RDONLY);

   // Verifica se o arquivo foi aberto com sucesso
    if (fileDescriptor < 0){
        // se deu erro encera o programa
        printf("Erro ao abrir o arquivo");
        return -1;
    }

    // Cria o arquivo destino
    int new_file = open("lab2_ex3_destino.txt", O_WRONLY | O_CREAT | O_TRUNC);
   // Verifica se o arquivo foi criado com sucesso
    if (new_file < 0){
        // se deu erro encera o programa
        printf("Erro ao criar o arquivo");
        return -1;
    }
    // Le o conteudo da origem
    bytesRead=read(fileDescriptor, buffer, sizeof(buffer)-1);
    // Escreve o conteudo do buffer para o destino
    write(new_file, buffer, sizeof(buffer)-1);

    // Fecha ambos os arquivos
    close(fileDescriptor);
    close(new_file);
 
}   