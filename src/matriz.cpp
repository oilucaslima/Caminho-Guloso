#include "matriz.hpp"
int totalDasMatriz=0;

int lerTamanhoMatriz(){

    ifstream arquivo;
    int contadorLinha=0, contadorEspaco=0,intTamMatriz=0;
    string caractere="", tamMatriz="";

    arquivo.open("dataset/input.data",ios::in);

    if(arquivo.is_open()){
        while(getline(arquivo,caractere)){
            for(int i=0; i<=(int)caractere.size(); i++){
                if(caractere[i]==' '){
                    contadorEspaco++;
                }
                if(caractere[i]=='\0'){
                    contadorLinha++;
                }
                if(contadorLinha==0 && contadorEspaco==0){
                    tamMatriz+=caractere[i];
                }
            }   
        }
        //numeroMatriz = contadorLinha/(stoi(tamMatriz)+1); 
        intTamMatriz = atoi(tamMatriz.c_str());
    }
    arquivo.close();
    return intTamMatriz;
}

void iniciarMatriz(int** matriz, int tamanho){
    for(int l=0; l<tamanho; l++){
        for(int c=0; c<tamanho; c++){
            matriz[l][c]=-1;
        }
    }
}

void imprimirMatriz(int** matriz, int tamanho){

    cout<<endl;

    for(int l=0; l<tamanho; l++){
        for(int c=0; c<tamanho; c++){
            cout<<matriz[l][c]<<" ";
        }
        cout<<endl;
    }

}

void lerMatriz(int** matriz, int tamanho){

    ifstream arquivo;
    arquivo.open("dataset/input.data",ios::in);
    int intNumber=0,cont=0;
    string caractere="", number="", tab=" ";
    int l=0, c=0, f=1;

    iniciarMatriz(matriz, tamanho);

    if(arquivo.is_open()){ 
        while(getline(arquivo,caractere)){
            for(int i=0; i<=(int)caractere.size(); i++){
                if(caractere[i]=='\0'){
                    cont++;
                }
                if(cont>=1){
                    if(caractere[i]!='\n' && caractere[i]!= '\0'){

                        if(caractere[i]!=' '){
                            number+=caractere[i];
                        }
                        else{

                            intNumber = atoi(number.c_str());
                            
                            if(matriz[l][c]==-1){
                                matriz[l][c]=intNumber;
                                c++;
                            }
                            if(c>(tamanho-1)){
                                l++;
                                c=0;
                            }

                            if(matriz[tamanho-1][tamanho-1] != -1){
                                l=0;
                                cout<<endl;

                                cout<<"\n\t----- MATRIZ ["<<f<<"] -----\n\n";

                                for(int i=0; i<tamanho; i++){
                                    for(int j=0; j<tamanho; j++){
                                        cout << matriz[i][j] << " ";
                                    }
                                    cout << endl;
                                }
                                f++;
                                andarMatriz(matriz,tamanho);
                                iniciarMatriz(matriz, tamanho);

                            }
                            number.clear();
                        }
                    }
                }                
                
            }
            
        }
        arquivo.close();
    }
    else{
        cout<<"\n[E] - ERRO - [E]";
    }

    cout<<" \nTotal dos caminhos das matrizes = "<<totalDasMatriz<<endl;
    
}

void andarMatriz(int** matriz, int tamanho){

    int nDireita=0, nEsquerda=0, nBaixo=0, nDiagDireita=0, nDiagoESquerda=0;
    int i=0,j=0,soma=0;
    
    soma+=matriz[i][j];

    while((i<tamanho) && (j<tamanho)){
        if(i<(tamanho-1)){

            nDireita = direita(matriz,i,j);
            nEsquerda = esquerda(matriz,i,j);
            nBaixo = baixo(matriz, i,j);
            nDiagDireita = diagonalDireita(matriz,i,j);
            nDiagoESquerda = diagonalEsquerda(matriz,i,j);

            if(j==0){
                if(nDireita>nDiagDireita && nDireita>nBaixo){
                    soma+=matriz[i][j+1];
                  //   cout<<"\n13 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    j++;

                    //imprimirMatriz(matriz,tamanho);
                }
                else if(nDiagDireita>=nDireita && nDiagDireita>nBaixo){
                    soma+=matriz[i+1][j+1];
                   //  cout<<"\n 12 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                     //imprimirMatriz(matriz,tamanho);

                    i++;
                    j++;
                }
                else if(nBaixo>=nDireita && nBaixo>=nDiagDireita){
                    soma+=matriz[i+1][j];
                  //   cout<<"\n 11 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                     //imprimirMatriz(matriz,tamanho);

                    i++;
                }
            }
            else if(j>0 && j<(tamanho-1)){
                nDireita = direita(matriz, i,j);
                nEsquerda = esquerda(matriz,i,j);
                nBaixo = baixo(matriz,i,j);
                nDiagDireita = diagonalDireita(matriz,i,j);
                nDiagoESquerda = diagonalEsquerda(matriz,i,j);

                if(nDireita>=nEsquerda && nDireita>nBaixo && nDireita>nDiagDireita && nDireita>=nDiagoESquerda){
                    soma+=matriz[i][j+1];
                   //  cout<<"\n 10  soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    j++;
                     //imprimirMatriz(matriz,tamanho);
                }
                else if(nEsquerda>nDireita && nEsquerda>nBaixo && nEsquerda>nDiagDireita && nEsquerda>nDiagoESquerda){
                    soma+=matriz[i][j-1];
                   //  cout<<"\n9  soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                     //imprimirMatriz(matriz,tamanho);

                    j--;
                }
                else if(nBaixo>=nDireita && nBaixo>=nEsquerda && nBaixo>=nDiagoESquerda && nBaixo>=nDiagDireita){
                    soma+=matriz[i+1][j];
                   //  cout<<"\n  8 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    // imprimirMatriz(matriz,tamanho);

                    i++;                        
                }
                else if(nDiagDireita>=nDireita && nDiagDireita>=nEsquerda && nDiagDireita>nBaixo && nDiagDireita>=nDiagoESquerda){
                    soma+=matriz[i+1][j+1];
                   //  cout<<"\n 7 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    // imprimirMatriz(matriz,tamanho);

                    i++;
                    j++;

                }
                else if(nDiagoESquerda>nDireita && nDiagoESquerda>=nEsquerda && nDiagoESquerda>nBaixo && nDiagoESquerda>nDiagDireita){
                    soma+=matriz[i+1][j-1];
                   //  cout<<"\n 6 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    // imprimirMatriz(matriz,tamanho);

                    i++;
                    j--;
                }
            }
            else if(j==(tamanho-1)){

                nDireita = direita(matriz,i,j);
                nEsquerda = esquerda(matriz,i,j);
                nBaixo = baixo(matriz,i,j);
                nDiagDireita = diagonalDireita(matriz,i,j);
                nDiagoESquerda = diagonalEsquerda(matriz,i,j);

                if(nEsquerda>nBaixo && nEsquerda>nDiagoESquerda){
                    soma+=matriz[i][j-1];
                   //  cout<<"\n 5 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                    // imprimirMatriz(matriz,tamanho);

                    j--;
                }
                else if(nDiagoESquerda>=nEsquerda && nDiagoESquerda>nBaixo){
                    soma+=matriz[i+1][j-1];
                  //   cout<<"\n 4 soma = "<<soma<<endl;
                    matriz[i][j]=-1;
                   //  imprimirMatriz(matriz,tamanho);

                    i++;
                    j--;
                }
                else if(nBaixo>=nEsquerda && nBaixo>=nDiagoESquerda){
                    soma+=matriz[i+1][j];
                   //  cout<<"\n3 soma = "<<soma<<endl;
                    matriz[i][j]=-1;

                    i++;
                }
                
            }
        }

        if(i==(tamanho-1)){

            if(j>=(tamanho-1)){
                matriz[i][j]=-1;
                imprimirMatriz(matriz,tamanho);
                cout<<"\n!) Soma do caminho: "<<soma<<endl;
                totalDasMatriz+=soma;
                soma=0;
            }
            else{

                soma+=matriz[i][j+1];
                 //cout<<"\n 1 soma = "<<soma<<endl;
                matriz[i][j]=-1;
                //cout<<"soma======"<<soma<<endl;
                //imprimirMatriz(matriz,tamanho);

            } 

            j++;
       
        }  
    }

    soma=0;
}

int direita(int** matriz, int i, int j){
    return matriz[i][j+1];
}

int esquerda(int** matriz, int i, int j){
    return matriz[i][j-1];   
}

int baixo(int** matriz, int i, int j){
    return matriz[i+1][j];
}

int diagonalDireita(int** matriz, int i, int j){
    return matriz[i+1][j+1]; 
}

int diagonalEsquerda(int** matriz, int i, int j){
    return matriz[i+1][j-1];
}

