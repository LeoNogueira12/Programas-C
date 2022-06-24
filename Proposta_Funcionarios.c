#include <stdio.h>
#include <string.h>

#define TAM 100

struct Funcionario{

    int idade;
    char nome[60];
    char cidade[60];
    float salario;
};
void lerDados(struct Funcionario funcionario[TAM]);
void imprime(struct Funcionario funcionario[TAM]);

int main(){
    int menu,i,comp,j,r1,count=0;
    char anome[60];
    char acidade[60],buscanome[60],vetcidade[TAM];
    float asalario;
    int bf,bs,aidade,resultado;
    struct Funcionario funcionario[TAM];
    for(i=0;i<TAM;i++){
        funcionario[i].idade = -987654321;
        funcionario[i].salario = -999999;
        funcionario[i].cidade[i] = 'n';
        funcionario[i].cidade[i+1] = 'u';
        funcionario[i].cidade[i+2] = 'l';
        funcionario[i].cidade[i+3] = 'l';
        funcionario[i].nome[i] = 'n';
        funcionario[i].nome[i+1] = 'u';
        funcionario[i].nome[i+2] = 'l';
        funcionario[i].nome[i+3] = 'l';
    }
    funcionario[57].salario=-999999;
    funcionario[58].salario=-999999;
    funcionario[59].salario=-999999;
    funcionario[60].salario=-999999;
    funcionario[61].salario=-999999;
    funcionario[62].salario=-999999;
    funcionario[63].salario=-999999;
    do{
        printf("\nBem vindo!\nO que deseja acessar?\n 1-Inserir Funcionario\n2-Atualizar dados do funcionario cadastrados\n3-Deletar os dados de um funcionario\n4-Consultar dados de um funcionario pelo numero\n5-Consulta por nome do funcionario\n6-Funcionarios com salario maior ou igual a um certo numero\n7-Lista de funcionarios que ganham 1 salario minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos\n8-Numero de funcionarios por cidade\n9-Sair.\n");
        scanf("%i", &menu);
        switch(menu){
            case 1: //Inserir Funcionario
				lerDados(funcionario);
                break;

            case 2: //Atualizar dados do funcionario cadastrados
                printf("Digite o numero do funcionario a ser atualizado: ");
                scanf("%d", &bf);
                getchar();
                for(i=0;i<TAM;i++){
                    if(i==bf){
                        printf("--------Funcionario %d---------\n", i);
                        printf("Coloque o nome: ");
                        gets(anome);
                        strcpy(funcionario[i].nome,anome);
                        printf("Coloque a idade: ");
                        scanf("%d", &aidade);
                        getchar();
                        funcionario[i].idade = aidade;
                        printf("Coloque a cidade: ");
                        gets(acidade);
                        strcpy(funcionario[i].cidade,acidade);
                        printf("Coloque o salario: ");
                        scanf("%f", &asalario);
                        getchar();
                        funcionario[i].salario = asalario;
                    }
                }
                break;

            case 3: //Deletar os dados de um funcionario
                printf("Digite o numero do funcionario a ser deletado: ");
                scanf("%d", &bs);
                for(i=0;i<TAM;i++){
                    if(i==bs){
                        funcionario[i].idade = -987654321;
                        funcionario[i].salario = -999999;
                        funcionario[i].cidade[i] = 'n';
                        funcionario[i].cidade[i+1] = 'u';
                        funcionario[i].cidade[i+2] = 'l';
                        funcionario[i].cidade[i+3] = 'l';
                        funcionario[i].nome[i] = 'n';
                        funcionario[i].nome[i+1] = 'u';
                        funcionario[i].nome[i+2] = 'l';
                        funcionario[i].nome[i+3] = 'l';
                    }
                }

                break;

            case 4: //Consultar dados de um funcionario pelo numero
				imprime(funcionario);
                break;

            case 5: //Consulta por nome do funcionario
            	printf("Qual funcionario deseja buscar? ");
            	getchar();
            	gets(buscanome);
            	for (i=0;i<TAM;i++){
            		resultado = strcmp (funcionario[i].nome,buscanome);
            		if(resultado==0){
            			printf("----- Dados do Funcionario-------\n");
            			printf("Nome: %s \n", funcionario[i].nome);
            			printf("idade: %d \n", funcionario[i].idade);
            			printf("Salario aproximado: %.2f \n", funcionario[i].salario);
            			printf("Cidade: %s \n", funcionario[i].cidade);
					}
            	}
                break;

            case 6: //Funcionarios com salario maior ou igual a um certo numero
                printf("Com qual numero deseja comparar o salario? ");
                scanf("%d", &comp);
                for(i=0;i<TAM;i++){
                    if(funcionario[i].salario==comp||funcionario[i].salario>comp){
                       printf("Funcionario: %d\n",i);
                    }
                }
                break;

            case 7: //Lista de funcionarios que ganham 1 salario minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos
            	for(i=0;i<TAM;i++){
                    if(funcionario[i].salario==1212||funcionario[i].salario<1212 && funcionario[i].salario!=-999999){
                       printf("Funcionario que recebe um salario minimo ou menos: %d\n",i);
                	}
                }
                for(i=0;i<TAM;i++){
                	if(funcionario[i].salario>1212 && funcionario[i].salario<(3*1212)||funcionario[i].salario==(3*1212)){
                       printf("Funcionario que recebe mais de salario minimo ate tres: %d\n",i);
                    }
				}
				for(i=0;i<TAM;i++){
					if(funcionario[i].salario>(3*1212)){
                       printf("Funcionario que recebe mais de tres salarios minimos: %d\n",i);
                    }
				}
                break;

            case 8: //Numero de funcionarios por cidade
	        	for(i=0;i<1;i++){
                    for(j=i+1;j<TAM;j++){
                        if(funcionario[i].idade!= -987654321 && funcionario[j].idade!= -987654321){
                            strcat(funcionario[i].cidade,funcionario[j].cidade);
                            //printf("%s\n", funcionario[i].cidade);

                        }
                    }
	        	}
	        	printf("%s\n",funcionario[0].cidade);
                break;

            case 9: //Sair
				printf("Saindo...");
                break;

        }
    }while(menu!=9);

 return 0;
}

void lerDados(struct Funcionario funcionario[TAM]){ //Leitura de dados
    int idade,i=0,f,k=0;
    float salario;
    char nome[60],cidade[60];
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d",&f);
    getchar();
    do{
        if(funcionario[i].idade == -987654321){
            printf("--------Funcionario %d---------\n", i);
            printf("Coloque o nome: ");
            gets(nome);
            strcpy(funcionario[i].nome,nome);
            printf("Coloque a idade: ");
            scanf("%d", &idade);
            getchar();
            funcionario[i].idade = idade;
            printf("Coloque a cidade: ");
            gets(cidade);
            strcpy(funcionario[i].cidade,cidade);
            printf("Coloque o salario: ");
            scanf("%f", &salario);
            getchar();
            funcionario[i].salario = salario;
            k++;
        }
        i++;
    }while(i<TAM&&k<f);

    return;
}
void imprime(struct Funcionario funcionario[TAM]){ //impressão de dados
    int i,bf;
    printf("Qual funcionario deseja buscar os dados? ");
    scanf("%d",&bf);
    for(i=0;i<TAM;i++){
        if(i==bf){
            printf("----- Dados do Funcionario-------\n");
            printf("Nome: %s \n", funcionario[i].nome);
            printf("idade: %d \n", funcionario[i].idade);
            printf("Salario aproximado: %.2f \n", funcionario[i].salario);
            printf("Cidade: %s \n", funcionario[i].cidade);
        }
    }
    return;
}
