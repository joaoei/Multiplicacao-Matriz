#include "mult_matriz.h"
#include <sstream>
#include <iostream>

int main( int argc, char * argv[] ) {
	if ( argc > 2 ) { 
		int tam = 8;
		string prog;
		stringstream( argv[2] ) >> prog;

		if (num_exp2(tam)) {
			cout << "Sim" << endl;
		} else {
			cout << "Nao" << endl;
		}
		//Programa...
	} else {
		cout <<"Parâmetros inválidos. Entrada correta seria do tipo: ./[arquivo bin] [Numero de colunas/linhas] [S para rodar o programa sequencial ou C para rodar o programa Concorrente]" << endl;
	}
}