#include "matriz.hpp"

using namespace std;

int main(){

    int tamanho;
    int** matriz;

    tamanho = lerTamanhoMatriz();

    matriz = (int**)malloc(tamanho*sizeof(int*));
    for (int i=0; i<tamanho; i++){
	    matriz[i] = (int*)malloc(tamanho*sizeof(int));
    }

    lerMatriz(matriz,tamanho);
}