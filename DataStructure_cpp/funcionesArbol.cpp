#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
	nodo *padre;
};

void menu();
void insertarNodo(nodo *&, int, nodo *);
void mostrarArbol (nodo *&, int);
void preOrden(nodo *);
void inOrden(nodo *);
void eliminarNodo_(nodo *);
void imprimirH(nodo *);
void imprimir_H(nodo *);
void borrarImpar(nodo *);
void postOrden(nodo *);
void eliminar(nodo *, int);
void eliminarNodo(nodo *);
void cambiarDato(nodo *, nodo *);

float promedio(nodo *);

int contar(nodo *);
int suma(nodo *);
int sumaPar(nodo *, int &);
int sumaImpar(nodo *, int &);
int datosImpar(nodo *);

bool bImpar(nodo *);
bool buscar(nodo *, int);


nodo *crearNodo(int, nodo *);
nodo *menor(nodo *);

nodo *arbol = NULL;

static int opcion, num, contador,sum = 0,nPar;

int main() {
	do {
		menu();

		cin>>opcion;

		switch(opcion) {
			case 1:
				cout<<"Ingrese el dato: ";
				cin>>num;

				insertarNodo(arbol, num, NULL);
			break;
			case 2:
				contador = 0;
				mostrarArbol(arbol, contador);
			break;
			case 3:
				cout<<"Ingrese el dato a buscar: ";
				cin>>num;

				if(buscar(arbol, num)) {
					cout<<"El numero "<<num<<" se encuentra en el arbol"<<endl;
				}
				else {
					cout<<"El numero "<<num<<" NO se encuentra en el arbol"<<endl;
				}
			break;
			case 4:
				cout<<"PreOrden"<<endl;

				preOrden(arbol);
			break;
			case 5:
				cout<<"InOrden"<<endl;

				inOrden(arbol);
			break;
			case 6:
				cout<<"PostOrden"<<endl;

				postOrden(arbol);
			break;
			case 7:
				cout<<"Ingrese el dato a eliminar: ";
				cin>>num;

				eliminar(arbol, num);
			break;
			case 8:
				cout<<"hojas de arbol son..."<<endl;

				imprimirH(arbol);

				cout<<endl;
			break;
			case 9:
				cout<<"datos no clasificados como hojas..."<<endl;

				imprimir_H(arbol);

				cout<<endl;
			break;
				case 10:
				cout<<"El promedio de datos en el arbol es: "<<promedio(arbol)<<endl;
			break;
			case 11:
			    cout<<"El resultado de suma de los pares es: "<<sumaPar(arbol,sum)<<endl;
			    sum = 0;
			break;	
			case 12:
			    cout<<"El resultado de suma de los impares es: "<<sumaImpar(arbol,sum)<<endl;
			    sum = 0;
			break;
			case 13:
			    while(bImpar(arbol)) {
			    	borrarImpar(arbol);
				}
			break;
			case 14:
				cout<<"La suma de datos en el arbol es: "<<suma(arbol)<<endl;
			break;
			case 15:
				cout<<"La cantidad de datos en arbol es: "<<contar(arbol)<<endl;
			break;
		}
	}while(opcion != 16);
}

void menu() {
	cout<<"--- Arboles ---"<<endl;
	cout<<"[1] Insertar un nuevo nodo"<<endl;
	cout<<"[2] Mostrar todo el arbol"<<endl;
	cout<<"[3] Buscar un dato en el arbol"<<endl;
	cout<<"[4] Recorrido preOrden"<<endl;
	cout<<"[5] Recorrido inOrden"<<endl;
	cout<<"[6] Recorrido postOrden"<<endl;
	cout<<"[7] Eliminar un nodo"<<endl;
	cout<<"[8] Imprimir hojas"<<endl;
	cout<<"[9] Imprimir todo menos hojas"<<endl;
	cout<<"[10] Promedio"<<endl;
	cout<<"[11] Suma de pares"<<endl;
	cout<<"[12] Suma de impares"<<endl;
	cout<<"[13] Borrar impares"<<endl;
	cout<<"[14] Suma datos"<<endl;
	cout<<"[15] Cantidad de nodos en arbol"<<endl;
	cout<<"[16] Salir"<<endl;
	cout<<"Ingrese una opcion: ";
}

nodo *crearNodo (int n, nodo *padre) {
	nodo * nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}

void insertarNodo(nodo *&arbol, int n, nodo *padre) {
	int ValorRaiz;
	if(arbol == NULL) {
		nodo * nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else {
		ValorRaiz = arbol->dato;
		if(n < ValorRaiz) {
			insertarNodo(arbol->izq, n, arbol);
		}
		else {
			if(n > ValorRaiz) {
				insertarNodo(arbol->der, n, arbol);
			}
		}
	}
}

void mostrarArbol(nodo *&arbol, int contador) {
	if(arbol != NULL) {
		mostrarArbol(arbol->der, contador+1);
		for(int i = 0; i < contador; i++) {
			cout<<"   ";
		}

		cout<<arbol->dato<<endl;

		mostrarArbol(arbol->izq, contador+1);
	}
	else {
		return;
	}
}

void imprimirH(nodo *arbol) {
    if(!arbol)
        return;

    if(!arbol->izq && !arbol->der) {
        cout << arbol->dato << "  "; 
        return;
    }

    if(arbol->izq)
       imprimirH(arbol->izq);

    if(arbol->der)
       imprimirH(arbol->der);
} 

void imprimir_H(nodo *arbol) {
    if (!arbol)
        return;
    if (arbol->izq  || arbol->der) {
    	imprimir_H(arbol->izq);
    	cout << arbol->dato << "  "; 
    	imprimir_H(arbol->der);
        return;
    }
} 


bool buscar(nodo *arbol, int n) {
	if(arbol != NULL) {
		if(arbol->dato == n) {
			return true;
		}
		else {
			if(n < arbol->dato) {
				return buscar(arbol->izq, n);
			}
			else {
				return buscar(arbol->der, n);
			}
		}
	}
	else {
		return false;
	}
}

void preOrden(nodo *arbol) {
	if(arbol != NULL) {
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
	else {
		return;
	}
}

void inOrden(nodo *arbol) {
	if(arbol != NULL) {
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
	else {
		return;
	}
}

void postOrden(nodo *arbol) {
	if(arbol != NULL) {
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
	else {
		return;
	}
}

void eliminar(nodo *arbol, int n) {
	if(arbol != NULL) {
		if(n < arbol->dato) {
			eliminar(arbol->izq, n);
		}
		else {
			if(n > arbol->dato) {
				eliminar(arbol->der, n);
			}
			else {
				eliminarNodo(arbol);
			}
		}
	}
	else {
		return;
	}
}

nodo *menor(nodo *arbol) {
	if(arbol != NULL) {
		if(arbol->izq) {
			return menor(arbol->izq);
		}
		else {
			return arbol;
		}
	}
	else {
		return NULL;
	}
}

void cambiarDato(nodo *arbol, nodo *nuevoNodo) {
	if(arbol->padre) {
		if(arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = nuevoNodo;
		}
	}

	if(nuevoNodo) {
		nuevoNodo->padre = arbol->padre;
	}
}

float promedio(nodo *arbol) {
	if(arbol != NULL) {
		float sum = suma(arbol);
		float cantidad = contar(arbol);
		float prom = sum / cantidad;
		return prom;
	}
}

int contar(nodo *arbol) {
	int c = 1;
	if(arbol==NULL){
		return 0;
	}
	else {
		c += contar(arbol->izq);
		c += contar(arbol->der);
		return c;
	}
}

int suma(nodo *arbol) {
	if(arbol != NULL) {
		int s1 = suma(arbol->izq);
		int s2 = suma(arbol->der) + arbol->dato;
		return (s1 + s2);
	}
	else {
		return 0;
	}
}

void eliminarNodo_(nodo *nodo_borrar) {
	nodo_borrar->izq = NULL;
	nodo_borrar->der = NULL;
	delete nodo_borrar;
}

void eliminarNodo(nodo *nodoEliminar) {
	if(nodoEliminar->izq && nodoEliminar->der) {
		nodo *men = menor(nodoEliminar->der);
		nodoEliminar->dato = men->dato;
		eliminarNodo(men);
	}
	else if(nodoEliminar->izq) {
		cambiarDato(nodoEliminar, nodoEliminar->izq);
		eliminarNodo(nodoEliminar);
	}
	else if(nodoEliminar->der) {
		cambiarDato(nodoEliminar, nodoEliminar->der);
		eliminarNodo(nodoEliminar);
	}
	else {
		cambiarDato(nodoEliminar, NULL);
		eliminarNodo(nodoEliminar);
	}
}

int sumaPar(nodo *arbol, int &suma) {
	if(arbol != NULL) {
		sumaPar(arbol->izq, suma);
		if(arbol->dato % 2 == 0) {
			cout<<arbol->dato<<" - ";
			suma = suma + arbol->dato;	
		}
		sumaPar(arbol->der, suma);
	}
	return suma;
}
int sumaImpar(nodo *arbol, int &suma) {
	if(arbol != NULL) {
		sumaImpar(arbol->izq, suma);
		if(arbol->dato % 2 != 0) {
			cout<<arbol->dato<<" - ";
			suma = suma + arbol->dato;	
		}
		sumaImpar(arbol->der, suma);
	}
	return suma;
}

void borrarImpar(nodo *arbol) {
	if(arbol != NULL) {
		int par = datosImpar(arbol);
		eliminar(arbol, par);
	}
}

bool bImpar(nodo *arbol) {
	if(arbol != NULL) {
		bImpar(arbol->izq);
		if(arbol->dato % 2 == 0) {
			return true;	
		}
		bImpar(arbol->der);
	}
	else {
		return false;
	}
}

int datosImpar(nodo *arbol) {
	if(arbol != NULL) {
		datosImpar(arbol->izq);
		if(arbol->dato % 2 != 0) {
			return arbol->dato;	
		}
		datosImpar(arbol->der);
	}
}