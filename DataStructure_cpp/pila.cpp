#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

void menu();
void push(nodo *&, int);
void imprimir(nodo *);
void imprimir2(nodo *, nodo *);
void del_pila(nodo *&);
void voltear(nodo *&, nodo *);
void modificar(nodo *&);
void push_pos(nodo *&, nodo *, int);

int pop(nodo *&);
int contar_nodos(nodo *);
int pares(nodo *);

bool vacia(nodo *, bool);

static int op, dato_;
static bool bandera;
static nodo *stack = NULL, *aux_stack;

int main() {
	do {
		menu();

		cout<<"	---> ";
		cin>>op;

		switch(op) {
			case 1:
				system("cls");

				cout<<"dato: ";
				cin>>dato_;

				push(stack, dato_);
			break;
			case 2:
				pop(stack);
			break;
			case 3:
				imprimir(stack);
				cout<<"f2"<<endl;
				imprimir2(stack, aux_stack);
			break;
			case 4:
				voltear(stack, aux_stack);
			break;
			case 5:
				modificar(stack);
			break;
			case 6:
				push_pos(stack, aux_stack, dato_);
			break;
			case 7:
				if(vacia(stack, bandera)) {
					cout<<"la pila no contiene datos"<<endl;
				}
				else {
					cout<<"la pila contiene "<<contar_nodos(stack)<<" datos"<<endl;
				}
			break;
			case 8:
				cout<<"la suma de los pares: "<<pares(stack)<<endl;
			break;
			case 9:
				cout<<"la cantidad de nodos en la pila es: "<<contar_nodos(stack)<<endl;
			break;
			case 10:
				del_pila(stack);
			break;
		}
	} while(op != 11);

	return 0;
}

void menu() {
	cout<<"[1] push"<<endl;
	cout<<"[2] pop"<<endl;
	cout<<"[3] imprimir"<<endl;
	cout<<"[4] voltear"<<endl;
	cout<<"[5] modificar dato"<<endl;
	cout<<"[6] push posicion"<<endl;
	cout<<"[7] comprobar datos"<<endl;
	cout<<"[8] sumar pares"<<endl;
	cout<<"[9] contar nodos"<<endl;
	cout<<"[10] destruir pila"<<endl;
}

bool vacia(nodo *pila, bool b) {
	pila == NULL ? b = true : b = false;

	return b;
}

void push(nodo *&pila, int dt) {
	nodo *nuevo = new nodo();
	nuevo->dato = dt;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(nodo *&pila) {
	int num;
	nodo *aux = pila;
	num = aux->dato;
	pila = pila->sig;

	delete(aux);
	return num;
}

void imprimir(nodo *pila) {
	if(!vacia(pila, bandera)) {
		nodo *aux = pila;

		while(aux != NULL) {
			cout<<aux->dato<<endl;

			aux = aux->sig;
		}
	}
}

void imprimir2(nodo *pila, nodo *pilaA) {
	int d;

	if(!vacia(pila, bandera)) {
		while(pila != NULL) {
			d = pop(pila);
			push(pilaA, d);

			cout<<d<<endl;
		}

		while(pilaA != NULL) {
			push(pila, pop(pilaA));
		}
	}
}

void del_pila(nodo *&pila) {
	if(!vacia(pila, bandera)) {
		nodo *aux = pila;

		while(aux != NULL) {
			aux = aux->sig;

			delete(aux);
		}
	}
}

int contar_nodos(nodo *pila) {
	int cont = 0;

	if(!vacia(pila, bandera)) {
		nodo *aux = pila;

		while(aux != NULL) {
			cont++;
			aux = aux->sig;
		}
	}

	return cont;
}

void modificar(nodo *&pila) {
	nodo *aux = pila;
	int dt, dt_;

	cout<<"ingrese el dato a modificar: ";
	cin>>dt;
	cout<<"ingrese el nuevo dato: ";
	cin>>dt_;

	while(aux != NULL) {
		if(aux->dato == dt) {
			aux->dato = dt_;
			break;
		}
		aux = aux->sig;
	}
}

void voltear(nodo *&pila, nodo *pilaAux) {
	int i;

	while(pila != NULL) {
		i = pop(pila);
		push(pilaAux, i);
	}

	pila = pilaAux;

	cout<<"volteado..."<<endl;
}

void push_pos(nodo *&pila, nodo *pilaAux, int dt) {
	int pos_;
	cout<<"ingere posicion: ";
	cin>>pos_;

	for(int i = 0; i < pos_; i++) {
		push(pilaAux, pop(pila));
	}

	cout<<"nuevo dato: ";
	cin>>dt;

	push(pila, dt);

	for(int i = 0; i < pos_; i++) {
		push(pila, pop(pilaAux));
	}
}

int pares(nodo *pila) {
	int s = 0;

	while(pila != NULL) {
		if(pila->dato % 2 ==0) {
			s += pila->dato;
		}
		
		pila = pila->sig;
	}

	return s;
}