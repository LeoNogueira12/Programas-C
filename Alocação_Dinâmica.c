#include<stdio.h>
#include<stdlib.h>

//Alocação Dinâmica
/*
void ler_Vetor(int *v, int tamanho);
void mostra_Vetor(int *v, int tamanho);

int main(){
    int *ponteiro = NULL;
    int tamanho;

    printf("Defina o tamanho: ");
    scanf("%d", &tamanho);

    //Alocação dinâmica do vetor ponteiro
    ponteiro = (int*)malloc(tamanho * sizeof(int));

    ler_Vetor(ponteiro, tamanho);
    mostra_Vetor(ponteiro,tamanho);

    free(ponteiro);

    return 0;
}

void ler_Vetor(int *vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("Valor inteiro: ");
        scanf("%d", &vetor[i]);
    }
}
void mostra_Vetor(int *vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("Valor do vetor[%d]: %d\n",i, vetor[i]);
    }
}
*/


//sizeof
/*
int main(){
    printf("Tamanho em bytes de um char:  %d\n", sizeof(char));
    printf("Tamanho em bytes de um int:   %d\n", sizeof(int));
    printf("Tamanho em bytes de um float: %d\n", sizeof(float));
    printf("Tamanho em bytes de um long:  %d\n", sizeof(long));
    printf("Tamanho em byte de um double: %d\n", sizeof(double));

    return 0;
}
*/

//Cadastros
/*
Programa oara cadastrar produtos
*/

struct dados_produto{
    char descricao[20];
    unsigned int id;
    float preco;
    unsigned int qtd_estoque;
};

typedef struct dados_produto dados_produto;

dados_produto insere_produto();
int localiza_produto_descricao(char descricao[20], dados_produto *dados, int qtd);
dados_produto* localiza_produto_descricao1();
void mostra_todos_produtos(dados_produto *dados, int qtd);
float mostra_total_em_reais_estoque(dados_produto *dados, int qtd);
int menu();

int main(){
    //Base de dados
    dados_produto *dados = (dados_produto*)malloc(sizeof(dados_produto)*10);
    unsigned int qtd_produtos = 0;
    int opcao;
    char desc[20];

    do{
        opcao = menu();
        switch(opcao){
            case 1: dados[qtd_produtos] = insere_produto();
                qtd_produtos++;
                break;
            case 2: mostra_todos_produtos(dados, qtd_produtos);
                break;
            case 3:getchar();
                printf("Qual a descricao do produto? \n");
                fgets(desc, 10, stdin);
                if(localiza_produto_descricao(desc,dados,qtd_produtos)!= -1){
                    printf("Produto %s localizado\n", desc);
                }else{
                    printf("Produto nao localizado\n");
                }
                break;
            case 4:printf("O montante do estoque eh: %.2f\n", mostra_total_em_reais_estoque(dados, qtd_produtos));
                break;
            case 5://Libera Memoria
                free(dados);
                printf("Saindo...");
        }

    }while(opcao!=5);

    return 0;
}

dados_produto insere_produto(){
    dados_produto aux;
    printf("Id do produto              : ");
    scanf("%d", &aux.id);
    printf("Descricao do produto       : ");
    getchar();
    fgets(aux.descricao, 20,stdin);
    printf("Quantidade no estoque      : ");
    scanf("%d", &aux.qtd_estoque);
    printf("Valor unitario             : ");
    scanf("%f", &aux.preco);
    return aux;
}

int localiza_produto_descricao(char descricao[20], dados_produto *dados, int qtd){
    int i;
    float montante = 0.0;
    for(i=0;i<qtd;i++){
       if(strcmp(dados[i].descricao, descricao)== 0){
            return i;
       }
    }
    return NULL;
}

dados_produto* localiza_produto_descricao1(){
    int i;
    float montante = 0.0;
    for(i=0;i<qtd;i++){
       if(strcmp(dados[i].descricao, descricao)== 0){
            return i;
       }
    }
    return -1;

}

void mostra_todos_produtos(dados_produto *dados, int qtd){
    int i;
        for(i=0;i<qtd;i++){
        printf("Id do produto              :%d\n", dados[i].id);
        printf("Descricao do produto       :%s\n", dados[i].descricao);
        printf("Quantidade no estoque      :%d\n", dados[i].qtd_estoque);
        printf("Valor unitario             :%.2f\n\n", dados[i].preco);
    }
}

float mostra_total_em_reais_estoque(dados_produto *dados, int qtd){
    int i;
    float montante = 0.0;
    for(i=0;i<qtd;i++){
        montante == montante + dados[i].qtd_estoque * dados[i].preco;
    }
}

int menu(){
    int opcao;
    printf("1 - novo produto\n");
    printf("2 - mostrar cadastrados\n");
    printf("3 - mostrar descricao\n");
    printf("4 - calcula estoque\n");
    printf("5 - Sair\n opcao: ");
    scanf("%d", &opcao);
    return opcao;
}
