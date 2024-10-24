
Instruções para Compilar e Executar o Programa:

1. Como compilar o programa:
Utilize o comando gcc para compilar o programa. Por exemplo:

Para compilar o programa lab6_memoria.c:

gcc -o lab6_memoria lab6_memoria.c

2. Como executar o programa:
Após a compilação, execute o programa utilizando o seguinte comando:

./lab6_memoria

3. Para comprovar que os resultados propostos foram alcançados:
Este programa implementa uma lista ligada simples e oferece as funcionalidades de remover o primeiro elemento, imprimir a lista e calcular quantas células podem ser criadas com a memória disponível.

- Após a execução, será exibido o tamanho de cada célula em bytes e a quantidade de células que poderiam ser alocadas com a memória disponível.
- A lista original será exibida e, a cada remoção de um elemento, o estado atualizado da lista será mostrado no terminal.

Resultados do prompt: 
Cada célula ocupa 16 bytes
Qtd de celulas que poderiam ser criados com a memoria disponível = 93684992 

Lista completa: 10 -> 15 -> 20 -> NULL
Lista apos remover o primeiro elemento: 15 -> 20 -> NULL
Lista apos remover o segundo elemento: 20 -> NULL
Lista apos remover o terceiro elemento: NULL
