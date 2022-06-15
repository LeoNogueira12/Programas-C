include <stdio.h>
#include <string.h>
#define TAM 5

struct Aluno{

    float media;
    char nome[50];
};
void LerDados(struct Aluno aluno[TAM]);
void Imprime(struct Aluno aluno[TAM]);

int main(){

    struct Aluno aluno[TAM];
    LerDados(aluno);
    Imprime(aluno);

 return 0;
}

void LerDados(struct Aluno aluno[TAM]){
    float media;
    char nome[50];
    int i;
    for(i=0;i<TAM;i++){
        printf("-------- Aluno %d---------\n", i+1);
        printf("Coloque seu nome: ");
        gets(nome);
        strcpy(aluno[i].nome,nome);
        printf("Coloque sua media: ");
        scanf("%f", &media);
        getchar();
        aluno[i].media = media;
    }
    return;
}
void Imprime(struct Aluno aluno[TAM]){
    int i;
    float media=0;
    for(i=0;i<TAM;i++){
        media = aluno[i].media + media;
    }
    printf("A media de todos os alunos eh: %2.f",media/TAM);
    return;
}
