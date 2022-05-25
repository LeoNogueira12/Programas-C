#include <stdio.h>
#include <stdlib.h>

int menu,n,i,tentativa,x,jogadas, acertos=0, erros=0;

int main(){
	do{
		printf("\nBem vindo ao jogo! \n\nEscolha uma opcao: 1 - Iniciar, 2 - Tutorial, 3 - Sair do jogo... \n");
		scanf("%d", &menu);
		switch(menu){
			case 1: printf("Informe o limite do intervalo. \n");
				scanf("%d", &n);
					if(n <= 1){
					printf("Tente um numero maior que 1 da proxima vez... \n");
				}else{
					printf("Informe o numero de rodadas \n");
					scanf("%d", &jogadas);
					for(i=0;i<jogadas;i++){				
						x = 1 + rand() % n;
						printf("Tente adivinhar o numero que estou pensando... \n");
						scanf("%d", &tentativa);
							if(tentativa<1||tentativa>n){
								printf("Perdeu a vez !!! Na proxima escolha um numero dentro do intervalo dito anteriormente!!! \n");
								erros++;
							}else{
								if(tentativa == x){       
									printf("Parabens voce acertou o numero! \n\n");
									acertos++;
								}else{
									printf("Voce errou o numero... \n\n");
									erros++;
							}
						}
					}
				}
					printf("O jogo acabou! \nVoce acertou %d vezes e errou %d vez(es) em todas as suas rodadas ate aqui.\n", acertos, erros);
					if(acertos>erros){
						printf("Parabens voce esta ganhando o jogo! \n");
					}
					if(acertos<erros){
						printf("Voce esta perdendo o jogo... \n");
					}
					if(acertos == erros){
						printf("Estamos empatados! \n");
					}
					break;
				case 2: printf("O jogo consiste na advinhacao de numeros, voce vai me dizer o intervalo numerico que quer advinhar (que comeca em 1) e a quantidade de rodadas quer jogar (em cada rodada penso em um numero diferente), apos isso comecaremos o jogo! \n");
					break;
				case 3: printf("Saindo... \n");
		}                                                                                                                                                                          
	}while(menu != 3);
		
	return 0;
}
