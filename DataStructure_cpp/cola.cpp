#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

nodo *frente, *fin, *cola_aux, *aux_fin;

void menu();
void encolar(nodo *&, nodo*&, int);
void imprimir(nodo *, nodo *, nodo *);
void in_pos(nodo *&, nodo *&, nodo *, nodo *);
void modificar_dato(nodo *&, nodo *&, nodo *&, int , int );

int desencolar(nodo *&, nodo *&);
int contar_nodos(nodo *);
int par(nodo *);
int impar(nodo *);

float suma(nodo *);
float promedio(nodo *);

bool vacia(nodo *);

static int op, _dato_, p;

int main() {
	do {
		menu();

		cout<<"\t----> ";
		cin>>op;

		switch(op) {
			case 1:
				cout<<"dato: ";
				cin>>_dato_;

				encolar(frente, fin, _dato_);
			break;
			case 2:
				desencolar(frente, fin);
			break;
			case 3:
				imprimir(frente, fin, cola_aux);
			break;
			case 4:
				in_pos(frente, fin, cola_aux, aux_fin);
			break;
			case 5:
				cout<<"dato a modificar: ";
				cin>>_dato_;
				cout<<"nuevo dato: ";
				cin>>p;

				modificar_dato(frente, fin, cola_aux, _dato_, p);
			break;
			case 6:
				if(vacia(frente)) {
					cout<<"la pila no contiene datos"<<endl;
				}
				else {
					cout<<"la pila contiene "<<contar_nodos(frente)<<" datos"<<endl;
				}
			break;
			case 7:
				cout<<"la cantidad de nodos en la pila es: "<<contar_nodos(frente)<<endl;
			break;
			case 8:
				cout<<"la suma de los datos pares es: "<<par(frente)<<endl;
			break;
			case 9:
				cout<<"la suma de los datos impares es: "<<impar(frente)<<endl;
			break;
			case 10:
				cout<<"el promedio de los datos es: "<<promedio(frente)<<endl;
			break;
		}
	} while(op != 11);

	return 0;
}

void menu() {
	cout<<"Colas"<<endl;
	cout<<"[1] encolar"<<endl;
	cout<<"[2] desencolar"<<endl;
	cout<<"[3] imprimir"<<endl;
	cout<<"[4] insertar en posicion"<<endl;
	cout<<"[5] modificar dato"<<endl;
	cout<<"[6] comprobar datos"<<endl;
	cout<<"[7] contar nodos"<<endl;
	cout<<"[8] sumar pares"<<endl;
	cout<<"[9] sumar impares"<<endl;
	cout<<"[10] promedio"<<endl;
	cout<<"[11] salir"<<endl;
}

bool vacia(nodo *ft) {
	return (ft == NULL) ? true : false;
}

int contar_nodos(nodo *ft) {
	int cont = 0;

	 if(!vacia(ft)) {
	 	nodo *aux = ft;

	 	while(aux != NULL) {
			cont++;
			aux = aux->sig;
		}
	}

	return cont;
}

void encolar(nodo *&ft, nodo *&fn, int dt) {
	nodo *nuevo = new nodo();

	nuevo->dato = dt;
	nuevo->sig = NULL;

	if(vacia(ft)) {
		ft = nuevo;
	}
	else {
		fn->sig = nuevo;
	}

	fn = nuevo;
}

int desencolar(nodo *&ft, nodo *&fn) {
	nodo *aux;
	int dt;

	if(!vacia(ft)) {
		dt = ft->dato;
		aux = ft;

		if(ft == fn) {
			ft = NULL;
			fn = NULL;
		}
		else {
			ft = ft->sig;
		}

		delete aux;
	}

	return dt;
}

void imprimir(nodo *ft, nodo *fn, nodo *aux) {
	if(!vacia(ft)) {
		int n;
		while(ft != NULL) {
			n = desencolar(ft, fn);
			encolar(aux, fn, n);

			cout<<n<<endl;
		}

		//regresamos a cola original
		while(aux != NULL) {
			n = desencolar(aux, fn);
			encolar(ft, fn, n);
		}
	}
}

void in_pos(nodo *&ft, nodo *&fn, nodo *aux, nodo *fn2) {
	if(!vacia(ft)) {
		int pos, dt;

		cout<<"ingrese la posicion: ";
		cin>>pos;

		for(int i = 0; i < pos; i++) {
			encolar(aux, fn2, desencolar(ft, fn));
		}

		cout<<"ingrese el dato: ";
		cin>>dt;

		encolar(aux, fn2, dt);

		while(ft != NULL) {
			encolar(aux, fn2, desencolar(ft, fn));
		}

		while(aux != NULL) {
			encolar(ft, fn, desencolar(aux, fn2));
		}
	}
}

void modificar_dato(nodo *&ft, nodo *&fn, nodo *&aux, int dt, int ndt) {
	int d;
	while(ft != NULL) {
		if(ft->dato == dt) {
			ft->dato = ndt;
		}

		d = desencolar(ft, fn);
		encolar(aux, fn, d);
	}

	while(aux != NULL) {
		encolar(ft, fn, desencolar(aux, fn));
	}
}

int par(nodo *ft) {
	int s = 0;

	if(!vacia(ft)) {
		nodo *aux = ft;

		while(aux != NULL) {
			if(aux->dato % 2 == 0) {
				s += aux->dato;
			}

			aux = aux->sig;
		}
	}

	return s;
}

int impar(nodo *ft) {
	int s = 0;

	if(!vacia(ft)) {
		nodo *aux = ft;

		while(aux != NULL) {
			if(aux->dato % 2 != 0) {
				s += aux->dato;
			}

			aux = aux->sig;
		}
	}

	return s;
}

float suma(nodo *ft) {
	float s = 0;

	if(!vacia(ft)) {
		nodo *aux = ft;

		while(aux != NULL) {
			s += aux->dato;
			aux = aux->sig;
		}
	}

	return s;
}

float promedio(nodo *ft) {
	return (suma(ft) / contar_nodos(ft));
}