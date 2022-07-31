#include <stdio.h> //Inserção de bibliotecas.
#include <stdlib.h>
#include <string.h>

#define SAIR 	11 //Definição da opção sair do menu, feito para facilitar na confecção do código.
#define QTD_STR 60 //Definição usada para padronizar o tamanho das strings e facilitar na mudança no código inteiro.
#define INICIO   1 //Definição para alterar o modo de inserção na lista encadeada, sendo no início ou fim.
#define FIM		 2

int quantidade_lista=0; //Variável global pra identificar quantos funcionários existem na lista, sua quantidade aumenta na função de cadastro.

typedef char string[QTD_STR]; //Cria o tipo string com a quantidade padrão.

typedef struct Funcionario{ //struct para armazenar os dados dos funcionários.

    int idade;
    string nome;
    string cidade;
    float salario;
	struct Funcionario *prox;
	
}dados_t; //Cria o tipo dados_t proveniente da struct Funcionarios.

int menu(); //Menu do programa
dados_t *cadastroFuncionario(); //Inserção de dados para um funcionário
void colocaLista(dados_t **lista,dados_t *novo,int local_insercao); //Coloca os dados inseridos na função anterior na lista encadeada
void alteraDados(dados_t **lista,string nome); //Altera os dados de um funcionário na lista
dados_t *deletaDados(dados_t **lista, dados_t* funcionario); //Deleta um funcionário da lista
void mostraLista(dados_t *lista); //Mostra os dados de todos os funcionarios
dados_t *localizaNome(string nome, dados_t *lista); //Localiza um funcionário específico na lista 
int comparacaoSalario(dados_t *lista,int comparacao); //Compara o salário de um funcionário com um número dado pelo usuário
void listaSalario(dados_t *lista); //Lista de funcionarios que ganham 1 salário mínimo ou menos, mais de 1 salário mínimo a 3 salários mínimos e mais que 3 salários mínimos 
void dadosFuncionario(dados_t *funcionario); //Mostra os dados de apenas um funcionario
void funcionariosCidade(dados_t *lista); //Numero de funcionarios em uma cidade
void exportaTxt(dados_t *lista); //Exporta os dados da lista para um arquivo txt
void importaTxt(dados_t **lista); //Importa os dados de um arquivo txt 
void removeEnter(string s); //Remove o Enter de strings provenientes do fgets
void importaBinario(dados_t **lista); //Importa dados de um arquivo binário
void exportaBinario(dados_t *lista); //Exporta os dados da lista para um arquivo binário

int main(){
    string nome_busca,nome_altera,nome_deleta;
    dados_t *lista = NULL,*aux_deleta=NULL,*f_removido=NULL,*aux_busca=NULL;
    int opcao_menu,num_compara;
    
    //Pergunta para o usuário se ele quero ou não ler os dados de um arquivo binário
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
	
	//loop para o funcionamento contínuo do menu até o usuário escolher a opção de sair.
    do{
        opcao_menu = menu();
        switch(opcao_menu){ //Faz o acionamento de funções de acordo com a escolha do usuário no menu
			case 1: 
				colocaLista(&lista,cadastroFuncionario(),INICIO); //Cadastra um funcionário e o coloca na lista
				printf("Funcionario cadastrado!\n");
				break;
				
			case 2:
				printf("Qual funcionario deseja alterar? "); //altera os dados de um funcionário
				getchar();
				fgets(nome_altera,QTD_STR,stdin);
				removeEnter(nome_altera);
				alteraDados(&lista,nome_altera);
				printf("Dados alterados!\n");
				break;
				
			case 3:
				printf("Qual funcionario deseja deletar? "); //deleta os dados de um funcionário
            	getchar();
				fgets(nome_deleta,QTD_STR,stdin);
				removeEnter(nome_deleta);
				aux_deleta = localizaNome(nome_deleta,lista); //localiza o funcionário
				f_removido = deletaDados(&lista,aux_deleta); //remove os dados do funcionário
				if(f_removido){ //se a função não retornar NULL
					printf("Funcionario %s removido!\n",f_removido->nome);
					quantidade_lista = quantidade_lista -1; //remove um funcionário da contagem da lista
					free (f_removido); //libera o espaço da memória do funcionário
				}else{
					printf("Funcionario nao encontrado!\n");
				}
				break;		
					
			case 4:
				mostraLista(lista); //Mostra todos os dados de um funcionário
				break;
				
			case 5:
				getchar();
                printf("Qual nome deseja buscar? : ");
                fgets(nome_busca,QTD_STR,stdin);
                removeEnter(nome_busca);
                aux_busca = localizaNome(nome_busca,lista); //localiza o funcionário
                if(aux_busca != NULL){//se a função não retornar NULL
                	dadosFuncionario(aux_busca);
                }else{
               		printf("Pessoa nao encontrada!\n");
            	}
                    break;
				break;
				
			case 6:
				printf("Com qual numero quer saber quantos funcionarios tem o salario maior? "); 
				scanf("%d",&num_compara);
				printf("A quantidade de funcionarios com o salario maior que %d eh: %d.\n",num_compara,comparacaoSalario(lista,num_compara)); //retorna o número de funcionários com salário maior que num_compara dado pelo usuário
				break;
				
			case 7:
				listaSalario(lista); //mostra a lista de funcionarios que ganham 1 salário mínimo ou menos, mais de 1 salário mínimo a 3 salários mínimos e mais que 3 salários mínimos 
				break;
				
			case 8:
				funcionariosCidade(lista); //Mostra quantos funcionários tem em cada cidade
				break;
			
			case 9: 
				exportaTxt(lista); //Exporta os dados para o arquivo txt
				printf("Dados Exportados!\n");
				break;
				
			case 10:	      
				importaTxt(&lista); //Importa os dados para o arquivo txt
				printf("Dados importados!\n");
				break;
				
            case SAIR: //Sair
            //Pergunta para o usuário se ele deseja exportar os dados para o arquivo binário
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
				free(lista); //Libera o espaço da memória da lista
                break;
        }
    }while(opcao_menu!=SAIR);
 return 0;
}

int menu(){
	//Menu de interação com o usuário
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
    printf("10- Importar dados de arquivo txt.\n");
    printf("%d - Sair.\n", SAIR);
    printf("Opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return opcao; //retorna a opcao do usuário para ser manipulada no main
}

dados_t *cadastroFuncionario(){
	//cadastra os dados de um funcionário
	
	dados_t *novo = NULL;
	
	novo = (dados_t*)malloc(sizeof(dados_t)); //Aloca os dados dinâmicamente
	
	printf("Nome do funcionario: ");
	getchar();
	fgets(novo->nome,QTD_STR,stdin);
	removeEnter(novo->nome);
	printf("Idade do funcionario: ");
	scanf("%d", &novo->idade);
	printf("Salario do funcionario: ");
	scanf("%f", &novo->salario);
	printf("Cidade do funcionario: ");
	getchar();
	fgets(novo->cidade,QTD_STR,stdin);
	removeEnter(novo->cidade);
	novo->prox = NULL;
	
	return novo; //retorna os dados do funcionário para ser manipulado 
}

void colocaLista(dados_t **lista,dados_t *novo,int local_insercao){
	//Coloca os dados anteriormente cadastrados na lista
	dados_t *aux = NULL;
	
	if(*lista){ //Se a lista não estiver vazia
		switch(local_insercao){
			case INICIO:
				aux = *lista; //O aux aponta para o mesmo que a lista
				*lista = novo; //A lista aponta para o novo funcionário 
				novo->prox = aux; //O novo funcionário aponta para o antigo começo
				break;
			case FIM:
				aux = *lista; //Aux aponta para o mesmo que a lista
				while(aux->prox != NULL){ //Encontra o último elemento da lista
					aux = aux->prox;
				}
				aux->prox = novo; //O último aponta para o novo funcionário
				break;
		}
	}else{ //Se estiver vazia
		*lista = novo; //A lista aponta para o novo funcionário
	}
	quantidade_lista++; //Acrescenta a quantidade de funcionários na lista em 1
}

void alteraDados(dados_t **lista,string nome){
	//Altera os dados de um funcionário 
	dados_t *aux = *lista;
	
	if(*lista){ //Se a lista não estiver vazia
		while(aux != NULL){ //laço para achar o funcionário desejado
			if(strcmp(aux->nome,nome)==0){ //muda os dados do funcionario
				printf("Nome do funcionario: ");
				fgets(aux->nome,QTD_STR,stdin);
				removeEnter(aux->nome);
				printf("Idade do funcionario: ");
				scanf("%d", &aux->idade);
				printf("Salario do funcionario: ");
				scanf("%f", &aux->salario);
				printf("Cidade do funcionario: ");
				getchar();
				fgets(aux->cidade,QTD_STR,stdin);
				removeEnter(aux->cidade);
				return; //Após mudar os dados, retorna para o main
			}else{
				aux = aux->prox; //Passa para o próximo na lista para achar o desejado
			}
		}
	}else{
		printf("Nenhum funcionario cadastrado!\n"); //Se a lista estiver vazia
	}
	
}

dados_t *deletaDados(dados_t **lista, dados_t* funcionario){
	//Deleta os dados de um funcionário
	dados_t *aux, *remove = NULL;

	if(*lista){ //se a lista não estiver vazia
		if((*lista)== funcionario){ //se ela aponta para o desejado
			remove = *lista; //remove aponta para o mesmo que lista
			*lista = remove->prox; //lista aponta para o próximo que ela apontava antes
		}else{ //se a lista não aponta para o início
			aux = *lista; //aux aponta para o mesmo que a lista
			while(aux->prox != funcionario){ //encontra o funcionário da lista antes do desejado
				aux = aux->prox;
			}
			if(aux->prox){ //Se o próximimo do auxiliar não for NULL
				remove = aux->prox; //remove aponta para o próximo do auxiliar
				aux->prox = remove->prox; //o próximo do auxiliar vai apontar para o próximo do remove
			}
		}
	}
	return remove; //retorna o remove para ser manipulado 
}

void mostraLista(dados_t *lista){
	//Mostra os dados de todos os funcionários da lista
	dados_t *aux = NULL;
	aux = lista;
	
	while(aux!= NULL){ //Enquanto o aux ainda for um funcionário válido 
		printf("**************************************************************\n"); //mostra os dados
		printf("Nome do funcionario...:%s\n", aux->nome);
		printf("Idade do funcionario..:%d\n",aux->idade);
		printf("Salario do funcionario:%2.f\n",aux->salario);
		printf("Cidade do funcionario.:%s\n",aux->cidade);
		printf("**************************************************************\n");
		aux = aux->prox; //passa para o próximo da lista
	}
	if(lista == NULL){ //Se a lista estiver vazia
		printf("Nao existem funcionarios na lista!\n");
	}
}

dados_t *localizaNome(string nome, dados_t *lista){
	//Localiza um funcionário na lista pelo nome
    dados_t *aux = lista;

    while(aux!=NULL){ //Laço para percorrer toda a lista
        if(strcmp(nome, aux->nome)==0){ //Se achar o desejado
            return aux; //retorna os dados do funcionário para ser manipulado
        }
        aux = aux->prox; //passa para o próximo da lista
    }
    return NULL; //retorna NULL já que não achou o funcionário
}

int comparacaoSalario(dados_t *lista,int comparacao){
	//compara o salário dos funcionários cadastrados com um número específico
	dados_t *aux = lista;
	int quantidade = 0;
	
	while(aux != NULL){ //Laço para percorrer a lista
		if(aux->salario > comparacao){
			quantidade++; //conta os funcionários 
		}
		aux = aux->prox; //passa para o próximo da lista
	}
	return quantidade; //retorna a quantidade de funcionários com o salário maior que o número indicado
}

void listaSalario(dados_t *lista){
	//mostra a lista de funcionarios que ganham 1 salário mínimo ou menos, mais de 1 salário mínimo a 3 salários mínimos e mais que 3 salários mínimos 
	dados_t *aux = lista;
	int salario_min = 1212, quantidade1=0,quantidade2=0,quantidade3=0;

	while(aux!=NULL){ //laço para percorrer a lista
		if(aux->salario < salario_min || aux->salario == salario_min){ //se ganha um salário mínimo ou menos
			quantidade1++; //aumenta em 1 a quantidade da opção
		}
		if(aux->salario > salario_min && aux->salario < (3*salario_min)){ //se ganha mais de um salário mínimo e menos de 3 salários mínimos
			quantidade2++; //aumenta em 1 a quantidade da opção
		}
		if(aux->salario > (3*salario_min)){ //se ganha mais de 3 salários mínimos
			quantidade3++; //aumenta em 1 a quantidade da opção
		}
		aux = aux->prox;
	}
	printf("Quantidade de funcionarios que ganham um salario minimo ou menos: %d\n",quantidade1); //mostra a quantidade de funcionários da 1 opção
	printf("Quantidade de funcionarios que ganham mais de um salario minimo e menos de tres salarios minimos: %d\n",quantidade2); //mostra a quantidade de funcionários da 2 opção
	printf("Quantidade de funcionarios que ganham mais de tres salarios minimos: %d",quantidade3); //mostra o número de funcionários da 2 opção
}

void dadosFuncionario(dados_t *funcionario){
	//mostra os dados de um funcionário específico
	dados_t *aux = funcionario;
	
	printf("**************************************************************\n");
	printf("Nome do funcionario...:%s\n", aux->nome);
	printf("Idade do funcionario..:%d\n",aux->idade);
	printf("Salario do funcionario:%2.f\n",aux->salario);
	printf("Cidade do funcionario.:%s\n",aux->cidade);
	printf("**************************************************************\n");
	
}

void funcionariosCidade(dados_t *lista){
	//mostra a lista de funcionários em cada cidade
	dados_t *aux = lista;	
	string cidade[100];
	int i = 0,j,count =0;
	
	if(lista){ //se a lista não estiver vazia
		do{ //laço para mandar transcrevem as cidades de cada funcionário em um vetor de strings
		
			strcpy(cidade[i],aux->cidade);
			aux = aux->prox;
			i++;
		
		}while(aux!=NULL && i<quantidade_lista); //percorre toda a lista e adiciona à string 
		
		for(i=0;i<quantidade_lista;i++){ //laço para percorrer o vetor de strings e comparar com outro funcionário
			for(j=0;j<quantidade_lista;j++){
				if(strcmp(cidade[i],cidade[j])==0){ //se as cidades forem iguais
					count++; //aumenta a variável em 1
				}
			}
			if(cidade[i]){ //se a string não for nula
				printf("Quantidade de funcionarios na cidade %s : %d\n",cidade[i],count);
			}
			count = 0; //volta a contagem = 0 para fazer o mesmo laço com o próximo funcionário
		}
		
	}else{ //se a lista estiver vazia
		printf("Nao existem funcionarios na lista!\n");
	}
}

void exportaTxt(dados_t *lista){
	//exporta os dados para um arquivo txt
	dados_t *aux =lista,*aux2;
	FILE* arquivo;
	
	arquivo = fopen("dados_funcionarios.txt", "a+"); //abre o arquivo no modo de escrever no final

	while(aux!=NULL){ //percorre a lista, colocando todos os dados de cada um na lista
		fprintf(arquivo,"%s\n",aux->nome);
		fprintf(arquivo,"%d\n",aux->idade);
		fprintf(arquivo,"%.2f\n",aux->salario);
		fprintf(arquivo,"%s\n\n",aux->cidade);
		aux = aux->prox;
	}
	
	//coloca um funcionário padrão na lista, feito para a correção de um problema de leitura do arquivo
	aux2->nome[0] = 'n';
	fprintf(arquivo,"%s\n",aux2->nome);
	aux2->idade = 0;
	fprintf(arquivo,"%d\n",aux2->idade);
	aux2->salario = 0;
	fprintf(arquivo,"%.2f\n",aux2->salario);
	aux2->cidade[0] = 'n';
	fprintf(arquivo,"%s\n\n",aux2->cidade);
	
	fclose(arquivo); //fecha o arquivo
}

void importaTxt(dados_t **lista){
	//importa os dados de um arquivo txt
	dados_t *aux;
	FILE *arquivo;
	string nome,cidade;
	int idade;
	float salario;
		
	arquivo = fopen("dados_funcionarios.txt", "r"); //abre o arquivo no modo de leitura
	
	while (!feof(arquivo)) { //enquanto não for o final arquivo, pega os dados armazenados no arquivo
		fscanf(arquivo, "%s\n", &nome);
		fscanf(arquivo, "%d\n", &idade);
		fscanf(arquivo, "%f\n", &salario);
		fscanf(arquivo, "%s\n\n", &cidade);
		if (!feof(arquivo)) {
		  	aux = (dados_t*)malloc(sizeof(dados_t)); //aloca dinâmicamente o funcionário do aquivo
		  	strcpy(aux->nome,nome);
		  	strcpy(aux->cidade,cidade);
		  	aux->idade = idade;
		  	aux->salario = salario;
		  	aux->prox = NULL;
		  	colocaLista(lista, aux, FIM); //coloca o funcionario na lista
	  	}
	}
	fclose(arquivo); //fecha o arquivo
}	

void removeEnter(string s){
	//retira o enter que sobra dos fgets's
	int tamanho;
	tamanho = strlen(s); //descobre o tamanho da string
	s[tamanho-1] = '\0'; //remove o último \0 que era desnecessário
}

void importaBinario(dados_t **lista){
	//Importa os dados de um arquivo binário
	FILE *fp;
	dados_t *aux;
	string nome,cidade;
	int idade;
	float salario;
	
	fp = fopen("dados_funcionarios.bin", "rb"); //Abre o arquivo no modo de leitura de binário
	
	if (fp == NULL) { //se o arquivo for nulo
		printf("Erro ao tentar abrir arquivo dados_funcionarios.bin");
		exit(0);
	}

  	while (!feof(fp)) { //laço para ler os dados do arquivo
	  	fread(&nome, sizeof(string), 1, fp);
	  	fread(&idade, sizeof(int), 1, fp);
	  	fread(&salario, sizeof(float), 1, fp);
	  	fread(&cidade, sizeof(string), 1, fp);
	  	if (!feof(fp)) {
		  	aux = (dados_t*)malloc(sizeof(dados_t)); //Aloca dinâmicamente os dados
		  	aux->idade = idade;
		  	strcpy(aux->nome,nome);
		  	strcpy(aux->cidade,cidade);
		  	aux->salario = salario;
		  	aux->prox = NULL;
		  	colocaLista(lista, aux,INICIO); //coloca os dados na lista
		  }
	}
	
	fclose(fp); //Fecha o arquivo
}

void exportaBinario(dados_t *lista){
	//Exporta os dados para um arquivo binário
	FILE *fp;
	dados_t *aux = lista;
	
	fp = fopen("dados_funcionarios.bin", "wb+"); //Abre o arquivo no modo de escrita binário e cria o arquivo se ele não existir
	
	if (fp == NULL) { //se o arquivo for nulo
		printf("Erro ao tentar abrir arquivo dados_funcionarios.bin");
		exit(0);
	}
	
	while (aux != NULL) { //percorre toda a lista, colocando os dados no arquivo
		fwrite(&aux->nome, sizeof(string), 1, fp);
		fwrite(&aux->idade, sizeof(int), 1, fp);
		fwrite(&aux->salario, sizeof(float), 1, fp);
		fwrite(&aux->cidade, sizeof(string), 1, fp);
		aux = aux->prox;
	}
	
	fclose(fp); //fecha o arquivo
}
