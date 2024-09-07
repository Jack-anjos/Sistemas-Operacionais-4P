Instruções para Compilar e Executar os Programas:
1. Como compilar os programas:
Utilize o comando gcc para compilar cada um dos programas. Por exemplo:

Para compilar o programa exercicio01lab03.c:

bash
Copiar código
gcc -o exercicio01lab03 exercicio01lab03.c
Para compilar o programa exercicio2lab03.c:

bash
Copiar código
gcc -o exercicio2lab03 exercicio2lab03.c
Para compilar o programa exercicio3lab03.c:

bash
Copiar código
gcc -o exercicio3lab03 exercicio3lab03.c
2. Como executar os programas:
Após a compilação, execute os programas utilizando os seguintes comandos:

Para o programa exercicio01lab03:

bash
Copiar código
./exercicio01lab03
Para o programa exercicio2lab03:

bash
Copiar código
./exercicio2lab03
Para o programa exercicio3lab03:

bash
Copiar código
./exercicio3lab03
3. Como comprovar que os resultados propostos foram alcançados:
exercicio01lab03.c:
Este programa cria um processo filho e um processo pai usando o comando fork(). O processo filho imprime uma mensagem repetida 5 vezes, com um intervalo de 1 segundo entre cada mensagem, enquanto o processo pai espera 3 segundos antes de encerrar. Confira a saída no terminal para ver as mensagens geradas pelos dois processos.

exercicio2lab03.c:
Este programa também utiliza fork(), mas o processo pai espera o filho terminar através da função wait(). Verifique no terminal se o processo pai só exibe a mensagem "Processo filho terminou" após o término do processo filho.

exercicio3lab03.c:
Neste programa, o processo filho executa o comando ls -l usando a função exec(), e o processo pai espera o filho terminar com wait(). Verifique no terminal se a listagem detalhada do diretório (comando ls -l) é exibida e se a mensagem "Processo filho terminou" é mostrada após a execução do comando.
