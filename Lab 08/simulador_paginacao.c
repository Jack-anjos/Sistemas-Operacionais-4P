#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_FRAME 256      // Tamanho de cada frame e página
#define NUM_FRAMES 4           // Número de frames na memória física
#define NUM_PAGINAS 8          // Número de páginas na memória virtual

// Estrutura para representar um frame na memória física
typedef struct {
    int id_frame;
    bool ocupado;
    int id_processo;            // ID do processo que ocupa o frame
    int id_pagina;              // ID da página armazenada no frame
} Frame;

// Estrutura para representar uma página na memória virtual
typedef struct {
    int id_pagina;
    int id_processo;            // ID do processo dono da página
    int frame_associado;        // ID do frame associado
} Pagina;

// Estrutura para a Tabela de Páginas
typedef struct {
    Pagina paginas[NUM_PAGINAS];
} TabelaPaginas;

// Estrutura para a Memória Física
typedef struct {
    Frame frames[NUM_FRAMES];
} MemoriaFisica;

// Função para inicializar a Memória Física
void inicializar_memoria_fisica(MemoriaFisica* memoria_fisica) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        memoria_fisica->frames[i].id_frame = i;
        memoria_fisica->frames[i].ocupado = false;
        memoria_fisica->frames[i].id_processo = -1;  // Nenhum processo associado inicialmente
        memoria_fisica->frames[i].id_pagina = -1;    // Nenhuma página associada inicialmente
    }
}

// Função para inicializar a Tabela de Páginas
void inicializar_tabela_paginas(TabelaPaginas* tabela) {
    for (int i = 0; i < NUM_PAGINAS; i++) {
        tabela->paginas[i].id_pagina = i;
        tabela->paginas[i].id_processo = -1;         // Nenhum processo associado inicialmente
        tabela->paginas[i].frame_associado = -1;     // Nenhum frame associado inicialmente
    }
}

// Função para alocar um frame para uma página
bool alocar_pagina(MemoriaFisica* memoria_fisica, TabelaPaginas* tabela, int id_processo, int id_pagina) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (!memoria_fisica->frames[i].ocupado) {
            // Aloca o frame para a página e processo
            memoria_fisica->frames[i].ocupado = true;
            memoria_fisica->frames[i].id_processo = id_processo;
            memoria_fisica->frames[i].id_pagina = id_pagina;
            tabela->paginas[id_pagina].frame_associado = memoria_fisica->frames[i].id_frame;
            tabela->paginas[id_pagina].id_processo = id_processo;
            return true;
        }
    }
    return false;  // Não há frames livres
}

// Função para desalocar um frame
void desalocar_pagina(MemoriaFisica* memoria_fisica, TabelaPaginas* tabela, int id_pagina) {
    int frame_id = tabela->paginas[id_pagina].frame_associado;
    if (frame_id != -1) {
        memoria_fisica->frames[frame_id].ocupado = false;
        memoria_fisica->frames[frame_id].id_processo = -1;
        memoria_fisica->frames[frame_id].id_pagina = -1;
        tabela->paginas[id_pagina].frame_associado = -1;
        tabela->paginas[id_pagina].id_processo = -1;
    }
}

// Função de tradução de endereço virtual para físico
int traduzir_endereco(int endereco_virtual, TabelaPaginas* tabela) {
    int numero_pagina = endereco_virtual / TAMANHO_FRAME;
    int offset = endereco_virtual % TAMANHO_FRAME;

    // Encontra o frame associado à página
    int frame_id = tabela->paginas[numero_pagina].frame_associado;
    if (frame_id == -1) {
        printf("Page fault! Página %d não está na memória.\n", numero_pagina);
        return -1;
    }
    
    return frame_id * TAMANHO_FRAME + offset;
}

// Programa de teste
int main() {
    MemoriaFisica memoria_fisica;
    TabelaPaginas tabela_paginas;

    inicializar_memoria_fisica(&memoria_fisica);
    inicializar_tabela_paginas(&tabela_paginas);

    // Teste: Alocar páginas para um processo
    int id_processo = 1;
    alocar_pagina(&memoria_fisica, &tabela_paginas, id_processo, 0);
    alocar_pagina(&memoria_fisica, &tabela_paginas, id_processo, 1);

    // Teste de tradução de endereços
    int enderecos_virtuais[] = {100, 300, 500, 700};
    for (int i = 0; i < sizeof(enderecos_virtuais) / sizeof(enderecos_virtuais[0]); i++) {
        int endereco_virtual = enderecos_virtuais[i];
        int endereco_fisico = traduzir_endereco(endereco_virtual, &tabela_paginas);
        if (endereco_fisico != -1) {
            printf("Endereço virtual %d -> Endereço físico %d\n", endereco_virtual, endereco_fisico);
        }
    }

    // Teste: Desalocar página e tentar traduzir endereço novamente
    desalocar_pagina(&memoria_fisica, &tabela_paginas, 0);
    int endereco_fisico_desalocado = traduzir_endereco(100, &tabela_paginas);
    if (endereco_fisico_desalocado == -1) {
        printf("Página desalocada corretamente.\n");
    }

    return 0;
}
