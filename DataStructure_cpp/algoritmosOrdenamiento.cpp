#include <iostream>
#include <stdlib.h>
#include <time.h>

struct nodo {
	int dato;
	nodo *sig;
} *primero, *ultimo, *i, *j;

using namespace std;

void menu();
void insertarNodo();
void llenarLista(int);
void imprimirLista();
void burbuja();
void insercion();
void seleccion(nodo *&);
void nodoSig(nodo *, int);
void quickSort(nodo ** );
void QuickSort();
void Agregar(nodo ** , int);
void Imprimir(nodo *);
void bSecuencial();
void bBinaria();

nodo *obtenerDato(nodo *);
nodo *mitad(nodo *, nodo *, nodo **, nodo **);
nodo *quickSortRecursivo(nodo *, nodo *);

int generarAleatorio();
int contar(nodo *);

bool vacia();

static int op, cant;

int main() {
	srand(time(NULL));

	do {
		menu();

		cin>>op;

		switch(op) {
			case 1:
				cout<<"ingrese la cantidad de datos: ";
				cin>>cant;

				llenarLista(cant);
			break;
			case 2:
				burbuja();
			break;
			case 3:
				insercion();
			break;
			case 4:
				seleccion(primero);
			break;
			case 5:
				QuickSort();
			break;
			case 6:
				imprimirLista();
				cout<<endl;
			break;
			case 7:
				bSecuencial();
			break;
			case 8:
				bBinaria();
			break;
		}
	} while(op != 9);

	return 0;
}

void menu() {
	cout<<"ALGORITMOS DE ORDENAMIENTO"<<endl;
	cout<<"[1] Cantidad de datos"<<endl;
	cout<<"[2] Burbuja"<<endl;						//done
	cout<<"[3] Insercion"<<endl;					//done
	cout<<"[4] Seleccion"<<endl;					//done
	cout<<"[5] QuickSort"<<endl;					//done
	cout<<"[6] Imprimir"<<endl;						//done
	cout<<"[7] Busqueda secuencial"<<endl;			//done
	cout<<"[8] Busqueda binaria"<<endl;				//done
	cout<<"[9] Salir"<<endl;
}

int generarAleatorio() {
	int num = 1 + rand() % (101 - 1);

	return num;
}

bool vacia() {
	bool ans;

	primero == NULL ? ans = true : ans = false;

	return ans;
}

void insertarNodo() {
	nodo *nuevo = new nodo();

	nuevo->dato = generarAleatorio();

	if(primero == NULL) {
		primero = nuevo;
		primero->sig = NULL;
		ultimo = nuevo;
	}
	else {
		ultimo->sig = nuevo;
		nuevo->sig = NULL;
		ultimo = nuevo;
	}
}

void llenarLista(int cant) {
	for(int i = 0; i < cant; i++) {
		insertarNodo();
	}
}

void imprimirLista() {
	nodo *actual = new nodo();

	cout<<"Elementos de la Lista: "<<endl;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			if(actual->sig == NULL) {
				cout<<actual->dato<<endl;
			}
			else {
				cout<<actual->dato<<", ";
			}
			actual = actual->sig;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

/* -------------------- burbuja -------------------- */
void burbuja() {
	nodo *actual, *aux;
	int t;
	actual = primero;

	while(actual->sig != NULL) {
		aux = actual->sig;

		while(aux != NULL) {
			if(actual->dato > aux->dato) {
				t = aux->dato;
				aux->dato = actual->dato;
				actual->dato = t;
			}
			aux = aux->sig;
		}
		actual = actual->sig;
		aux = actual->sig;
	}
}

int contar(nodo *list) {
	int cantidad = 0;
	if(!vacia()) {
		while(list != NULL) {
			cantidad++;
			list = list->sig;
		}
	}
	else {
		cantidad = 0;
	}
	return cantidad;
}

/* -------------------- insercion -------------------- */
void insercion() {
	nodo *actual = primero;
	int temp;
	for(i = actual; i->sig != NULL; i = i->sig) {
		for(j = i->sig; j != NULL; j = j->sig) {
			if(i->dato > j->dato) {
				temp = i->dato;
				i->dato = j->dato;
				j->dato = temp;
			}
		}
	}
}

/* -------------------- seleccion -------------------- */
void seleccion(nodo *&lista) {

	nodo *actual, *siguiente;
	int t;
	actual = lista; int minimo;
	nodo *min = lista;

	while(actual->sig != NULL) {
		minimo = actual->dato;
		min = actual;
		siguiente = actual->sig;

		while(siguiente != NULL) {
			if(siguiente->dato < minimo) {
				minimo = siguiente->dato;
				min = siguiente;
			}
			siguiente = siguiente->sig;
		}
		t = actual->dato;
		actual->dato = min->dato;
		min->dato = t;
		actual = actual->sig;
	}
}

/* -------------------- quicksort -------------------- */
void QuickSort() {
	nodo *a = NULL;
    int cantidad, n;
    cout<<"ingrese cuanto datos quiere en la lista"<<endl;
    cin>>cantidad;
    srand((unsigned int) time(NULL));
        for(int i = 0; i < cantidad; i++){
            n = rand() % (100 + 1); 
            Agregar(&a, n);
            } 
    cout<<"Datos de la lista \n";
    Imprimir(a);
 
    quickSort(&a);
 
    cout<<"\nLista ordenada..."<<endl;
    Imprimir(a);
}


nodo *obtenerDato(nodo *actual)
{
    while (actual != NULL && actual->sig != NULL)
        actual = actual->sig;
    return actual;
}
 
nodo *mitad(nodo *inicio, nodo *fin, nodo **nuevoInicio, nodo **nuevoFin)
{
    nodo *pivote = fin;
    nodo *previo = NULL, *actual = inicio, *lista = pivote;
    while (actual != pivote) {
        if (actual->dato < pivote->dato) {
            if ((*nuevoInicio) == NULL)
                (*nuevoInicio) = actual;
            previo = actual;
            actual = actual->sig;
        }
        else 
        {
            if (previo)
                previo->sig = actual->sig;
            nodo* temporal = actual->sig;
            actual->sig = NULL;
            lista->sig = actual;
            lista = actual;
            actual = temporal;
        }
    }
    if ((*nuevoInicio) == NULL)
        *nuevoInicio = pivote;
    *nuevoFin = lista;
    return pivote;
}
nodo* quickSortRecursivo(nodo* inicio, nodo* fin)
{
    if (!inicio || inicio == fin)
        return inicio;
    nodo *nuevoInicio = NULL, *nuevoFin = NULL;
    nodo* pivote = mitad(inicio, fin, &nuevoInicio, &nuevoFin);
    if (nuevoInicio != pivote) {
        nodo* temporal = nuevoInicio;
        while (temporal->sig != pivote)
            temporal = temporal->sig;
        temporal->sig = NULL;
        nuevoInicio = quickSortRecursivo(nuevoInicio, temporal);
        temporal = obtenerDato(nuevoInicio);
        temporal->sig = pivote;
    }
    pivote->sig = quickSortRecursivo(pivote->sig, nuevoFin);
    return nuevoInicio;
}
void quickSort(nodo** actual)
{
    *actual = quickSortRecursivo(*actual, obtenerDato(*actual));
    return;
}

void Agregar(nodo** lista, int dato)
{
    nodo* nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = (*lista);
    (*lista) = nuevo;
}
 
void Imprimir(nodo* nodo)
{
    while (nodo != NULL) {
        cout<<nodo->dato<<" ";
        nodo = nodo->sig;
    }
    cout<<endl;;
}

/* -------------------- secuencial -------------------- */
void bSecuencial() {
	nodo *actual = primero;
	cout<<"Ingrese un dato a buscar: "<<endl;
	int n;
	bool encontrado = false;
	cin>>n;
	while(actual->sig != NULL) {
		if(actual->dato == n) {
			encontrado = true;
		}
		actual = actual->sig;
	}
	if(encontrado == true) {
		cout<<"Dato encontrado en la lista"<<endl;
	}
	else {
		cout<<"Dato no encontrado en la lista "<<endl;
	}
}

/* -------------------- binaria -------------------- */
void bBinaria() {
	nodo *actual = primero;
	int ini = 0, fin = contar(primero) - 1, mitad, num;
	burbuja();
	cout<<endl<<"numero a buscar: ";
	cin>>num;

	mitad = (ini + fin) / 2;

	while(ini <= fin && actual->dato != num) {
		if(num < actual->dato) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}

		mitad = (ini + fin) / 2;
	}

	if(num == actual->dato) {
		cout<<"el numero esta en la posicion "<<mitad<<endl;
	}
	else {
		cout<<"el numero no esta en la lista..."<<endl;
	}
}