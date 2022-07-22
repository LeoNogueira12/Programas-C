#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIR 6
typedef char string[60];

struct dados{
    string nome;
    float media;
}aluno[4];

int menu();
void alteraDados(string altera);

int main()
{
    FILE *f;
    int i,opcao;
    string nome_aux;

    do{
        opcao = menu();
        switch(opcao){
            case 1:
                for (i=0;i<5; i++){
                    getchar();
                    printf("Nome: ");
                    fgets(aluno[i].nome,60,stdin);
                    printf("Media: ");
                    scanf("%f",&aluno[i].media);
                    printf("\n");
                }
                break;

            case 2:
                f=fopen("dados_aluno","wb");

                if (!f){
                    return 1;
                }
                for (i=0;i<5; i++){
                    fwrite(&aluno[i],sizeof(aluno),1,f);
                }
                fclose(f);
                printf("Dados Exportados!\n");
                break;

            case 3:
                f=fopen("dados_aluno","rb");
                if (!f)
                    return 1;

                for (i=0;i<5; i++){
                    fread(&aluno[i],sizeof(aluno),1,f);
                    printf("\n.....................................................\n");
                    printf("Nome do aluno......:%s\n",aluno[i].nome);
                    printf("Media arredondada:..%f\n",aluno[i].media);
                    printf("\n.....................................................\n");
                }
                fclose(f);
                break;

            case 4:
                break;
            case 5:
                printf("Qual aluno deseja alterar? ");
                getchar();
                fgets(nome_aux,60,stdin);
                alteraDados(nome_aux);
                printf("Dados alterados!\n");
                break;
            case SAIR:
                break;
        }
    }while(opcao != SAIR);

    return 0;
}

int menu(){
    int opcao;

    printf("1.Registrar 5 alunos\n");
    printf("2.Exportar para binario todos os registros\n");
    printf("3.Importar do arquivo binario todos os registros.\n");
    printf("4.Importar apenas um registro.\n");
    printf("5.Alterar dados\n");
    printf("%d.Sair\n",SAIR);
    printf("Opcao: ");
    scanf("%d",&opcao);
    printf("\n");

    return opcao;
}

void alteraDados(string altera){
    int i;
    for(i=0;i<5;i++){
        if(strcmp(altera,aluno[i].nome)==0){
            printf("Novo nome: ");
            fgets(aluno[i].nome,60,stdin);
            printf("Nova media: ");
            scanf("%f", &aluno[i].media);
        }
    }
}
