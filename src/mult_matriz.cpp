#include "mult_matriz.h"

/*
* FALTA FAZER:
*	- Calcular speedup (T_sequencial/T_concorrente)
	- Escrever relatório: Introdução, Metodolgia, Resultados e Conclusões. 
*/

int main( int argc, char * argv[] ) {
	vector<double> valores(20);

	if ( argc > 2 ) { 
		string prog;
		int tam;
		stringstream( argv[1] ) >> tam;
		stringstream( argv[2] ) >> prog;

		if (num_pot2(tam) && tam != 2 && (prog == "S" || prog == "C")) {
		    vector<vector<int>> matrizA (tam, vector<int>(tam));
		    vector<vector<int>> matrizB (tam, vector<int>(tam));
		    vector<vector<int>> matrizC (tam, vector<int>(tam));

  			if (!abre_arq("A", tam, matrizA) || !abre_arq("B", tam, matrizB)) {
  				cout << "Erro ao abrir arquivos" << endl;
  				exit(-1);
  			}
  			
  			if (prog == "S") {
  				for(int j = 0; j < 20; ++j) {
	  				// Iniciando contagem
	  				auto inicio = std::chrono::system_clock::now();
	  				
	  				mult_matriz_seq(matrizA, matrizB, matrizC, tam);

	  				// Finalizando contagem
					auto fim = std::chrono::system_clock::now();
					std::chrono::duration<double> tempo_decorrido = fim-inicio;
					
					// Salvando valores
					valores[j] = tempo_decorrido.count();
					escreve_resultado(tam, valores, "S");
					cout << j << ". Tempo: " << valores[j] << endl;
  				}

  				if (!escreve_arq(tam, matrizC)) {
  					cout << "Erro ao escrever arquivos" << endl;
  					exit(-1);
  				} 
  			} else {
	  				// Iniciando contagem
		  			auto inicio = std::chrono::system_clock::now();
	  				
	  				pthread_t threads[tam];
	  				struct estrutura est[tam];
					int resultado;
					void *status;
					   
					for(int i = 0; i < tam; i++ ) {
						est[i].tam = tam;
					   	est[i].linha = i;
					   	est[i].matrizA = matrizA[i];
					   	est[i].matrizB = matrizB;
					   	est[i].matrizC = (void *) &matrizC[0];
					    resultado = pthread_create(&threads[i], NULL, mult_linha_conc, (void *)&est[i]);
					      
					    if (resultado) {
					        cout << "Erro: não foi possivel criar a thread," << resultado << endl;
					        exit(-1);
					    }
					}

					for(int i = 0; i < tam; i++ ) {
					    resultado = pthread_join(threads[i], &status);
					    if (resultado) {
					        cout << "Erro: incapaz de fazer join na thread," << resultado << endl;
					        exit(-1);
					    }
					}

					// Finalizando contagem
					auto fim = std::chrono::system_clock::now();
					std::chrono::duration<double> tempo_decorrido = fim-inicio;
					cout << "Tempo: " << tempo_decorrido.count() << endl;
				}

				pthread_exit(NULL);
  				
  				if (!escreve_arq(tam, matrizC)) {
  					cout << "Erro ao escrever arquivos" << endl;
  					exit(-1);
  				}				
		} else {
			cout << tam << " não é um valor válido, tente inserir um número que é maior que 2 e potência de base 2" << endl;
			cout << "Ou" << endl;
			cout << prog << " não é uma string válida, tente inserir S para sequencial e C para concorrente" << endl;
		}
	} else {
		cout <<"Parâmetros inválidos. Entrada correta seria do tipo: ./[arquivo bin] [Numero de colunas/linhas] [S para rodar o programa sequencial ou C para rodar o programa Concorrente]" << endl;
	}
}
