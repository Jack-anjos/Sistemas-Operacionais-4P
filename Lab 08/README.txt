Simulador de Memória Virtual com Paginação
Descrição
Este programa é um simulador básico de memória virtual com paginação. Ele foi desenvolvido para demonstrar o funcionamento de sistemas de paginação, incluindo a alocação de páginas para processos, gerenciamento de frames na memória física, e tradução de endereços virtuais para endereços físicos.

Estruturas de Dados
Frame: Representa um frame (quadro) na memória física.

id_frame: Identificador do frame.
ocupado: Indica se o frame está ocupado.
id_processo: ID do processo ao qual o frame pertence.
id_pagina: ID da página armazenada no frame.
Pagina: Representa uma página na memória virtual.

id_pagina: Identificador da página.
id_processo: ID do processo dono da página.
frame_associado: ID do frame físico associado à página.
TabelaPaginas: Representa a tabela de páginas que mapeia cada página virtual para um frame físico.

paginas: Array de páginas que mantém o mapeamento entre páginas virtuais e frames físicos.
MemoriaFisica: Representa a memória física do sistema, contendo os frames.

frames: Array de frames para armazenar páginas.
Funções
inicializar_memoria_fisica:

Inicializa a estrutura MemoriaFisica, definindo todos os frames como desocupados e sem páginas ou processos associados.
inicializar_tabela_paginas:

Inicializa a tabela de páginas (TabelaPaginas), sem associar nenhum frame físico a uma página.
alocar_pagina:

Procura um frame livre na memória física e, se encontrar, o associa a uma página específica de um processo. A função atualiza a estrutura do frame e da página para indicar a alocação.
Parâmetros:
memoria_fisica: A estrutura que representa a memória física.
tabela: A tabela de páginas.
id_processo: ID do processo que está alocando a página.
id_pagina: ID da página a ser alocada.
Retorno: true se a alocação foi bem-sucedida, false se não há frames livres.
desalocar_pagina:

Libera um frame que foi alocado para uma página específica. A função remove o mapeamento na tabela de páginas e libera o frame.
Parâmetros:
memoria_fisica: A estrutura que representa a memória física.
tabela: A tabela de páginas.
id_pagina: ID da página a ser desalocada.
traduzir_endereco:

Converte um endereço virtual em um endereço físico usando a tabela de páginas. A tradução extrai o número da página e o deslocamento (offset) dentro da página, verifica o frame associado, e combina o número do frame com o offset para obter o endereço físico.

Parâmetros:
endereco_virtual: Endereço virtual a ser traduzido.
tabela: A tabela de páginas.
Retorno: Endereço físico correspondente, ou -1 em caso de page fault.
Programa de Teste
O programa de teste no main realiza as seguintes operações:

Inicialização:

Inicializa a memória física e a tabela de páginas.
Alocação de Páginas:

Aloca algumas páginas para um processo de exemplo, associando-as a frames físicos na memória.

Tradução de Endereços Virtuais:

Testa a tradução de alguns endereços virtuais para endereços físicos e imprime os resultados.
Caso o endereço virtual não tenha uma página alocada (page fault), o programa informa que a página não está na memória.

Desalocação e Novo Teste:

Desaloca uma página e tenta acessar o endereço virtual correspondente novamente, demonstrando o funcionamento de uma página desalocada.
Exemplo de Execução
Ao executar o programa, ele deve exibir uma série de mensagens mostrando:

Alocações de páginas para frames específicos.
Traduções de endereços virtuais para físicos.
Mensagens de page fault para endereços que não têm páginas alocadas.


Como Compilar e Executar
Compile o programa usando um compilador C:

bash
gcc simulador_paginacao.c -o simulador_paginacao
Execute o programa:

bash
./simulador_paginacao
O programa exibirá o funcionamento do sistema de paginação e os resultados das traduções de endereços.