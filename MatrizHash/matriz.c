#include "matriz.h"

void criarMatriz() {
  FILE *pont_Mat;
  int randNumber = rand() % 1000;

  // abrindo o arquivo
  pont_Mat = fopen("matriz.txt", "w");

  srand(time(NULL));

  for (int i = 1; i < 10001; i++) {

    randNumber = rand() % 10;

    if (i > 0 && i % 100 == 0) {

      if (randNumber < 100 && randNumber >= 10) {
        fprintf(pont_Mat, "0%d  ", randNumber);
      } else if (randNumber < 10) {
        fprintf(pont_Mat, "00%d  ", randNumber);
      } else {
        fprintf(pont_Mat, "%d  ", randNumber);
      }
      fprintf(pont_Mat, "\n");
    } else {
      if (randNumber < 100 && randNumber >= 10) {
        fprintf(pont_Mat, "0%d  ", randNumber);
      } else if (randNumber < 10) {
        fprintf(pont_Mat, "00%d  ", randNumber);
      } else {
        fprintf(pont_Mat, "%d  ", randNumber);
      }
    }
  }

  // fechando arquivo
  fclose(pont_Mat);

  // mensagem para o usuário
  printf("O arquivo foi criado com sucesso!");
}

void buscarMatriz() {
  FILE *pont_Mat;
  FILE *pont_Cor;
  int test;
  int cont;
  int coluna;
  int mat[10][10];
  int trans[10][10];
  int result[10][10];
  int cordA,cordB,cordC,cordD;

  char info[256];
  char *pt;
  int KeyLinha = 1;
  int KeyColuna = 1;
  int c = 0;
  int l = 0;

  cont = 0;
  pont_Mat = fopen("matriz.txt", "r");
  pont_Cor = fopen("cordenadas.txt", "r");

  if (pont_Mat == NULL && pont_Cor)

    printf("Erro, nao foi possivel abrir o arquivo\n");

  else {
    
    while(cont<2){
      
    fseek(pont_Cor, 8*cont,SEEK_SET);
    fscanf(pont_Cor,"%d %d %d %d", &cordA,&cordB,&cordC,&cordD);
    printf("\ncordA = %d \n cordB = %d \n cordC = %d \n cordD = %d \n",cordA,cordB,cordC,cordD);
    KeyLinha= cordA;
      cont++;
    for (int i = 0; i < (cordC-cordA)+1; i++) {

      fseek(pont_Mat, 502 * (KeyLinha-1) + 5 * (cordB-1), SEEK_SET);
      fgets(info, 5*(cordD-cordB+1), pont_Mat);

      c = 0;
      KeyColuna = 0;
      pt = strtok(info, "  ");
      while (pt) {
        int numero = atoi(pt);

        printf("\nposição da submatriz i=%d j= %d numero= %d", l, c, numero);
        mat[l][c] = numero;
        trans[c][l] = numero;
        c++;
        KeyColuna++;

        pt = strtok(NULL, "  ");
      };
      l++;
      KeyLinha++;
      printf("\n");
    }
    
    // printf("%s\n", info);
    for (int i = 0; i < (cordC-cordA)+1; i++) {
      for (int j = 0; j < (cordC-cordA)+1; j++) {
        int temp = 0;
        for (int k = 0; k < (cordD-cordB)+1; k++) {
          temp += mat[i][k] * trans[k][j];
         
        }
        result[i][j] = temp;
      }
    }
    printf("\n normal\n");
    for (int i = 0; i < (cordC-cordA)+1; i++) {

      for (int j = 0; j < (cordD-cordB)+1; j++) {
        printf("%d ", mat[i][j]);
      }
      printf("\n");
    }
     printf("\n transposta\n");
    for (int i = 0; i < (cordC-cordA)+1; i++) {

      for (int j = 0; j < (cordD-cordB)+1; j++) {
        printf("%d ", trans[i][j]);
      }
      printf("\n");
    }
    
     printf("\n resultado\n");
    for (int i = 0; i < (cordC-cordA)+1; i++) {

      for (int j = 0; j < (cordD-cordB)+1; j++) {
        printf("%d ", result[i][j]);
      }
      printf("\n");
    }
      

    }
    fclose(pont_Mat);
    fclose(pont_Cor);
  
}
  }
  


void Initialize(HashTable *h, int M){
	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	for(int i=0; i<M; i++){
		h->table[i].key   = -1;
		h->table[i].value = 0;
	}

	h->M = M;
}


void Imprime(HashTable *h){
	for(int i=0; i<h->M; i++)
		printf("KEY:%d - VALUE:%d\n", h->table[i].key, h->table[i].value);
}


int getValue(HashTable *h, int key){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != key){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			return -1;
		}
	}

	return h->table[idx].value;
}

void Insert(HashTable *h, int key, int value){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != -1){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			printf("OPENED HASH IS FULL!\n");
			return;
		}
	}	
	
	h->table[idx].key   = key;
	h->table[idx].value = value;
}

