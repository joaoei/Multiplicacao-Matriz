#include "mult_matriz.h"
#include <stdio.h>
#include <iostream>

int main( int argc, char * argv[] ) {
	if ( argc > 2 ) { 
		string prog;
		int tam;
		stringstream( argv[1] ) >> tam;
		stringstream( argv[2] ) >> prog;

		if (num_pot2(tam) && tam != 2 && (prog == "S" || prog == "C")) {
		    vector<vector<int>> matrizA (tam, vector<int>(tam));
		    vector<vector<int>> matrizB (tam, vector<int>(tam));
		    vector<vector<int>> matrizC (tam, vector<int>(tam));

  			if (!abre_arq("A", tam, matrizA)) return 0; 
  			if (!abre_arq("B", tam, matrizB)) return 0; 
  			/*
  			for (int i = 0; i < tam; ++i)
  			{
  				for (int j = 0; j < tam; ++j)
  				{
  					cout << matrizA[i][j] << " ";
  				}
  				cout << endl;
  			}
  			cout << endl;
  			for (int i = 0; i < tam; ++i)
  			{
  				for (int j = 0; j < tam; ++j)
  				{
  					cout << matrizB[i][j] << " ";
  				}
  				cout << endl;
  			}
  			*/
			//Programa...
		} else {
			cout << tam << " não é um valor válido, tente inserir um número que é maior que 2 e potência de base 2" << endl;
			cout << "Ou" << endl;
			cout << prog << " não é uma string válida, tente inserir S para sequencial e C para concorrente" << endl;
		}
	} else {
		cout <<"Parâmetros inválidos. Entrada correta seria do tipo: ./[arquivo bin] [Numero de colunas/linhas] [S para rodar o programa sequencial ou C para rodar o programa Concorrente]" << endl;
	}
}