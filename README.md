# Processamento-de-matrizes-por-segmenta-o-de-arquivo

Trabalho realizado para a disciplina de Algoritmos e Estrutura de Dados 2 \
CEFET - MG Campus V \
Gabriel Vitor Silva \

## Compilar ##
```
(https://replit.com/@GabrielGvs)
```
## introdução ##
### Apresentação do Problema ###
Neste trabalho, cada aluno deve implementar um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande é fornecido no formato NxN com valores de ponto flutuante ou inteiros como entrada. Este é processado a partir de várias coordenadas introduzidas por um segundo arquivo, o coordenadas.txt. Em coordenadas.txt deve ser descrito por linha uma dupla de i e j correspondendo a posição inicial e final a ser lida. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10. 

## Desenvolvimento: #
Para desenvolvimento desse trabalho foram usadas as fuçoes FSEEK e FSCANF para pegar as cordenadas da submatriz no arquivo cordenadas.txt, e foi usada as funçoes FSEEK e FGETS para localizaão e retiramento da linha da submatriz do arquivo matriz.txt, com a função STRTOK foi feita a tolkenização da linha e dividindoa em sub strings e com a função ATOI foram transformadas em inteiros e assim armazenando todos dados da primeira linha na linha da matriz normal e na coluna da matriz transposta, isso em um laço de repetição do tamanho do numero de linhas da submatriz e depois desse laço foi feita a multiplicação da matriz pela sua transposta e armazenando o resultado na tabela hash com a cordenada como key.
