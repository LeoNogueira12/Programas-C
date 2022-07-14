#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SAIR 9

typedef char string[60];

typedef struct Funcionario{

    int idade;
    string nome;
    string cidade string;
    float salario;

}dados;

int menu();
void cadastroFuncionario();
void buscaFuncionario();

int main(){
    int menu;
    do{
        menu = menu();
        switch(menu){

            case SAIR: //Sair
				printf("Saindo...");
                break;
        }
    }while(menu!=SAIR);

 return 0;
}

int menu(){
    int opcao;
    printf("\nBem vindo!\n Qual operacao deseja reaizar?");
    printf("1 - Cadastrar um funcionario.\n");
    printf("2 - Atualizar dados de um funcionario\n");
    printf("3 - Deletar um funcionario.\n");
    printf("4 - Relatorio de todos os funcionarios.\n");
    printf("5 - Consulta de funcionario por nome.\n");
    printf("6 - Numero de funcionarios com salario maior ou igual a um certo numero.\n");
    printf("7 - Numero de funcionarios que ganham 1 salário minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos.\n");
    printf("8 - Numero de funcionarios por cidade.\n");
    printf("%d - Sair.\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return opcao;
}

void buscaFuncionario(){

}


