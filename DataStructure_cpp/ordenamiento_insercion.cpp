#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 50

using namespace std;

int main() {
	int vect[TAM];
	int num, aux, pos;

	srand((unsigned int) time(NULL));

	for(int i = 0; i < TAM; i++) {
		vect[i] = rand() % 100 + 1;
	}

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}

	cout<<endl<<"ordenamiento por insercion"<<endl;

	for(int i = 0; i < TAM; i++) {
		pos = i;
		aux = vect[i];
		while(pos > 0 && vect[pos - 1] > aux) {
			vect[pos] = vect[pos - 1];
			pos--;
		}

		vect[pos] = aux;
	}

	cout<<endl<<"vector ordenado"<<endl;

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}
}