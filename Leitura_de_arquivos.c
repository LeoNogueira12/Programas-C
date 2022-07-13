//Controle Econômico
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_STRING 30
#define QTD_DADOS 3
#define SAIR 5

typedef char string[TAMANHO_STRING];

typedef struct bolsa{
    string referencia;
    int dia;
    int mes;
    float variacao;
}dados_bolsa;

//Funcões
dados_bolsa criaRegistro();
void mostraRegistro(dados_bolsa *dados,int qtd_regs);
int menu();
void removeEnter(string s);
void exportaDados(dados_bolsa *dados,string nome, int qtd);
void importaDados(dados_bolsa *dados, int *qtd);

int main(){
    //Alocação Dinâmica
    dados_bolsa *dados;
    dados = (dados_bolsa*)malloc(sizeof(dados_bolsa)*QTD_DADOS);
    int qtd_registros=0,opcao;
    string nome_arq;

    do{
        opcao = menu();
        switch(opcao){
        case 1:
            dados[qtd_registros] = criaRegistro();
            qtd_registros ++;
            break;
        case 2:
            mostraRegistro(dados,qtd_registros);
            break;
        case 3:
            getchar();
            printf("Qual o nome do arquivo? ");
            fgets(nome_arq,TAMANHO_STRING,stdin);
            removeEnter(nome_arq);
            exportaDados(dados,nome_arq,qtd_registros);
            break;
        case 4:
            importaDados(dados,&qtd_registros);
            break;
        case SAIR:
            free(dados);
            break;
        }
    }while(opcao!=SAIR);

    return 0;
}

//Implementação de funções
dados_bolsa criaRegistro(){
    dados_bolsa novo_registro;

    getchar();
    printf("Referencia: ");
    fgets(novo_registro.referencia,30,stdin);
    removeEnter(novo_registro.referencia);
    printf("Dia: ");
    scanf("%d",&novo_registro.dia);
    printf("Mes: ");
    scanf("%d",&novo_registro.mes);
    printf("Variacao: ");
    scanf("%f",&novo_registro.variacao);

    return novo_registro;
}

void mostraRegistro(dados_bolsa *dados,int qtd_regs){
    int i;
    for(i=0;i<qtd_regs;i++){
        printf("\n*************************************\n");
        printf("Dados do registro %d\n",i);
        printf("Referencia: %s\n",dados[i].referencia);
        printf("dia/mes   : %d/%d\n",dados[i].dia,dados[i].mes);
        printf("Variacao  : %2.f",dados[i].variacao);
        printf("\n*************************************\n");
    }
}

int menu(){
    int opcao;

    printf("1 - Novo registro.\n");
    printf("2 - Mostra registros.\n");
    printf("3 - Exportar dados para txt.\n");
    printf("4 - Importar dados.\n");
    printf("%d - Sair\n",SAIR);
    printf("Opcao: ");
    scanf("%d",&opcao);

    return opcao;
}

void removeEnter(string s){
    int len = strlen(s);
    s[len-1] = "\0";
}

void exportaDados(dados_bolsa *dados,string nome, int qtd){
    int i;
    FILE *fp_arq;

    fp_arq = fopen(nome,"w+");

    for(i=0;i<qtd;i++){
        fprintf(fp_arq,"%s\n",dados[i].referencia);
        fprintf(fp_arq,"%d\n",dados[i].dia);
        fprintf(fp_arq,"%d\n",dados[i].mes);
        fprintf(fp_arq,"%2.f\n\n",dados[i].variacao);
    }
    fclose(fp_arq);
}

void importaDados(dados_bolsa *dados, int *qtd){
    string nome_arq;
    FILE *fp_arq;
    *qtd = 0;

    getchar();
    printf("Nome do arquivo para importacao: ");
    fgets(nome_arq,TAMANHO_STRING,stdin);
    removeEnter(nome_arq);

    fp_arq = fopen(nome_arq,"r");

    while(!feof(fp_arq)){
        fscanf(fp_arq,"%s\n",&dados[*qtd].referencia);
        fscanf(fp_arq,"%d\n",&dados[*qtd].dia);
        fscanf(fp_arq,"%d\n",&dados[*qtd].mes);
        fscanf(fp_arq,"%f\n\n",&dados[*qtd].variacao);
        *qtd += 1;
    }
    fclose(fp_arq);
}
