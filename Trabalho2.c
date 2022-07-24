#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIR 	11
#define QTD_STR 60
#define INICIO  1
#define FIM		2

typedef char string[QTD_STR];

typedef struct Funcionario{

    int idade;
    string nome;
    string cidade;
    float salario;
	struct Funcionario *prox;
	
}dados_t;

int menu();
dados_t *cadastroFuncionario();
void colocaLista(dados_t **lista,dados_t *novo,int local_insercao);
void alteraDados(dados_t **lista,string nome);
dados_t *deletaDados(dados_t **lista, dados_t* funcionario);
void mostraLista(dados_t *lista);
dados_t *localizaNome(string nome, dados_t *lista);
int comparacaoSalario(dados_t *lista,int comparacao);
void listaSalario(dados_t *lista);
void dadosFuncionario(dados_t *funcionario);
void repeticaoCidade(dados_t *lista);
void exportaTxt(dados_t *lista);
void importaTxt(dados_t *lista);
void removeEnter(string s);

int main(){
    int opcao_menu,num_compara;
    dados_t *lista = NULL,*aux_busca = NULL,*aux_altera = NULL,*aux_deleta = NULL,*f_removido = NULL;
    string nome_busca,nome_altera,nome_deleta;
    
    do{
        opcao_menu = menu();
        switch(opcao_menu){
			case 1: 
				colocaLista(&lista,cadastroFuncionario(),INICIO);
				printf("Funcionario cadastrado!\n");
				break;
				
			case 2:
				printf("Qual funcionario deseja alterar? ");
				getchar();
				fgets(nome_altera,QTD_STR,stdin);
				alteraDados(&lista,nome_altera);
				printf("Dados alterados!\n");
				break;
				
			case 3:
				printf("Qual funcionario deseja deletar? ");
            	getchar();
				fgets(nome_deleta,QTD_STR,stdin);
				aux_deleta = localizaNome(nome_deleta,lista);
				f_removido = deletaDados(&lista,aux_deleta);
				if(f_removido){
					printf("Funcionario %s removido!\n",f_removido->nome);
					free (f_removido);
				}
				break;		
					
			case 4:
				mostraLista(lista);
				break;
				
			case 5:
				getchar();
                printf("Qual nome deseja buscar? : ");
                fgets(nome_busca,QTD_STR,stdin);
                aux_busca = localizaNome(nome_busca,lista);
                if(aux_busca != NULL){
                	dadosFuncionario(aux_busca);
                }else{
               		printf("Pessoa nao encontrada!\n");
            	}
                    break;
				break;
				
			case 6:
				printf("Com qual numero quer saber quantos funcionarios tem o salario maior? ");
				scanf("%d",&num_compara);
				printf("A quantidade de funcionarios com o salario maior que %d eh: %d.\n",num_compara,comparacaoSalario(lista,num_compara));
				break;
				
			case 7:
				listaSalario(lista);
				break;
				
			case 8:
				break;
			
			case 9: 
				exportaTxt(lista);
				printf("Dados Exportados!\n");
				break;
				
			case 10:
				importaTxt(lista);
				printf("Dados importados!\n");
				break;
				
            case SAIR: //Sair
				printf("Saindo...");
				free(lista);
                break;
        }
    }while(opcao_menu!=SAIR);

 return 0;
}

int menu(){
    int opcao;
    printf("\nBem vindo!\nQual operacao deseja reaizar?\n");
    printf("1 - Cadastrar um funcionario.\n");
    printf("2 - Atualizar dados de um funcionario.\n");
    printf("3 - Deletar um funcionario.\n");
    printf("4 - Relatorio de todos os funcionarios.\n");
    printf("5 - Consulta de funcionario por nome.\n");
    printf("6 - Numero de funcionarios com salario maior ou igual a um certo numero.\n");
    printf("7 - Numero de funcionarios que ganham 1 salário minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos.\n");
    printf("8 - Numero de funcionarios por cidade.\n");
    printf("9 - Exportar para arquivo txt.\n");
    printf("10- Importar dados de arquivo txt,\n");
    printf("%d - Sair.\n", SAIR);
    printf("Opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return opcao;
}

dados_t *cadastroFuncionario(){
	dados_t *novo = NULL;
	
	novo = (dados_t*)malloc(sizeof(dados_t));
	
	printf("Nome do funcionario: ");
	getchar();
	fgets(novo->nome,QTD_STR,stdin);
	printf("Idade do funcionario: ");
	scanf("%d", &novo->idade);
	printf("Salario do funcionario: ");
	scanf("%f", &novo->salario);
	printf("Cidade do funcionario: ");
	getchar();
	fgets(novo->cidade,QTD_STR,stdin);
	novo->prox = NULL;
	
	return novo;
}

void colocaLista(dados_t **lista,dados_t *novo,int local_insercao){
	dados_t *aux = NULL;
	
	if(*lista){
		switch(local_insercao){
			case INICIO:
				aux = *lista;
				*lista = novo;
				novo->prox = aux;
				break;
			case FIM:
				aux = *lista;
				while(aux->prox != NULL){
					aux = aux->prox;
				}
				aux->prox = novo;
				break;
		}
	}else{
		*lista = novo;
	}
}

void alteraDados(dados_t **lista,string nome){
	dados_t *aux = *lista;
	
	if(*lista){
		while(aux != NULL){
			if(strcmp(aux->nome,nome)==0){
				printf("Nome do funcionario: ");
				fgets(aux->nome,QTD_STR,stdin);
				printf("Idade do funcionario: ");
				scanf("%d", &aux->idade);
				printf("Salario do funcionario: ");
				scanf("%f", &aux->salario);
				printf("Cidade do funcionario: ");
				getchar();
				fgets(aux->cidade,QTD_STR,stdin);
				return;
			}else{
				aux = aux->prox;
			}
		}
	}
	
}

dados_t *deletaDados(dados_t **lista, dados_t* funcionario){
	dados_t *aux, *remove = NULL;
	if(*lista){
		if((*lista)== funcionario){
			remove = *lista;
			*lista = remove->prox;
		}else{
			aux = *lista;
			while(aux->prox != funcionario){
				aux = aux->prox;
			}
			if(aux->prox){
				remove = aux->prox;
				aux->prox = remove->prox;
			}
		}
	}
	return remove;
}

void mostraLista(dados_t *lista){
	dados_t *aux = NULL;
	aux = lista;
	while(aux!= NULL){
		printf("**************************************************************\n");
		printf("Nome do funcionario...:%s", aux->nome);
		printf("Idade do funcionario..:%d\n",aux->idade);
		printf("Salario do funcionario:%2.f\n",aux->salario);
		printf("Cidade do funcionario.:%s\n",aux->cidade);
		printf("**************************************************************\n");
		aux = aux->prox;
	}
}

dados_t *localizaNome(string nome, dados_t *lista){
    dados_t *aux = lista;

    while(aux!=NULL){
        if(strcmp(nome, aux->nome)==0){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

int comparacaoSalario(dados_t *lista,int comparacao){
	dados_t *aux = lista;
	int quantidade = 0;
	while(aux != NULL){
		if(aux->salario > comparacao){
			quantidade++;
		}
		aux = aux->prox;
	}
	return quantidade;
}

void listaSalario(dados_t *lista){
	dados_t *aux = lista;
	int salario_min = 1212, quantidade1=0,quantidade2=0,quantidade3=0;

	while(aux!=NULL){
		if(aux->salario < salario_min || aux->salario == salario_min){
			quantidade1++;
		}
		if(aux->salario > salario_min && aux->salario < (3*salario_min)){
			quantidade2++;
		}
		if(aux->salario > (3*salario_min)){
			quantidade3++;
		}
		aux = aux->prox;
	}
	printf("Quantidade de funcionarios que ganham um salario minimo ou menos: %d\n",quantidade1);
	printf("Quantidade de funcionarios que ganham mais de um salario minimo e menos de tres salarios minimos: %d\n",quantidade2);
	printf("Quantidade de funcionarios que ganham mais de tres salarios minimos: %d",quantidade3);
}

void dadosFuncionario(dados_t *funcionario){
	dados_t *aux = funcionario;
	
	printf("**************************************************************\n");
	printf("Nome do funcionario...:%s", aux->nome);
	printf("Idade do funcionario..:%d\n",aux->idade);
	printf("Salario do funcionario:%2.f\n",aux->salario);
	printf("Cidade do funcionario.:%s\n",aux->cidade);
	printf("**************************************************************\n");
	aux = aux->prox;
}

void repeticaoCidade(dados_t *lista){
	dados_t *aux = lista, *aux2 = lista;

	while(aux != NULL){
		
	}
}

void exportaTxt(dados_t *lista){
	dados_t *aux =lista;
	string nome;
	FILE* arquivo;

	getchar();
	printf("Nome do arquivo para exportacao: ");
	fgets(nome,QTD_STR, stdin);
	
	arquivo = fopen(nome, "w+");
	
	while(aux!=NULL){
		fprintf(arquivo,"**************************************************************\n");
		fprintf(arquivo,"Nome do funcionario...:%s", aux->nome);
		fprintf(arquivo,"Idade do funcionario..:%d\n",aux->idade);
		fprintf(arquivo,"Salario do funcionario:%2.f\n",aux->salario);
		fprintf(arquivo,"Cidade do funcionario.:%s\n",aux->cidade);
		fprintf(arquivo,"**************************************************************\n");
		aux = aux->prox;
	}
	fclose(arquivo);
}

void importaTxt(dados_t *lista){
	dados_t *aux = lista;
	FILE *arquivo;
	string nome;
	int i=0;
	
	getchar();
	printf("Nome do arquivo para importcao: ");
	fgets(nome,QTD_STR, stdin);
	
	arquivo = fopen(nome, "r");
	
	while (!feof(arquivo)) {
		fscanf(arquivo, "%s\n", &aux[i].nome);
		fscanf(arquivo, "%s\n", &aux[i].cidade);
		fscanf(arquivo, "%d\n", &aux[i].idade);
		fscanf(arquivo, "%f\n\n", &aux[i].salario);
		aux->prox = NULL;
		i++;
	}

	fclose(arquivo);
}

void removeEnter(string s){
	int tamanho;
	tamanho = strlen(s);
	s[tamanho-1] = '\0';
}
