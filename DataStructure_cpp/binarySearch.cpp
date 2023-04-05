#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 100

using namespace std;

int main() {
	int vect[TAM];
	int ini = 0, fin = TAM - 1, mitad, num;

	srand((unsigned int) time(NULL));

	for(int i = 0; i < TAM; i++) {
		//vect[i] = rand() % 100 + 1;
		vect[i] = i + 1;
	}

	for(int i = 0; i < TAM; i++) {
		cout<<vect[i]<<" ";
	}

	cout<<endl<<"numero a buscar: ";
	cin>>num;

	mitad = (ini + fin) / 2;

	while(ini <= fin && vect[mitad] != num) {
		if(num < vect[mitad]) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}

		mitad = (ini + fin) / 2;
	}

	if(num == vect[mitad]) {
		cout<<"el numero esta en la posicion "<<mitad<<endl;
	}
	else {
		cout<<"el numero no esta en la lista..."<<endl;
	}
}