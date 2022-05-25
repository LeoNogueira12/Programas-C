#include<stdio.h>
#define LINHA 10
#define COLUNA 10

int i,j, vetor[LINHA][COLUNA], maior, posl, posc;

int main(){
	for (i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			printf("Coloque o numero na matriz, na posicao(%i,%i)\n", i,j);
			scanf("%d", &vetor[i][j]);
		}
	}
	for (i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			if(vetor[i][j]>maior){
				maior = vetor[i][j];
				posl = i;
				posc = j;
			}
		}
	}
	printf("O maior elemento inteiro eh o %d na posicao (%d,%d).",maior,posl,posc);
	
	return 0;
}