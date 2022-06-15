#include<stdio.h>
#define TAM 10

int pos_maior(int v[TAM]){
    int maior,i,pos;
    maior = v [0];
    for(i=0;i<TAM;i++){
        if(v[i]>maior){
            maior=v[i];
            pos=i;
        }
    }

    return pos;
}

int main(){
    int vetor[TAM],i,k;
    for(i=0;i<TAM;i++){
        printf("Insira o valor: ");
        scanf("%d",&vetor[i]);
    }
    k = pos_maior(vetor);
    printf("O maior vetor eh %d na posicao %d",vetor[k] ,k);

    return 0;
}
