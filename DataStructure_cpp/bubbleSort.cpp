#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 50

using namespace std;

int main() {
	int vect[TAM];
	int num, aux;

	srand((unsigned int) time(NULL));

	for(int i = 0; i < TAM; i++) {
		vect[i] = rand() % 100 + 1;
	}

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}

	cout<<endl<<"ordenamiento burbuja"<<endl;

	for(int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			if(vect[j] > vect[j + 1]) {
				aux = vect[j];
				vect[j] = vect[j + 1];
				vect[j + 1] = aux;
			}
		}
	}

	cout<<endl<<"vector ordenado"<<endl;

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}
}