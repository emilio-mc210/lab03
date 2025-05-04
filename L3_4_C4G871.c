#include<stdio.h>

int entero_binario(int num){
    int binario = 0, unidad = 1, digito = 0;
    while( num ){ //Es decir mientras num!=0
        //Digito que se va a agregar
        digito = num%2;
        binario += digito*unidad;

        //Cambiar numero y unidad
        unidad *= 10;
        num /= 2;
    }

    return binario;
}

int main(){
    int num;
    printf("Ingrese un numero a convertir en binario: ");
    scanf("%i", &num);
    int binario = entero_binario(num);
    
    printf("El numero %i en binario es: %i \n", num, binario);
    return 0;
}