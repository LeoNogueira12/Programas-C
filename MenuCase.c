#include <stdio.h>

int contpar,opcao, par, impar, i;

int main()
{
	do {	
		printf("1) Imprimir pares de 1 ate 100\n");
		printf("2) Imprimir impares de 1 ate 100\n");
		printf("3) Contar pares de 1 ate 100\n");
		printf("4) Contar impares de 1 ate 100\n");
		printf("5) Imprimir os primos de 1 ate 100\n");
		printf("6) Sair do programa\n");
		printf("Qual a sua opcao? ");
		scanf("%i", &opcao);
		
		// Tratar opções do menu
		switch (opcao) {
			case 1: for (par = 1; par <= 100; par++) {
						if ((par % 2) == 0) {
							printf("O valor %i eh par\n", par);
						}
					}
					break;

			case 2: for (impar = 1; impar <= 100; impar++) {
				        if ((impar % 2) != 0) {
						    printf("o valor %i eh impa\n", impar); 
						}  
				}
				break;

			case 3: contpar=0;
					for (par = 1; par <= 100; par++) {
						if ((par % 2) == 0) {
							contpar++;		
						}
						
					}
					printf("A quantidade de numeros pares e:%d\n", contpar );
			
					break;

			case 4: contpar=0;
					for (par = 1; par <= 100; par++) {
						if ((par % 2) != 0) {
							contpar++;		
						}
						
					}
					printf("A quantidade de numeros impares e:%d\n", contpar );
			 
			
			break;
			
			case 5: for(i=2;i<=100;i++){
						if(i==2 || i==3 || i==5||i==7||i==9)
							printf("%d eh um numero primo.\n", i);
						else
							if( i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i%9!=0)
								printf("%d eh um numero primo\n", i);}
			break;
			case 6: printf("Saindo...");
			break;
		}
		
	} while (opcao != 6);
	
	return 0;
}
