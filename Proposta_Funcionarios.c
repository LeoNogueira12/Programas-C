#include <stdio.h>
#include <string.h>

#define TAM 2

struct Funcionario{

    int idade;
    char nome[50];
    float salario;
};
void LerDados(struct Funcionario funcionario[TAM]);
void Imprime(struct Funcionario funcionario[TAM]);

int main(){

    struct Funcionario funcionario[TAM];
    LerDados(funcionario);
    Imprime(funcionario);

 return 0;
}

void LerDados(struct Funcionario funcionario[TAM]){
    int idade;
    float salario;
    char nome[50];
    int i;
    for(i=0;i<TAM;i++){
        printf("--------Funcionario %d---------\n", i+1);
        printf("Coloque seu nome: ");
        gets(nome);
        strcpy(funcionario[i].nome,nome);
        printf("Coloque sua idade: ");
        scanf("%d", &idade);
        funcionario[i].idade = idade;
        printf("Coloque seu salario: ");
        scanf("%f", &salario);
        getchar();
        funcionario[i].salario = salario;
    }
    return;
}
void Imprime(struct Funcionario funcionario[TAM]){
    int i;
    for(i=0;i<TAM;i++){
        printf("----- Dados do Funcionario-------\n");
        printf("Nome: %s \n", funcionario[i].nome);
        printf("idade: %d \n", funcionario[i].idade);
        printf("Salario aproximado: %.2f \n", funcionario[i].salario);
    }
    return;
}
