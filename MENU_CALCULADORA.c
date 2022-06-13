#include <stdio.h>
int taml,tamc;

int ler_matriz(int a, int b){
    int i,j,m[a][b];
    for(i=0;i<a;i++){
          for(j=0;j<b;j++){
             printf("Coloque o vetor da pos (%d,%d): ",i,j);
             scanf("%d",& m[i][j]);
          }
     }
     return m;
}

void menor_matriz(int m[taml][tamc]){
    int men;
    int i,j;
    for(i=0;i<taml;i++){
        men = m[i,0];
        for(j=0;j<tamc;j++){
            if(m[i][j]<men){
                men = m [i][j];
            }
        }
         printf("O menor elemento da linha %d eh: %d\n",i, men);
    }

     return;
}

int main(){
    int m;
    printf("Numero de linhas da matriz: ");
    scanf("%d",&taml);
    printf("Numero de colunas da matriz: ");
    scanf("%d",&tamc);
    m = ler_matriz(taml,tamc);
    menor_matriz(m);

    return 0;
}
