#include <stdio.h>
#define N 5

float preco[N], maior=0,menor =999999,vt;
char produto[N];
int estoque[N];
int menu, i, d, maiores=0, menores=99999999, busca;
char pmaior, pmenor, pmaiores, pmenores, j,k,l,m,n;

int main(){
	printf("Sistema operando. Primeiramente cadastre os 5 produtos. \n");
		for(i=0;i<N;i++){
				d=i+1;
				printf("Cadastre o %d produto com seu identificador (letra): \n", d);
				scanf("%c", &produto[i]);
				getchar();		
				j=produto[0];
				k=produto[1];
				l=produto[2];
				m=produto[3];
				n=produto[4];
			}
			for(i=0;i<N;i++){
				printf("Qual eh o estoque do produto %c ?\n", produto[i]);
				scanf("%i", &estoque[i]);	
				printf("Qual eh o preco do produto %c ? (use ponto para valores com virgula)\n", produto[i]);
				scanf("%f", &preco[i]);
			}
	do{
		printf("O que deseja consultar? \n1 - Lista dos produtos.\n2 - Buscar produto.\n3 - Produto mais caro.\n4 - Produto mais barato.\n5 - Produto com maior estoque.\n6 - Produto com menor estoque.\n7 - Valor total do estoque.\n8-Sair.\n");
		scanf("%i", &menu);
		switch (menu){					
			case 1:for(i=0; i<N;i++){
				printf("Produto %c \n", produto[i]);		
			}
				break;
				
			case 2:printf("Qual produto deseja buscar? \n1 - %c\n2 - %c\n3 - %c\n4 - %c\n5 - %c\n", produto[0],produto[1],produto[2],produto[3],produto[4]);
			scanf("%i", &busca);
			switch(busca){
				case 1: printf("O estoque e preco do produto sao: %i, %f\n", estoque[0], preco[0]);
				break;
				case 2: printf("O estoque e preco do produto sao: %i, %f\n", estoque[1], preco[1]);
				break;
				case 3: printf("O estoque e preco do produto sao: %i, %f\n", estoque[2], preco[2]);
				break;
				case 4: printf("O estoque e preco do produto sao: %i, %f\n", estoque[3], preco[3]);
				break;
				case 5: printf("O estoque e preco do produto sao: %i, %f\n", estoque[4], preco[4]);
				break;
			}
				break;
				
			case 3:for(i=0; i<N;i++){
				if(preco[i]>maior){
					maior = preco[i];
					pmaior = produto[i];
				}
			}
				printf("O produto mais caro eh %c com o preco de %f.\n", pmaior, maior);
				break;
				
			case 4:for(i=0; i<N;i++){
				if(preco[i]<menor){
					menor = preco[i];
					pmenor = produto[i];
				}
			}
				printf("O produto mais barato eh %c com o preco de %f.\n", pmenor, menor);
				break;
				
			case 5:for(i=0; i<N;i++){
				if(estoque[i]>maiores){
					maiores = estoque[i];
					pmaiores = produto[i];
				}
			}
				printf("O produto com mais eh %c com estoque de %i.\n", pmaiores, maiores);
				break;
			
			case 6:for(i=0; i<N;i++){
				if(estoque[i]<menores){
					menores = estoque[i];
					pmenores = produto[i];
				}
			}
				printf("O produto com menos eh %c com estoque de %i.\n", pmenores, menores);
				break;	
			
			case 7:vt = (estoque[0]*preco[0])+(estoque[1]*preco[1])+(estoque[2]*preco[2])+(estoque[3]*preco[3])+(estoque[4]*preco[4]);
				printf("O valor total do estoque eh: %f\n", vt);
				break;
				
			case 8:printf("Saindo... \n");
				
		}
	
	}while(menu != 8);
	return 0;
}