using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void mult_matriz_seq(vector<vector<int>> matrizA, vector<vector<int>> matrizB, vector<vector<int>> &matrizC, int tam) {
	//Programa...
}

void mult_matriz_conc(vector<vector<int>> matrizA, vector<vector<int>> matrizB, vector<vector<int>> &matrizC, int tam) {
	//Programa...	
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

bool num_pot2(double num) {
	if (num <= 1) {
		if (num == 1) { return true;}
		return false;
	}
	return num_pot2(num/2);
}