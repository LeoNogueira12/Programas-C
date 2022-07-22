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
                //Entrada de dados dos 5 alunos
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
                //Abre o arquivo bin no modo para escrever
                f=fopen("dados_aluno","wb");

                //testa se ele existe
                if (!f){
                    return 1;
                }

                //Escreve os dados no arquivo bin
                for (i=0;i<5; i++){
                    fwrite(&aluno[i],sizeof(aluno),1,f);
                }

                //Fecha o arquivo
                fclose(f);
                printf("Dados Exportados!\n");
                break;

            case 3:
                f=open("dados_aluno")
                break;

            case 4:
                //Abre o arquivo bin no modo de leitura
                f=fopen("dados_aluno","rb");

                //Verifica se ele existe
                if (!f)
                    return 1;

                //Exporta os dados em blocos do arquivo
                for (i=0;i<5; i++){
                    fread(&aluno[i],sizeof(aluno),1,f);
                    printf("\n.....................................................\n");
                    printf("Nome do aluno......:%s\n",aluno[i].nome);
                    printf("Media arredondada:..%f\n",aluno[i].media);
                    printf("\n.....................................................\n");
                }
                fclose(f);
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

    printf("1.Registrar 5 alunos.\n");
    printf("2.Exportar para binario todos os registros.\n");
    printf("3.Importar do arquivo binario registro por registro.\n");
    printf("4.Importar todos os registro.\n");
    printf("5.Alterar a media de um aluno.\n");
    printf("%d.Sair.\n",SAIR);
    printf("Opcao: ");
    scanf("%d",&opcao);
    printf("\n");

    return opcao;
}

void alteraDados(string altera){
    int i;
    //Procura qual aluno ele quer alterar
    for(i=0;i<5;i++){
        if(strcmp(altera,aluno[i].nome)==0){
            //Altera a média
            printf("Nova media: ");
            scanf("%f", &aluno[i].media);
        }
    }
}
