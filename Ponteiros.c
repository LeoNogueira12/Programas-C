// Declaração e manipulação de ponteiros
/*
int main()
{
	int a = 10;
	int* b = &a;

	*b = 11;
	printf("Valor da variavel a: %d\n", a);

	printf("Valor apontado por b (conteudo): %d\n", *b);

	printf("Endereco da variavel a: %p\n", &a);
	printf("Endereco apontado por b: %p\n", b);
	printf("Endereco do ponteiro b: %p", &b);

	return 0;
}
*/

// Parâmetros por valor e referência
/*
void le_dados(int *a, int *b);
void mostra_dados(int a, int b);
int soma_dados(int a, int b);

int main()
{
	int x = 0, y = 0;

	le_dados(&x, &y);
	mostra_dados(x, y);
	printf("A soma de a com b eh: %d\n", soma_dados(x, y));

	return 0;
}

void le_dados(int *a, int *b)
{
	printf("Informe um valor para a: ");
	scanf("%d", a);
	printf("Informe um valor para b: ");
	scanf("%d", b);
}

void mostra_dados(int a, int b)
{
	printf("O valor de a eh: %d\n", a);
	printf("O valor de b eh: %d\n", b);
}

int soma_dados(int a, int b)
{
	return a + b;
}
*/

// Vetor e matriz por referencia
/*
void mostra_vetor(int *v);

int main()
{
	int vetor[5] = {1, 2, 3, 4, 5};

	mostra_vetor(vetor);
	mostra_vetor(vetor);

}

void mostra_vetor(int *v)
{
	int i;
	for (i = 0; i < 5; i++) {
		printf("v[%d]: %d ", i, v[i]);
		v[i]++;
	}

}
*/

//Estrutura por referencia
/*
struct coordenadas {
	int a;
	int b;
	float custo;
};

typedef struct coordenadas coordenadas;

void ler_coordenada(coordenadas *c);
void mostrar_coordenada(coordenadas c);
int menu();

int main()
{
	coordenadas coord[5];
	int quantidade = 0, opcao, i;

	do {
		opcao = menu();

		switch (opcao) {
			case 1: ler_coordenada(&coord[quantidade]);
							quantidade++;
							break;

			case 2: for (i = 0; i < quantidade; i++)
								mostrar_coordenada(coord[i]);
							break;
		}

	} while (opcao != 3);

	return 0;
}

void ler_coordenada(coordenadas *c)
{
	printf("Valor de a? ");
	scanf("%d", &c->a);
	printf("Valor de b? ");
	scanf("%d", &c->b);
	printf("Valor de custo? ");
	scanf("%f", &c->custo);
}

void mostrar_coordenada(coordenadas c)
{
	printf("Valor de a: %d\n ", c.a);
	printf("Valor de b: %d\n ", c.b);
	printf("Valor de custo: %.2f\n\n ", c.custo);
}

int menu()
{
	int opcao;

	printf("1.Cadastrar coordenada\n");
	printf("2.Mostrar todas as coordenadas cadastradas\n");
	printf("3.Sair do programa\n");
	printf("Opcao: ");
	scanf("%d", &opcao);

	return opcao;
}
*/
