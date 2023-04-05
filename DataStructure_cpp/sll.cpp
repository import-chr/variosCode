#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

/* ----------------------- NODO ----------------------- */
struct nodo {
	int dato;
	nodo *siguiente;
} *primero, *ultimo;
/* ----------------------- NODO ----------------------- */

/* ----------------------- PROTOTIPOS ----------------------- */
void insertar();						//hecho
void insertar_inicio();					//hecho
void insertar_pos();					//hecho
void imprimir();						//hecho
void eliminar_primero();				//hecho
void eliminar_ultimo();					//hecho
//eliminar por posicion
void eliminar_pos();					//
//eliminar por dato
void eliminar_dt();						//

int menu();								//hecho
int contar();							//hecho

bool vacia();							//hecho
/* ----------------------- PROTOTIPOS ----------------------- */

int main() {
	int opc;

	do {
		opc = menu();

		switch(opc) {
			case 1:
				insertar();
			break;
			case 2:
				insertar_inicio();
			break;
			case 3:
				insertar_pos();
			break;
			case 4:
				imprimir();
			break;
			case 5:
				eliminar_ultimo();
			break;
			case 6:
				eliminar_primero();
			break;
			case 7:
				eliminar_pos();
			break;
			case 8:
				eliminar_dt();
			break;
		}
	} while(opc != 9);

	getch();

	return 0;
}

/* ----------------------- FUNCIONES ----------------------- */

int menu() {
	int opcion;

	cout<<"LISTAS"<<endl;
	cout<<"[1] Insertar al final"<<endl;
	cout<<"[2] Insertar al inicio"<<endl;
	cout<<"[3] Insertar en posicion"<<endl;
	cout<<"[4] Imprimir"<<endl;
	cout<<"[5] Eliminar al final"<<endl;
	cout<<"[6] Eliminar al inicio"<<endl;
	cout<<"[7] Eliminar en posicion"<<endl;
	cout<<"[8] Eliminar por dato"<<endl;
	cout<<"[9] Salir"<<endl;
	cin>>opcion;

	return opcion;
}

void insertar() {
	nodo *nuevo = new nodo();

	cout<<"Ingrese el dato: ";
	cin>>nuevo->dato;

	if(primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}

	cout<<"Nodo agregado"<<endl;
}

void imprimir() {
	nodo *actual = new nodo();

	cout<<"Elementos de la Lista: "<<endl;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			cout<<actual->dato<<endl;

			actual = actual->siguiente;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

bool vacia() {
	if(primero == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void insertar_inicio() {
	nodo *nuevo = new nodo();

	cout<<"Ingrese el dato: ";
	cin>>nuevo->dato;

	if(vacia()) {
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}
	else {
		nuevo->siguiente = primero;
		primero = nuevo;
	}
}

int contar() {
	int cantidad = 0;

	nodo *actual = new nodo();

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			cantidad++;
			actual = actual->siguiente;
		}
	}
	else {
		cantidad = 0;
	}

	return cantidad;
}

void insertar_pos() {
	int pos, cant = contar(), contador = 1;
	int pos_max = cant + 1;

	nodo *nuevo = new nodo();
	nodo *actual = new nodo();

	cout<<"Ingrese la posicion: ";
	cin>>pos;

	if(pos == 1) {
		insertar_inicio();
	}
	else {
		if(pos == pos_max) {
			insertar();
		}
		else {
			if(pos < pos_max) {
				cout<<"Ingrese el dato: ";
				cin>>nuevo->dato;

				actual = primero;

				while(actual != NULL) {
					if(contador == pos - 1) {
						nuevo->siguiente = actual->siguiente;
						actual->siguiente = nuevo;
						//break;
					}

					contador++;
					actual = actual->siguiente;
				}
			}
			else {
				cout<<"Excede la posicion"<<endl;
			}
		}
	}
}

void eliminar_primero() {
	nodo *actual = new nodo();

	if(vacia() == false) {
		if(contar() == 1) {
			primero = NULL;
			ultimo = NULL;

			cout<<"Lista actualmente vacia"<<endl;
		}
		else {
			actual = primero;
			actual = actual->siguiente;
			primero = actual;

			cout<<"Se elimino el primer nodo"<<endl;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void eliminar_ultimo() {
	int cantidad = contar();
	int contador = 1;

	nodo *actual = new nodo();

	if(vacia() == false) {
		if(cantidad == 1) {
			primero = NULL;
			ultimo = NULL;

			cout<<"Lista actualmente vacia"<<endl;
		}
		else {
			actual = primero;

			while(actual != NULL) {
				if(contador == cantidad - 1){
					actual->siguiente = NULL;
					ultimo = actual;

					cout<<"Se elimino el ultimo nodo"<<endl;
				}

				actual = actual->siguiente;
				contador++;
			}
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void eliminar_pos() {
	int pos, posAux = 1, posAct = 1;

	nodo *actual = new nodo();
	nodo * aux = new nodo();

	cout<<"Ingrese la posicion: ";
	cin>>pos;

	if(vacia() == false) {
		actual = primero;
		aux = primero;

		while(actual != NULL) {
			if(posAct == pos - 1) {
				break;
			}

			posAct++;
			actual = actual->siguiente;
		}

		while(aux != NULL) {
			if(posAux == pos) {
				break;
			}

			posAux++;
			aux = aux->siguiente;
		}

		actual->siguiente = aux->siguiente;

		cout<<"Se elimino el nodo"<<endl;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void eliminar_dt() {
	int dt, pos = 0, posAct = 0;

	nodo *actual = new nodo();
	nodo * aux = new nodo();

	cout<<"Ingrese el dato: ";
	cin>>dt;

	if(vacia() == false) {
		actual = primero;
		aux = primero;

		while(actual != NULL) {
			if(dt == actual->dato) {
				break;
			}

			posAct++;
			actual = actual->siguiente;
		}

		while(aux != NULL) {
			if(pos == posAct - 1) {
				break;
			}

			pos++;
			aux = aux->siguiente;
		}

		aux->siguiente = actual->siguiente;

		cout<<"Se elimino el nodo"<<endl;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

/* ----------------------- FUNCIONES ----------------------- */