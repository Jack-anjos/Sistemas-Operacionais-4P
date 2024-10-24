#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <sys/sysinfo.h>
// definindo estrutra da lista ligada 
struct reg {
    int conteudo; 
    struct reg *prox; 
}; 
typedef struct reg celula;

// imprime a lista ligada
void imprime_lista(celula *inicio){
    celula *atual = inicio;
    
    while(atual != NULL){ // enquanto o valor de proximo não for vazio, segue imprimindo valores
        printf("%d -> ", atual ->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// limpar a lista ligada
void limpar_lista(celula **inicio){
    celula *atual = *inicio;
    celula *prox;
    while(atual != NULL){ // enquanto o valor de proximo não for vazio, segue liberando as células
        prox= atual->prox;
        free(atual); // libera espaço na memória
        atual = prox;
    }
    *inicio=NULL;
}

// remover primeiro elemento da lista
void remover_primeiro(celula **inicio) {
    if (*inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    celula *temp = *inicio; // guarda ponteiro para o primeiro elemento
    *inicio = (*inicio)->prox; // torna o próximo elemento o atual
    free(temp); // libera a memória do primeiro elemento
}
int main(){
	    // criando as 3 células
        celula *c1 = (celula *)malloc(sizeof(celula));
        celula *c2 = (celula *)malloc(sizeof(celula));
        celula *c3 = (celula *)malloc(sizeof(celula));
        
        // verificando o tamanho da estrutura de "celula"
        unsigned long tamanho_celula = sizeof(celula);
        printf("Cada célula ocupa %lu bytes\n", tamanho_celula);
        struct sysinfo info;

        // obter informações do sistema
        sysinfo(&info);

        // memória livre disponível (em bytes)
        unsigned long tamanho_memoria = info.freeram;
        printf("Qtd de celulas que poderiam ser criados com a memoria disponível = %lu \n\n", tamanho_memoria/tamanho_celula);
        
        // definindo conteúdos
        c1 -> conteudo = 10;
        c2 -> conteudo = 15;
        c3 -> conteudo = 20;
        // defininindo ponteiros
    	c1 -> prox = c2;
    	c2-> prox = c3;
    	c3 -> prox = NULL; // por enquanto não tem próximo
    	printf("Lista completa: ");
    	imprime_lista(c1);
    	
    	// removendo elementos um por um
        remover_primeiro(&c1); // remove o primeiro (c1)
        printf("Lista apos remover o primeiro elemento: ");
        imprime_lista(c1);
    
        remover_primeiro(&c1); // remove o próximo (c2)
        printf("Lista apos remover o segundo elemento: ");
        imprime_lista(c1);
    
        remover_primeiro(&c1); // remove o último (c3)
        printf("Lista apos remover o terceiro elemento: ");
        imprime_lista(c1);
}
