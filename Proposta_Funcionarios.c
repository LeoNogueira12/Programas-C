#include <stdio.h>
#include <string.h>

#define TAM 101

struct Funcionario{

    int idade;
    char nome[60];
    char cidade[60];
    float salario;
};
void lerDados(struct Funcionario funcionario[TAM]);
void atualizacaoDados(struct Funcionario funcionario[TAM],int bf);
void deletarFuncionario(struct Funcionario funcionario[TAM],int bs);
void mostraDados(struct Funcionario funcionario[TAM],int bf);
void buscaNome(struct Funcionario funcionario[TAM], char buscanome[60]);
void listaSalario(struct Funcionario funcionario[TAM]);
void funcionariosCidade(struct Funcionario funcionario[TAM]);
int repeticaoCidade(char *f1, char *f2, int k);

int main(){
    int menu,i,comp;
    char buscanome[60],vetcidade[TAM];
    int bf,bs;
    
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
	system("cls");
        switch(menu){
            case 1: //Inserir Funcionario
				lerDados(funcionario);
                break;

            case 2: //Atualizar dados do funcionario cadastrados
                printf("Digite o numero do funcionario a ser atualizado: ");
                scanf("%d", &bf);
                getchar();
                atualizacaoDados(funcionario,bf);
                break;

            case 3: //Deletar os dados de um funcionario
                printf("Digite o numero do funcionario a ser deletado: ");
                scanf("%d", &bs);
				deletarFuncionario(funcionario,bs);

                break;

            case 4: //Consultar dados de um funcionario pelo numero
            	printf("Qual funcionario deseja buscar os dados? ");
    			scanf("%d",&bf);
				mostraDados(funcionario,bf);
                break;

            case 5: //Consulta por nome do funcionario
            	printf("Qual funcionario deseja buscar? ");
            	getchar();
            	gets(buscanome);
            	buscaNome(funcionario,buscanome);
            	
                break;

            case 6: //Funcionarios com salario maior ou igual a um certo numero
                printf("Com qual numero deseja comparar o salario? ");
                scanf("%d", &comp);
                for(i=0;i<TAM;i++){
                    if(funcionario[i].salario==comp||funcionario[i].salario>comp){
                       printf("Funcionario: %s\n",funcionario[i].nome);
                    }
                }
                break;

            case 7: //Lista de funcionarios que ganham 1 salario minimo ou menos, mais de 1 salario minimo a 3 salarios minimos e mais que 3 salarios minimos
            	listaSalario(funcionario);
            
                break;

            case 8: //Numero de funcionarios por cidade
				funcionariosCidade(funcionario);

                break;
            case 9: //Sair
				printf("Saindo...");
                break;

        }
    }while(menu!=9);

 return 0;
}

void lerDados(struct Funcionario funcionario[TAM]){ //Leitura de dados
    int idade,i=0,f,k=0,ano;
    float salario,data;
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
            printf("Coloque a sua data de aniversario (dd.mm): ");
            scanf("%f", &data);
            printf("Coloque a sua data de aniversario (ano): ");
            scanf("%d", &ano);
            getchar();
            funcionario[i].idade = 2022-ano;
		//. necessario no final da cidade
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
void atualizacaoDados(struct  Funcionario funcionario[TAM],int bf){
	int i,aidade;
	char anome[60],acidade[60];
	float asalario;
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
                return;
}
void deletarFuncionario(struct Funcionario funcionario[TAM],int bs){ //deleta o funcionario
	int i;
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
	return;
	
}
void mostraDados(struct Funcionario funcionario[TAM],int bf){ //impressão de dados
    int i;
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
void buscaNome(struct Funcionario funcionario[TAM], char buscanome[60]){//busca de dados por nome
	int i;
	for (i=0;i<TAM;i++){
        if(strcmp(funcionario[i].nome,buscanome)==0){
           	printf("----- Dados do Funcionario-------\n");
           	printf("Nome: %s \n", funcionario[i].nome);
           	printf("idade: %d \n", funcionario[i].idade);
           	printf("Salario aproximado: %.2f \n", funcionario[i].salario);
           	printf("Cidade: %s \n", funcionario[i].cidade);
		}
   	}
   	return;
}
void listaSalario(struct Funcionario funcionario[TAM]){
	int i;
	for(i=0;i<TAM;i++){
        if(funcionario[i].salario==1212||funcionario[i].salario<1212 && funcionario[i].salario!=-999999){
         printf("Funcionario que recebe um salario minimo ou menos: %s\n",funcionario[i].nome);
        }
    }
    for(i=0;i<TAM;i++){
        if(funcionario[i].salario>1212 && funcionario[i].salario<(3*1212)||funcionario[i].salario==(3*1212)){
            printf("Funcionario que recebe mais de salario minimo ate tres: %s\n",funcionario[i].nome);
        }
	}
	for(i=0;i<TAM;i++){
		if(funcionario[i].salario>(3*1212)){
            printf("Funcionario que recebe mais de tres salarios minimos: %s\n",funcionario[i].nome);
        }
	}
	return;
}
void funcionariosCidade(struct Funcionario funcionario[TAM]){
	int i,count=0,count1=0,r1=0,r2=0,j;
	for(j=0;j<TAM;j++){
        if(funcionario[j].idade!= -987654321){
            strcat(funcionario[101].cidade,funcionario[j].cidade);
        }
	}

	for(i=1;i<TAM;i++){
	    if(funcionario[i].idade != -987654321){
            do{
                r1=repeticaoCidade(funcionario[101].cidade,funcionario[i].cidade,r1);
                if(r1 != -1){
                	count++;
                }
            }while(r1!=-1);
            printf("Quantidade de funcionarios na cidade %s: %d\n",funcionario[i].cidade, count);
	    }
	}
	do{
        r2=repeticaoCidade(funcionario[101].cidade,funcionario[0].cidade,r2);
        if(r2 != -1){
        	count1++;
        }
    }while(r2!=-1);
    printf("Quantidade de funcionarios na cidade %s: %d\n",funcionario[0].cidade, count1);	
	return;
}
int repeticaoCidade(char *f1,char *f2, int k){
    int i,j=0;
    for(i=k;i<strlen(f1);i++){
        if(f1[i] == f2[j]){
            j++;
        }else{
            j=0;
        }
        if(j==strlen(f2)){
            return i;
        }
    }
    return -1;
}
