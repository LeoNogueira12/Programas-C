//modularização de programa funções (subdivisões de main)

#include <stdio.h>
#include <stdlib.h>

int colunas,linhas,i,j,m[99][99];

int matriz(int a, int b){
    for(i=0;i<a;i++){
          for(j=0;j<b;j++){
             printf("Coloque o vetor da pos (%d,%d): ",i+1,j+1);
             scanf("%d",& m[i][j]);
          }
     }
     for(i=0;i<a;i++){
          for(j=0;j<b;j++){
             printf("%d\t",m[i][j]);
          }
          printf("\n");
     }
     return printf("Fim da operação.");
}

int main(){
    printf("coloque o tamanho de linhas: ");
    scanf("%d",&linhas);
    printf("coloque o tamanho de colunas: ");
    scanf("%d",&colunas);
    printf("%d\n",matriz(linhas,colunas));
    return 0;  
}
