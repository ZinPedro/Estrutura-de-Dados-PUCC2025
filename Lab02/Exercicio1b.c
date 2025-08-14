/*Elabore um programa que contenha uma função recebe 3
valores float (n1, n2, n3) e retornar o (x*x)+y+z. Os valores
devem ser lidos no programa principal, o resultado também
deve ser impresso no principal.
• Construa essa função de duas maneiras diferentes,
respeitando os cabeçalhos abaixo:
a. float calculo(float x,float y, float z)
b. void calculo(float x, float y, float z, float *r)*/

#include <stdio.h> 
#include <stdlib.h>

void calculo (float x, float y, float z, float *r){
    float cal=0;
    cal = (x*x)+y+z;
    *r = cal;
    return 0;
}

int main(){
    float x,y,z,c,*r;

    printf("Calculo: (x*x)+y+z\n");


    printf("Digite o numero referente a x: ");
    scanf("%f",&x);

    printf("Digite o numero referente a y: ");
    scanf("%f",&y);

    printf("Digite o numero referente a z: ");
    scanf("%f",&z);

    r = &c;

    calculo(x,y,z,r);

    printf("\nO calculo de (x*x)+y+z eh: %.2f",*r);

    return 0;
}