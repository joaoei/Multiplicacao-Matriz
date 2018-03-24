using namespace std;
#include <vector>

void mult_matriz_seq(vector<vector<int>> matrizA, vector<vector<int>> matrizB, vector<vector<int>> &matrizC, int tam) {
	//Programa...
}

void mult_matriz_conc(vector<vector<int>> matrizA, vector<vector<int>> matrizB, vector<vector<int>> &matrizC, int tam) {
	//Programa...	
}

bool num_exp2(double num) {
	if (num <= 1) {
		if (num == 1) { return true;}
		return false;
	}
	return num_exp2(num/2);
}