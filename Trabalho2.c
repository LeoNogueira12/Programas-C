#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIR 	11
#define QTD_STR 60
#define INICIO  1
#define FIM		2

int quantidade_lista=0;

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
void funcionariosCidade(dados_t *lista);
int repeticaoCidade(char *f1,char *f2, int k);
void exportaTxt(dados_t *lista);
void importaTxt(dados_t **lista);
void removeEnter(string s);
void importaBinario(dados_t **lista);
void exportaBinario(dados_t *lista);

int main(){
    string nome_busca,nome_altera,nome_deleta;
    dados_t *lista = NULL,*aux_deleta=NULL,*f_removido=NULL,*aux_busca=NULL;
    int opcao_menu,num_compara;
    char resposta,resposta2;
    printf("Ola, gostaria de importar os dados do arquivo binario: dados_funcionarios.bin? (y/n): ");
    scanf("%c", &resposta);
    if(resposta == 'y'){
    	importaBinario(&lista);
    	printf("Conteudo importado!\n");
	}else{
		if(resposta == 'n'){
			getchar();
			printf("\nPressione enter para continuar....");
			getchar();
			system("cls");
		}
	}
	
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
				funcionariosCidade(lista);
				break;
			
			case 9: 
				exportaTxt(lista);
				printf("Dados Exportados!\n");
				break;
				
			case 10:	      
				importaTxt(&lista);
				printf("Dados importados!\n");
				break;
				
            case SAIR: //Sair
            	printf("Deseja exportar os arquivos para bin? (y/n): ");
            	getchar();
            	scanf("%c", &resposta2);
            	if(resposta2 == 'y'){
            		exportaBinario(lista);
            		printf("Conteudo exportado para o arquivo bin!\n");
				}
            	if(resposta2 == 'n'){
            		getchar();
            		printf("\nPressione ENTER para sair.......\n");
            		getchar();
            		system("cls");
				}
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
    printf("7 - Numero de funcionarios que ganham 1 salario minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos.\n");
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
	quantidade_lista++;
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
		printf("Cidade do funcionario.:%s",aux->cidade);
		printf("**************************************************************\n");
		aux = aux->prox;
	}
	if(lista == NULL){
		printf("Nao existem funcionarios na lista!\n");
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


void funcionariosCidade(dados_t *lista){
	dados_t *aux = lista;	
	string cidade[100];
	int i = 0,j,count =0;
	
	if(lista){
		do{
		
			strcpy(cidade[i],aux->cidade);
			aux = aux->prox;
			i++;
		
		}while(aux!=NULL && i<quantidade_lista);
		
		for(i=0;i<quantidade_lista;i++){
			for(j=0;j<quantidade_lista;j++){
				if(strcmp(cidade[i],cidade[j])==0){
					count++;
				}
			}
			if(cidade[i]){
				removeEnter(cidade[i]);
				printf("Quantidade de funcionarios na cidade %s : %d\n",cidade[i],count);
			}
			count = 0;
		}
		
	}else{
		printf("Nao existem funcionarios na lista!\n");
	}
}

void exportaTxt(dados_t *lista){
	dados_t *aux =lista;
	FILE* arquivo;
	
	arquivo = fopen("dados_funcionarios.txt", "w+");
	
	while(aux!=NULL){
		fprintf(arquivo,"%s",aux->nome);
		fprintf(arquivo,"%d\n",aux->idade);
		fprintf(arquivo,"%.2f\n",aux->salario);
		fprintf(arquivo,"%s\n\n",aux->cidade);
		aux = aux->prox;
	}
	fclose(arquivo);
}

void importaTxt(dados_t **lista){
	dados_t *aux;
	FILE *arquivo;
	string nome,cidade;
	int idade;
	float salario;
		
	arquivo = fopen("dados_funcionarios.txt", "r");
	
	while (!feof(arquivo)) {
		fscanf(arquivo, "%s", &nome);
		fscanf(arquivo, "%d\n", &idade);
		fscanf(arquivo, "%f\n", &salario);
		fscanf(arquivo, "%s\n\n", &cidade);
		if (!feof(arquivo)) {
		  	aux = (dados_t*)malloc(sizeof(dados_t));
		  	strcpy(aux->nome,nome);
		  	strcpy(aux->cidade,cidade);
		  	aux->idade = idade;
		  	aux->salario = salario;
		  	aux->prox = NULL;
		  	colocaLista(lista, aux, FIM);
	  	}
	}
	fclose(arquivo);
}	

void removeEnter(string s){
	int tamanho;
	tamanho = strlen(s);
	s[tamanho-1] = '\0';
}

void importaBinario(dados_t **lista){
	FILE *fp;
	dados_t *aux;
	string nome,cidade;
	int idade;
	float salario;
	
	fp = fopen("dados_funcionarios.bin", "rb");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}

  while (!feof(fp)) {
  	fread(&nome, sizeof(string), 1, fp);
  	fread(&idade, sizeof(int), 1, fp);
  	fread(&salario, sizeof(float), 1, fp);
  	fread(&cidade, sizeof(string), 1, fp);
  	if (!feof(fp)) {
	  	aux = (dados_t*)malloc(sizeof(dados_t));
	  	aux->idade = idade;
	  	strcpy(aux->nome,nome);
	  	strcpy(aux->cidade,cidade);
	  	aux->salario = salario;
	  	aux->prox = NULL;
	  	colocaLista(lista, aux,INICIO);
	  }
	}
	
	fclose(fp);
}

void exportaBinario(dados_t *lista){
	FILE *fp;
	dados_t *aux = lista;
	
	fp = fopen("dados_funcionarios.bin", "wb+");
	
	if (fp == NULL) {
		printf("Erro ao tentar abrir arquivo <dados.bin>");
		exit(0);
	}
	
	while (aux != NULL) {
		fwrite(&aux->nome, sizeof(string), 1, fp);
		fwrite(&aux->idade, sizeof(int), 1, fp);
		fwrite(&aux->salario, sizeof(float), 1, fp);
		fwrite(&aux->cidade, sizeof(string), 1, fp);
		aux = aux->prox;
	}
	
	fclose(fp);
}
