/*Escreva um algoritmo que receba uma matriz B[9][9] de reais e retorna a soma dos elementos das
linhas pares de B.*/
#include<stdio.h>
#define LINHA 10
#define COLUNA 10

int B[LINHA][COLUNA],soma;
int i,j;


int main(){
	for(i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			printf("Coloque os elementos da matriz na posicao (%d,%d):\n", i,j);
			scanf("%d", &B[i][j]);
		}
	}
		for(i=0;i<LINHA;i+=2){
		for(j=0;j<COLUNA;j++){
			printf("%d\t", B[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<LINHA;i+=2){
		for(j=0;j<COLUNA;j++){
			soma=soma+B[i][j];
		}
	}
	printf("A soma de todos os elementos das linhas pares de B eh: %d", soma);
	
	return 0;
}