#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 50

using namespace std;

int main() {
	int vect[TAM];
	int num, aux, min;

	srand((unsigned int) time(NULL));

	for(int i = 0; i < TAM; i++) {
		vect[i] = rand() % 100 + 1;
	}

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}

	cout<<endl<<"ordenamiento por seleccion"<<endl;

	for(int i = 0; i < TAM; i++) {
		min = i;

		for(int j = i + 1; j < TAM; j++) {
			if(vect[j] < vect[min]) {
				min = j;
			}
		}

		aux = vect[i];
		vect[i] = vect[min];
		vect[min] = aux;
	}

	cout<<endl<<"vector ordenado"<<endl;

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}
}