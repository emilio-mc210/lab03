#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAMANO 5

int llenar_matriz(int matriz[TAMANO][TAMANO]){
    srand(time(NULL));
    int entrada;
    //Recorrer la matriz entrada por entrada
    for(int i=0; i<TAMANO; i++){
        for(int j=0; j<TAMANO; j++){
            entrada = rand() % 2;
            matriz[i][j] = entrada;
        }
    }

    return 0;
}

int encontrar_diagonal_mas_larga(int matriz[TAMANO][TAMANO]){
    int diagonal = 0, maximo = 0;
    int i,j,k;

    //Revisar diagonales hacia la esquina inferior derecha (de izquierda a derecha)
    //Ciclo que revisa diagonales desde la inferior izquierda a la central
    for(k=TAMANO-1; k>=0; k--){
        for(i=k, j=0; i<TAMANO; i++, j++){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Diagonales a la derecha de la central hasta la esquina superior derecha
    for(k=1; k<TAMANO; k++){
        for(i=0, j=k; j<TAMANO; i++, j++){ 
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    } 
    diagonal = 0;
    

    //Revisar diagonales hacia la esquina inferior derecha (de derecha a izquierda)
    //Ciclo que revisa diagonales desde la superior derecha a la central
    for(k=TAMANO-1; k>=0; k--){
        for(i=0, j=k; j<TAMANO; i++, j++){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Diagonales a la izquierda de la central hasta la esquina inferior izquierda
    for(k=1; k<TAMANO; k++){
        for(i=k, j=0; i<TAMANO; i++, j++){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    diagonal = 0;


    //Revisar diagonales hacia la esquina inferior izquierda (de izquierda a derecha)
    //Ciclo que revisa diagonales desde la superior izquierda a la central
    for(k=0; k<TAMANO; k++){
        for(i=0, j=k; j>=0; i++, j--){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Diagonales a la derecha de la central hasta la esquina inferior derecha
    for(k=1; k<TAMANO; k++){
        for(i=k, j=TAMANO-1; i<TAMANO; i++, j--){ 
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    diagonal = 0;


    //Revisar diagonales hacia la esquina inferior izquierda (de derecha a izquierda)
    //Ciclo que revisa diagonales desde la inferior derecha a la central
    for(k=TAMANO-1; k>=0; k--){
        for(i=k, j=TAMANO-1; i<TAMANO; i++, j--){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Diagonales a la izquierda de la central hasta la esquina superior izquierda
    for(k=TAMANO-2; k>=0; k--){ //TAMANO-2 para no repetir la central
        for(i=0, j=k; j>=0; i++, j--){ 
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    diagonal = 0;

    return maximo;
}

int main() {
    int matriz[TAMANO][TAMANO] = {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
    };

    //Llenar la matriz
    llenar_matriz(matriz);

    //Imprimir la matriz
    printf("La matriz es: \n");
    for(int i=0;i<TAMANO;i++){
        for(int j=0;j<TAMANO;j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int diagonal_mas_larga = encontrar_diagonal_mas_larga(matriz);
    printf("La secuencia de 1s mas grande es: %d\n", diagonal_mas_larga);
    return 0;
}