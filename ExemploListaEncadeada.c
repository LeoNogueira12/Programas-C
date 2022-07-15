//Controle de times
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 60
#define INICIO   1
#define FIM      2
#define SAIR     6

typedef char string[STR_SIZE];

typedef struct Times{
    string nome;
    int id;
    struct Times *prox;
}dados_t;

int menu();
void mostraLista(dados_t *lista);
dados_t *criaRegistro();
void insereLista(dados_t **lista, dados_t *novo_registro,int posicao);
void removeEnter(string s);

int main(){
    dados_t *lista = NULL;
    int opcao;
    do{
        opcao = menu();
        switch(opcao){
            case 1:
                insereLista(&lista,criaRegistro(),INICIO);
                break;
            case 2:
                mostraLista(lista);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case SAIR:
                printf("Saindo...");
                free(lista);
                break;
        }
    }while(opcao != SAIR);

    return 0;
}

int menu(){
    int opcao;

    printf("1.Insere registro\n");
    printf("2.Mostra registros.\n");
    printf("3.Localiza por nome.\n");
    printf("4.Exporta para txt.\n");
    printf("5.Importar dados de arquivo txt.\n");
    printf("%d.Sair.\n",SAIR);
    printf("Opcao: ");
    scanf("%d",&opcao);

    return opcao;
}

void mostraLista(dados_t *lista){
    dados_t *aux = lista;
    while(aux!=NULL){
        printf("************************************\n");
        printf("Nome :%s\n",aux->nome);
        printf("ID   :%d\n", aux->id);
        printf("Endereco do prox     :%p\n",aux->prox);
        printf("Endereco de registro :%p\n",aux);
        printf("************************************\n");
        aux = aux->prox;

    }
}

dados_t *criaRegistro(){
    dados_t *novo = NULL;
    //Alocação
    novo = (dados_t*)malloc(sizeof(dados_t));

    printf("Nome: ");
    getchar();
    fgets(novo->nome,STR_SIZE,stdin);
    //TODA STRING JÁ VEM POR REFERÊNCAI, POR ISSO NÃO PRECISA DE &
    removeEnter(novo->nome);
    printf("ID: ");
    scanf("%d", &novo->id);
    novo->prox = NULL;

    return novo;
}

void insereLista(dados_t **lista,dados_t *novo_registro,int posicao){
    dados_t *aux = NULL;

    if(*lista){
        switch(posicao){
            case INICIO:
                aux = *lista;
                *lista = novo_registro;
                novo_registro->prox = aux;
                break;
            case FIM:
                //Procura o último
                aux = *lista;
                while(aux->prox != NULL){
                    aux = aux->prox;
                }
                aux->prox = novo_registro;

                break;
        }
    }else{
        *lista = novo_registro;
    }
}

void removeEnter(string s){
    int tamanho;
    tamanho = strlen(s);
    s[tamanho-1] = '\0';
}
