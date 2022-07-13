//Manipulação de arquivod tipo texto
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

void lerNumeros(int *numeros);
void mostraNumeros(int *numeros);
void importaDados(FILE *f_numeros,int *numeros);

int main(){
    FILE *arq_numeros;
    int *numeros = (int*)malloc(sizeof(int)*TAMANHO),i;

    //Abre aqruivo
    arq_numeros = fopen(/*nome*/"f_numeros.txt",/*modo: r=read;w=write;a=append;+ = cria o arquivo se n existir*/"r");
    if(arq_numeros == NULL){
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }

    /*lerNumeros(numeros);
    mostraNumeros(numeros);

    //Salvar em arquivo
    for(i=0;i<TAMANHO;i++){
        fprintf(arq_numeros,"%d\n", numeros[i]);
    }*/

    //Importando dados
    importaDados(arq_numeros,numeros);
    mostraNumeros(numeros);

    //Libera memória alocada
    free(numeros);
    fclose(arq_numeros);

    return 0;
}

void lerNumeros(int *numeros){
    int i;
    for(i=0;i<TAMANHO;i++){
        printf("Coloque o elemento [%d]: ",i);
        scanf("%d", &numeros[i]/*(numeros+i)*/);
    }
}
void mostraNumeros(int *numeros){
    int i;
    printf("\n**********************************************************\n");
    for(i=0;i<TAMANHO;i++){
        printf("Elemento [%d]: %d\n",i,numeros[i]/* *(numeros+i) */);
    }
    printf("\n**********************************************************\n");
}
void importaDados(FILE *f_numeros,int *numeros){
    int i;
    for(i=0;i<TAMANHO;i++){
        fscanf(f_numeros,"%d\n", &numeros[i]);
    }
}
