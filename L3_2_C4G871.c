#include<stdio.h>
#define TAMANO 4

int suma_diagonal(int matriz[TAMANO][TAMANO], int n){
    int diagonal = 0, cont = 1;

    //Revisar diagonales hacia la esquina inferior derecha
    //Ciclo que revisa diagonales desde la inferior izquierda a la central
    for(int k=n-1; k>=0; k--){
        diagonal = 0;
        for(int i=k, j=0; i<n; i++, j++){
            diagonal += matriz[i][j];
        }
        printf("La diagonal %i es: %i\n",cont,diagonal);
        cont++;
    }
    //Diagonales a la derecha de la central hasta la esquina superior derecha
    for(int k=1; k<n; k++){
        diagonal = 0;
        for(int i=0, j=k; j<n; i++, j++){ 
            diagonal += matriz[i][j];
        }
        printf("La diagonal %i es: %i\n",cont,diagonal);
        cont++;
    }  

    //Revisar diagonales hacia la esquina inferior izquierda
    //Ciclo que revisa diagonales desde la superior izquierda a la central
    for(int k=0; k<n; k++){        
        diagonal = 0;
        for(int i=0, j=k; j>=0; i++, j--){
            diagonal += matriz[i][j];
        }
        printf("La diagonal %i es: %i\n",cont,diagonal);
        cont++;
    }
    //Diagonales a la derecha de la central hasta la esquina inferior derecha
    for(int k=1; k<n; k++){        
        diagonal = 0;
        for(int i=k, j=n-1; i<n; i++, j--){ 
            diagonal += matriz[i][j];
        }
        printf("La diagonal %i es: %i\n",cont,diagonal);
        cont++;
    }

    return 0;
}

int main(){
    int matriz[TAMANO][TAMANO] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };

    int n = sizeof(matriz[0])/sizeof(matriz[0][0]);

    //Imprimir la matriz
    printf("La matriz es: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\t%i", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Diagonales
    suma_diagonal(matriz,TAMANO);
    return 0;
}