#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo * siguiente;
};

void insertarCola(nodo *&, nodo *&, int);
void suprimirCola( nodo *&, nodo *&, int &);
void menu();
bool cola_vacia( nodo *&);

int main()
{
	nodo * frente = NULL;
	nodo * fin = NULL;
	nodo * frente_aux = NULL;
	nodo * fin_aux = NULL;
	int dato, opcion;
	do
	{
		menu();
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				cout<<"Ingrese el nuevo dato: ";
				cin>>dato;
				insertarCola(frente, fin, dato);
				cout<<"El dato se agrego a la cola..."<<endl;
			break;
			
			case 2:
				while(frente != NULL)
				{
					suprimirCola(frente, fin, dato);
					insertarCola(frente_aux, fin_aux, dato);
					if(frente != NULL)
					{
						cout<<dato<<", ";
					}
					else
					{
						cout<<dato<<"."<<endl;
					}
				}
				while(frente_aux != NULL)
				{
					suprimirCola(frente_aux, fin_aux, dato);
					insertarCola(frente, fin, dato);
				}
			break;
			
			case 3:
				suprimirCola(frente, fin, dato);
				cout<<"Se elimino el dato "<<dato<<" que era el frente de la cola"<<endl;
			break;
			
			case 4:
				while(frente != NULL)
				{
					suprimirCola(frente, fin, dato);
					if(frente != NULL)
					{
						cout<<dato<<", ";
					}
					else
					{
						cout<<dato<<"."<<endl;
						cout<<"Se eliminaron todos los elementos de la cola..."<<endl;
					}
				}
			break;
		}
	}while(opcion != 5);
}

void insertarCola(nodo *&frente, nodo *&fin, int n)
{
	nodo * nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	if(cola_vacia(frente)) //== true) Poner el ==true no es necesario
	{
		frente = nuevo_nodo;
	}
	else
	{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

void suprimirCola(nodo *&frente, nodo *&fin, int &n)
{
	if(cola_vacia(frente) != true)
	{
		n = frente->dato;
		nodo * aux = frente;
		if(frente == fin)
		{
			frente = NULL;
			fin = NULL;
		}
		else
		{
			frente = frente->siguiente;
		}
		delete aux;
	}
	else
	{
		cout<<"La cola esta vacia..."<<endl;
	}
}

bool cola_vacia(nodo *&frente)
{
	if(frente == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void menu()
{
	cout<<"Operaciones con colas"<<endl;
	cout<<"1. Agregar elemento a la cola"<<endl;
	cout<<"2. Imprimir los elementos de la cola"<<endl;
	cout<<"3. Eliminar el frente de la cola"<<endl;
	cout<<"4. Eliminar todos los elementos de la cola"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
}
