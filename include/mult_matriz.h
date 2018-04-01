#ifndef MULT_MATRIZ_H
#define MULT_MATRIZ_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <pthread.h>
#include <cstdlib>
#include <chrono>

struct estrutura {
	int tam;
	int linha;
	vector<int> matrizA;
	vector<vector<int>> matrizB;
	void *matrizC;
};

void *mult_linha_conc(void *);

bool abre_arq(string, int, vector<vector<int>> &);

bool escreve_arq(int, vector<vector<int>>);

bool num_pot2(double);

void mult_matriz_seq(vector<vector<int>>, vector<vector<int>>, vector<vector<int>> &, int);

#endif