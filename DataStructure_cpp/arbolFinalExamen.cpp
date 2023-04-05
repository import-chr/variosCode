#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
	char dato;
	nodo *izq;
	nodo *der;
};

nodo *arbol = NULL;

void menu();
void inserta(nodo *&, char);
void muestra(nodo *, int);
void preo(nodo *);
void ino(nodo *);
void posto(nodo *);

nodo *crear(char);
nodo *min(nodo *);
nodo *del(nodo *, char);

static int op, c;
static char ltr;

int main() {
	do {
		menu();
		cin>>op;

		switch(op) {
			case 1:
				cout<<"nuevo dato: ";
				cin>>ltr;
				inserta(arbol, ltr);
			break;
			case 2:
				muestra(arbol, c);
			break;
			case 3:
				cout<<"dato a eliminar: ";
				cin>>ltr;
				del(arbol, ltr);
			break;
			case 4:
				preo(arbol);
			break;
			case 5:
				ino(arbol);
			break;
			case 6:
				posto(arbol);
			break;
		}
	} while(op != 9);

	return 0;
}

void menu() {
	cout<<"arboles"<<endl;
	cout<<"1. insertar"<<endl;
	cout<<"2. mostrar"<<endl;
	cout<<"3. eliminar"<<endl;
	cout<<"4. preorden"<<endl;
	cout<<"5. inorden"<<endl;
	cout<<"6. postorden"<<endl;
	cout<<"9. salir"<<endl;
}

nodo *crear(char l) {
	nodo *n = new nodo();
	n->dato = l;
	n->izq = NULL;
	n->der = NULL;

	return n;
}

void inserta(nodo *&arbol, char l) {
	char v;

	if(arbol == NULL) {
		nodo *n = crear(l);
		arbol = n;
	}
	else {
		v = arbol->dato;

		if(l < v) {
			inserta(arbol->izq, l);
		}
		else if(l > v) {
			inserta(arbol->der, l);
		}
	}
}

void muestra(nodo *arbol, int cn) {
	if(arbol != NULL) {
		muestra(arbol->der, cn+1);

		for(int i = 0; i < cn; i++) {
			cout<<"   ";
		}

		cout<<arbol->dato<<endl;

		muestra(arbol->izq, cn+1);
	}
}

void preo(nodo *arbol) {
	if(arbol != NULL) {
		cout<<arbol->dato<<" - ";
		preo(arbol->izq);
		preo(arbol->der);
	}
}

void ino(nodo *arbol) {
	if(arbol != NULL) {
		ino(arbol->izq);
		cout<<arbol->dato<<" - ";
		ino(arbol->der);
	}
}

void posto(nodo *arbol) {
	if(arbol != NULL) {
		posto(arbol->izq);
		posto(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

nodo *min(nodo *arbol) {
	nodo *act = arbol;
	while(act && act->izq) {
		act = act->izq;
	}
	return act;
}

nodo *del(nodo *arbol, char l) {
	if(arbol == NULL) {
		return arbol;
	}

	if(l < arbol->dato) {
		arbol->izq = del(arbol->izq, l);
	}
	else if(l > arbol->dato) {
		arbol->der = del(arbol->der, l);
	}
	else {
		if(arbol->izq == NULL) {
			nodo *t = arbol->der;
			delete(arbol);
			return t;
		}
		else if(arbol->der == NULL) {
			nodo *t = arbol->izq;
			delete(arbol);
			return t;
		}

		nodo *t = arbol->der;
		arbol->dato = t->dato;
		arbol->der = del(arbol->der, t->dato);
	}
	return arbol;
}