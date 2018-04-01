#include "mult_matriz.h"

#include<math.h>

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

bool escreve_resultado(int tam, vector<double> valores, string tipo) {
	double soma = 0; // Variável usada para calcular a média depois
	double media;

	string nomeArq = "resultados/C"+to_string(tam)+"x"+to_string(tam)+"_"+tipo+".txt";
	ofstream arq (nomeArq);

	if (!arq.is_open()) {
  		cout << "Não foi possível abrir o arquivo" << endl;
  		return false;
  	}

	for (unsigned int i = 0; i < valores.size(); ++i)
	{
		soma += valores[i];
		arq << i << ". Tempo: " + to_string(valores[i]) + "\n";
	}

	media = soma/valores.size();

	double desvio_padrao;
	double variancia = 0;

	for(unsigned int i = 0; i < valores.size(); ++i) {
		variancia += pow((valores[i] - media), 2);
	}

	variancia /= valores.size();

	desvio_padrao = sqrt(variancia);


  	auto resultado = minmax_element(valores.begin(), valores.end());

  	arq << "Menor valor: " + to_string(valores[resultado.first - valores.begin()]) + " na posição " + to_string(resultado.first - valores.begin()) + "\n";
  	arq << "Maior valor: " + to_string(valores[resultado.second - valores.begin()]) + " na posição " + to_string(resultado.second - valores.begin()) + "\n";
  	arq << "Média: " + to_string(media) + "\n";
  	arq << "Desvio padrão: " + to_string(desvio_padrao) + "\n";

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
	for (int i = 0; i < tam; ++i){
		for (int j = 0; j < tam; ++j){
			int soma = 0;
			for (int k = 0; k < tam; ++k)
			{
				soma += matrizA[i][k] * matrizB[k][j];
			}
			matrizC[i][j] = soma;
		}
	}
}