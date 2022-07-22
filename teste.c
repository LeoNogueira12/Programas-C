#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[60];

struct dados{
    string nome;
    float media;
}aluno[4];

int main()
{
    FILE *f;
    int i;

    printf("Criando arquivo com 5 registros \n");
    f=fopen("dados_aluno","wb");

    if (!f){
        return 1;
    }

    for (i=0;i<5; i++){
        printf("Nome: ");
        fgets(aluno[i].nome,60,stdin);
        printf("Media: ");
        scanf("%f",&aluno[i].media);
        fwrite(&aluno[i],sizeof(aluno),1,f);
    }
    fclose(f);

    printf("-----Lendo os 5 registros----------\n");
    f=fopen("dados_aluno","rb");
    if (!f)
        return 1;

    for (i=0;i<5; i++){
        fread(&aluno[i],sizeof(aluno),1,f);
        printf("%s\n",aluno[i].nome);
        printf("%f\n",aluno[i].media);
    }
    fclose(f);
    printf("\n");

    system("pause");

    return 0;
}
