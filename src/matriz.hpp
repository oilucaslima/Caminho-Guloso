#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;

    int lerTamanhoMatriz();
    void imprimirMatriz(int** matriz, int tamanho);
    void iniciarMatriz(int** matriz, int tamanho);
    void lerMatriz(int** matriz, int tamanho);
    void andarMatriz(int** matriz, int tamanho);
    int direita(int** matriz, int i, int j);
    int esquerda(int** matriz, int i, int j);
    int baixo(int** matriz, int i, int j);
    int diagonalDireita(int** matriz, int i, int j);
    int diagonalEsquerda(int** matriz,int i, int j);

#endif