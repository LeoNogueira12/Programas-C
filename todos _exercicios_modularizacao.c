#include <stdio.h>
#include <math.h>

int num3,a,b,i,fat,taml,tamc;
//modulo exercicio 1
/*int calculadora(int menu, int num1,int num2){
    int d;
    switch(menu){
          case 1:
            d=num1+num2;
            printf("A soma de dos numeros eh: %d", d);
               break;
          case 2:
            d=num1-num2;
            printf("A subtracao de dos numeros eh: %d", d);
               break;
          case 3:
            d=num1/num2;
            printf("A divisao de dos numeros eh: %d", d);
               break;
          case 4:
            d=num1*num2;
            printf("A multiplicacao de dos numeros eh: %d", d);
               break;
          case 5:
          d= pow(num1,num2);
            printf("A potencia de %d na %d eh: %d", num1,num2,d);
               break;
      }
    return d;
}*/
//modulo exercicio 2
/*int fatorial(int a){
    for(fat = 1; a > 1; a = a - 1){
        fat = fat * a;
    }
     return fat;
}*/

//modulo exercicio3
/*float pesoideal(float altura,char sexo){
    int peso;
    if(sexo =='m'||sexo =='M'){
        peso=(72*altura)-58;
    }else if(sexo =='f'||sexo =='F'){
        peso=(62,1*altura)-44;
    }
    return peso;
}*/

//modulo exercicio4
/*float mediana(char parametro, float n1,float n2, float n3){
    int final;
    if(parametro=='a'){
        final=(n1+n2+n3)/3;
    }else if(parametro == 'p'){
        final=(n1*5+n2*3+n3*2)/9;
    }else if(parametro=='h'){
        final=3/(1/n1)+(1/n2)+(1/n3);
    }
    return final;
}*/

//modul ex 6
/*int ds(int tam){
    int soma=0,i,n=0,media,a[tam];
    for(i =0;i<tam;i++){
        printf("coloque o numero no vetor: ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<tam;i++){
        if(a[i]%2==0){
            soma = soma+a[i];
            n++;
        }
    }
    media=soma/n;
    return media;
}*/


//modulo exercicio 7
int ds(int a[taml][tamc]){
   int i,j,soma=0;
    for(i=0;i<taml;i++){
        for(j=0;j<tamc;j++){
            if(i+j==(taml-1)){
                soma=a[i][j]+soma;
            }
        }
    }
    return soma;

}


int main(){
    //exercicio  1
    /*int menu,num1,num2;
    printf("Bem vindo! qual operacao deseja fazer?\n 1 – para adicao (x+y)\n 2 – para subtracao (x-y)\n 3 – para divisao (x/y)\n 4 – para multiplicacao (x*y)\n 5 – para potencia (xy)\n");
    scanf("%d", &menu);
    printf("coloque o primeiro numero: ");
    scanf("%d",&num1);
    printf("coloque o segundo numero: ");
    scanf("%d",&num2);
    calculadora(menu,num1,num2);*/



    //exercicio 2
   /* printf("coloque o numero: ");
    scanf("%d",&num3);
    printf("O fatorial de %d eh: %d",num3,fatorial(num3));*/

    //exercicio 3
    /*float altura;
    char sexo;
    printf("coloque a sua altura: ");
    scanf("%f",&altura);
    printf("coloque o seu sexo: ");
    scanf("%c",&sexo);
    getchar();
    printf("O seu peso ideal eh: %f ", pesoideal(altura,sexo));*/

    //exercicio 4
    /*float media,nota1,nota2,nota3;
    printf("Coloque a primeira nota: ");
    scanf("%f",&nota1);
    printf("Coloque a 2 nota: ");
    scanf("%f",&nota2);
    printf("Coloque a 3 nota: ");
    scanf("%f",&nota3);
    getchar();
    char parametro;
    printf("Qual parametro deseja usar? a-media aritmetica,p media ponderada ou h harmonica? ");
    scanf("%c",&parametro);
    printf("%0.1f",mediana(parametro,nota1,nota2,nota3));*/

    //exercicio 6
    /*int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    printf("%d", ds(tam));*/

    //exercicio 7
    printf("Digite quantas linhas: ");
    scanf("%d", &taml);
    printf("Digite quantas colunas: ");
    scanf("%d", &tamc);
    int i,j,soma=0,a[taml][tamc];
    for(i=0;i<taml;i++){
        for(j=0;j<tamc;j++){
            printf("Coloque o elemento(%d,%d) na matriz: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d",ds(a));




    return 0;
}
