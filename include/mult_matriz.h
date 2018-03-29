using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <pthread.h>

struct estrutura {
	int tam;
	int linha;
	vector<int> matrizA;
	vector<vector<int>> matrizB;
	void *matrizC;
};

void *mult_linha_conc(void *t) {
	struct estrutura *dados;
	dados = (struct estrutura *) t;
	vector<int> *linhaMatrizC;
    linhaMatrizC = (vector<int> *) dados->matrizC;

    for (int i = 0; i < dados->tam; i++) {
		int var = 0;
		for (int j = 0; j < dados->tam; j++) {
			var += dados->matrizA[j]*dados->matrizB[j][i];
		}
		linhaMatrizC[dados->linha][i] = var;
	}
	pthread_exit(NULL);
}

bool abre_arq(string letra, int tam, vector<vector<int>> &matriz) {
	string nomeArq = "matrizes/"+letra+to_string(tam)+"x"+to_string(tam)+".txt";
  	ifstream arq (nomeArq);
  	string linha;
  	if (!arq.is_open()) {
  		cout << "Não foi possível abrir o arquivo" << endl;
  		return false;
  	}
  	
  	int i = 0;
  	int subs;
  	getline(arq, linha);
  	while(getline(arq, linha)){
  		istringstream iss (linha);
  		for (int j = 0; j < tam; j++) {
			iss >> subs;
			matriz[i][j] = subs;
  		}
  		i++;
  	}
	return true;
}

bool escreve_arq(int tam, vector<vector<int>> matriz) {
	string nomeArq = "matrizes/C"+to_string(tam)+"x"+to_string(tam)+".txt";
	ofstream arq (nomeArq);
	if (!arq.is_open()) {
  		cout << "Não foi possível abrir o arquivo" << endl;
  		return false;
  	}
  	string l = ""; 
	arq << to_string(tam)+" "+to_string(tam)+"\n";
	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam; ++j)
		{
			l += to_string(matriz[i][j])+" ";
		} 
		arq << l;
		arq << "\n";
		l = "";
	}
	arq.close();
	return true;
}

bool num_pot2(double num) {
	if (num <= 1) {
		if (num == 1) { return true;}
		return false;
	}
	return num_pot2(num/2);
}

void mult_matriz_seq(vector<vector<int>> matrizA, vector<vector<int>> matrizB, vector<vector<int>> &matrizC, int tam) {
	//Programa...
}