#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

struct nodo {
	int dato;
	nodo *anterior;
	nodo *siguiente;
} *primero, *ultimo;

void menu();										//md_menudone ..................................................... done
void insertar_inicio(int &);						//inserta dato al inicio .......................................... done
void insertar_final(int &);							//inserta dato al final ........................................... done
void imprimir_inicio();								//imprime desde el inicio ......................................... done
void imprimir_final();								//imprime desde el final .......................................... done
void insertar_posicion_0(int, int &);				//inserta dato en posicion indicada parando en la misma ........... done
void insertar_posicion_1(int, int &);				//inserta dato en posicion indicada parando una antes ............. done
void modificar_dato(int, int);						//modifica nodo por dato .......................................... done
void modificar_posicion(int, int);					//modifica nodo por posicion ...................................... done
void eliminar_primero(bool &, int &);				//elimina primer nodo de la lista ................................. done
void eliminar_ultimo(bool &, int &);				//elimina ultimo nodo de la lista ................................. done
void eliminar_dato(int, int &);						//elimina nodo por dato ........................................... done
void eliminar_posicion(int, int &);					//elimina nodo por posicion ....................................... done
void mayor_menor();									//imprime dato mayor y menor ...................................... done
void eliminar_dtxdt();								//elimina dato por dato y los imprime ............................. done

bool vacia();										//retorna estado de la lista ...................................... done
bool buscar_dato(int);								//busca nodo por dato ............................................. done

float promedio();									//promedio de datos en la lista ................................... done

int contar(int &);									//cuenta nodos de la lista ........................................ done
int suma_pares();									//suma datos pares en la lista .................................... done
int suma_impares();									//suma datos impares en la lista .................................. done
int suma_dt();										//suma todos los datos ............................................ done

int opcion;
int cantidad_datos = 0, posicion, dato_0, dato_1;
int contador_actual = 0, contador_antes = 0, contador_despues = 0;
int c_dt;

bool bandera, bandera_nodo_eliminado;

int main() {
	do {
		//system("cls");
		//system("pause");

		menu();

		cout<<endl<<"datos en lista: "<<cantidad_datos<<endl;

		cin>>opcion;

		switch(opcion) {
			case 1:
				insertar_final(cantidad_datos);
				//contar(cantidad_datos);
			break;
			case 2:
				insertar_inicio(cantidad_datos);
				//contar(cantidad_datos);
			break;
			case 3:
				system("cls");

				imprimir_inicio();
			break;
			case 4:
				system("cls");

				imprimir_final();
			break;
			case 5:
				system("cls");

				insertar_posicion_0(posicion, cantidad_datos);
				//contar(cantidad_datos);
			break;
			case 6:
				system("cls");

				insertar_posicion_1(posicion, cantidad_datos);
				//contar(cantidad_datos);
			break;
			case 7:
				system("cls");

				cout<<"Ingrese el dato a buscar: ";
				cin>>dato_0;

				buscar_dato(dato_0);
			break;
			case 8:
				system("cls");

				modificar_dato(dato_0, dato_1);
			break;
			case 9:
				system("cls");

				modificar_posicion(dato_0, dato_1);
			break;
			case 10:
				system("cls");

				eliminar_primero(bandera_nodo_eliminado, cantidad_datos);

				if(bandera_nodo_eliminado) {
					cout<<"Primer nodo eliminado"<<endl;
				}
			break;
			case 11:
				system("cls");

				eliminar_ultimo(bandera_nodo_eliminado, cantidad_datos);

				if(bandera_nodo_eliminado) {
					cout<<"Ultimo nodo eliminado"<<endl;
				}
			break;
			case 12:
				system("cls");

				eliminar_dato(dato_0, cantidad_datos);
			break;
			case 13:
				system("cls");

				eliminar_posicion(dato_0, cantidad_datos);
			break;
			case 14:
				system("cls");

				cout<<"promedio de los datos: "<<promedio()<<endl;
			break;
			case 15:
				system("cls");

				cout<<"suma de pares: "<<suma_pares()<<endl;
			break;
			case 16:
				system("cls");

				cout<<"suma de impares: "<<suma_impares()<<endl;
			break;
			case 17:
				system("cls");

				mayor_menor();
			break;
			case 18:
				system("cls");

				eliminar_dtxdt();
			break;
			case 19:
				system("cls");

				cout<<"Suma total: "<<suma_dt()<<endl;
			break;
		}

		//system("cls");
		system("pause");
	} while(opcion != 20);

	//getch();

	return 0;
}

//menu
void menu() {
	cout<<"Listas Dobles"<<endl;
	cout<<"[1] Insertar al final"<<endl;
	cout<<"[2] Insertar al inicio"<<endl;
	cout<<"[3] Imprimir al inicio"<<endl;
	cout<<"[4] Imprimir al final"<<endl;
	cout<<"[5] Insertar en posicion parando en la misma posicion"<<endl;
	cout<<"[6] Insertar en posicion parando una posicion antes"<<endl;
	cout<<"[7] Buscar dato"<<endl;
	cout<<"[8] Modificar por dato"<<endl;
	cout<<"[9] Modificar por posicion"<<endl;
	cout<<"[10] Eliminar el primero"<<endl;
	cout<<"[11] Eliminar el ultimo"<<endl;
	cout<<"[12] Eliminar por dato"<<endl;
	cout<<"[13] Eliminar por posicion"<<endl;
	cout<<"[14] Promedio de los datos"<<endl;
	cout<<"[15] Suma de los pares"<<endl;
	cout<<"[16] Suma de los impares"<<endl;
	cout<<"[17] Mayor y menor"<<endl;
	cout<<"[18] Eliminar dato por dato"<<endl;
	cout<<"[19] Suma de datos"<<endl;
	cout<<"[20] Salir"<<endl;
	cout<<"	--->";
}

//retorna lista vacia
bool vacia() {
	if(primero == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//imprime desde el inicio
void imprimir_inicio() {
	cout<<"Imprimir del primero al ultimo"<<endl;

	nodo *actual = new nodo();

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

//imprime desde el final
void imprimir_final() {
	cout<<"Imprimir del ultimo al primero"<<endl;

	nodo *actual = new nodo();

	if(vacia() == false) {
		actual = ultimo;

		while(actual != NULL) {
			cout<<actual->dato<<endl;

			actual = actual->anterior;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

//inserta nodo al final
void insertar_final(int &c) {
	nodo *nuevo = new nodo();

	cout<<"Ingrese el nuevo dato: ";
	cin>>nuevo->dato;

	if(vacia()) {
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = nuevo;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = ultimo;
		ultimo = nuevo;
	}

	c += 1;
}

//inserta nodo al inicio 
void insertar_inicio(int &c) {
	nodo *nuevo = new nodo();

	cout<<"Ingrese el nuevo dato: ";
	cin>>nuevo->dato;

	if(vacia()) {
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = nuevo;
	}
	else {
		primero->anterior = nuevo;
		nuevo->siguiente = primero;
		nuevo->anterior = NULL;
		primero = nuevo;
	}

	c += 1;
}

//cuenta cantidad de nodos en la lista
int contar(int &c) {
	nodo *actual = new nodo();

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			c += 1;
			actual = actual->siguiente;
		}
	}
	else {
		c = 0;
	}

	return c;
}

//inserta en posicion parando en la misma
void insertar_posicion_0(int pos, int &c) {
	nodo *nuevo = new nodo();
	nodo *actual = new nodo();
	nodo *antes = new nodo();

	contador_actual = 0;
	contador_antes = 0;

	if(vacia() == false) {
		actual = primero;
		antes = primero;

		cout<<"Ingrese la posicion: ";
		cin>>pos;
		cout<<"Ingrese el dato: ";
		cin>>nuevo->dato;

		while(actual != NULL && pos < cantidad_datos) {
			actual = actual->siguiente;
			contador_actual++;

			if(contador_actual == pos) {
				break;
			}
		}

		while(antes != NULL) {
			antes = antes->siguiente;
			contador_antes++;

			if(contador_antes == pos - 1) {
				break;
			}
		}

		nuevo->anterior = actual->anterior;
		nuevo->siguiente = actual;
		antes->siguiente = nuevo;
		actual->anterior = nuevo;
		c += 1;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

//inserta en posicion parando una posicion antes
void insertar_posicion_1(int pos, int &c) {
	nodo *nuevo = new nodo();
	nodo *actual = new nodo();
	nodo *despues = new nodo();

	contador_actual = 0;
	contador_despues = 0;

	if(vacia() == false) {
		actual = primero;
		despues = primero;

		cout<<"Ingrese la posicion: ";
		cin>>pos;
		cout<<"Ingrese el dato: ";
		cin>>nuevo->dato;

		while(actual != NULL && pos < cantidad_datos) {
			actual = actual->siguiente;
			contador_actual++;

			if(contador_actual == pos - 1) {
				break;
			}
		}

		while(despues != NULL) {
			despues = despues->siguiente;
			contador_despues++;

			if(contador_despues == pos + 1) {
				break;
			}
		}

		nuevo->siguiente = actual->siguiente;
		nuevo->anterior = actual;
		actual->siguiente = nuevo;
		despues->anterior = nuevo;
		c += 1;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

//busca dato indicado en la lista y retorna encontrado
bool buscar_dato(int dt) {
	nodo *actual = new nodo();

	bandera = false;
	contador_actual = 0;
	bool encontrado = false;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			if(actual->dato == dt) {
				bandera = true;
				encontrado = true;
				break;
			}

			actual = actual->siguiente;
			contador_actual++;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(bandera) {
		cout<<actual->dato<<" en posicion: "<<contador_actual<<endl;
	}
	else {
		cout<<dt<<" no se encuentra en la lista"<<endl;
	}

	return encontrado;
}

//modifica dato de la lista
void modificar_dato(int dt0, int dt1) {
	nodo *actual = new nodo();

	bandera = false;

	if(vacia() == false) {
		actual = primero;

		cout<<"Ingrese el dato a modificar: ";
		cin>>dt0;

		if(buscar_dato(dt0)) {
			cout<<"Ingrese el nuevo dato: ";
			cin>>dt1;

			while(actual != NULL) {
				if(actual->dato == dt0) {
					bandera = true;
					actual->dato = dt1;
					break;
				}

				actual = actual->siguiente;
			}
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(bandera) {
		cout<<"ha cambiado el dato";
	}
}

//modifica dato por posicion en la lista
void modificar_posicion(int dt0, int dt1) {
	nodo *actual = new nodo();

	bandera = false;

	contador_actual = 0;

	if(vacia() == false) {
		actual = primero;

		cout<<"Ingrese la posicion del dato a modificar: ";
		cin>>dt0;

		if(dt0 < cantidad_datos) {
			cout<<"Ingresa el nuevo dato: ";
			cin>>dt1;

			while(actual != NULL) {
				if(dt0 == contador_actual) {
					bandera = true;
					actual->dato = dt1;
					break;
				}

				actual = actual->siguiente;
				contador_actual++;
			}
		}
		else {
			cout<<dt0<<" excede la cantidad de datos en la lista"<<endl;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(bandera) {
		cout<<"ha cambiado el dato";
	}
}

void eliminar_primero(bool &bne, int &c) {
	nodo *actual = new nodo();

	bne = false;

	if(vacia() == false) {
		actual = primero;
		actual = actual->siguiente;
		actual->anterior = NULL;
		primero = actual;
		bne = true;
		c -= 1;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void eliminar_ultimo(bool &bne, int &c) {
	nodo *actual = new nodo();

	bne = false;

	if(vacia() == false) {
		actual = ultimo;
		actual = actual->anterior;
		actual->siguiente = NULL;
		ultimo = actual;
		bne = true;
		c -= 1;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

//elimina nodo por dato
void eliminar_dato(int dt, int &c) {
	nodo *actual = new nodo();
	nodo *antes = new nodo();
	nodo *despues = new nodo();

	bandera = false;

	if(vacia() == false) {
		actual = primero;
		antes = primero;
		despues = primero;

		cout<<"Ingrese el dato a eliminar: ";
		cin>>dt;

		if(buscar_dato(dt)) {
			contador_actual = 0;
			contador_antes = 0;
			contador_despues = 0;

			while(actual != NULL) {
				if(actual->dato == dt) {
					break;
				}

				actual = actual->siguiente;
				contador_actual++;
			}

			while(antes != NULL) {
				if(contador_antes == contador_actual - 1) {
					break;
				}

				antes = antes->siguiente;
				contador_antes++;
			}

			while(despues != NULL) {
				if(contador_despues == contador_actual + 1) {
					break;
				}

				despues = despues->siguiente;
				contador_despues++;
			}

			/*cout<<"actual: "<<actual->dato<<endl;
			cout<<"pos actual: "<<contador_actual<<endl;
			cout<<"antes: "<<antes->dato<<endl;
			cout<<"pos antes: "<<contador_antes<<endl;
			cout<<"despues: "<<despues->dato<<endl;
			cout<<"pos despues: "<<contador_despues<<endl;*/

			antes->siguiente = despues;
			despues->anterior = antes;
			bandera = true;
			c -= 1;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(bandera) {
		cout<<"se ha eliminado el nodo"<<endl;
	}
}

void eliminar_posicion(int dt, int &c) {
	nodo *actual = new nodo();
	nodo *antes = new nodo();
	nodo *despues = new nodo();

	bandera = false;

	if(vacia() == false) {
		actual = primero;
		antes = primero;
		despues = primero;

		cout<<"Ingrese la posicion a eliminar: ";
		cin>>dt;

		if(dt < cantidad_datos) {
			contador_actual = 0;
			contador_antes = 0;
			contador_despues = 0;

			while(actual != NULL) {
				if(contador_actual == dt) {
					break;
				}

				actual = actual->siguiente;
				contador_actual++;
			}

			while(antes != NULL) {
				if(contador_antes == contador_actual - 1) {
					break;
				}

				antes = antes->siguiente;
				contador_antes++;
			}

			while(despues != NULL) {
				if(contador_despues == contador_actual + 1) {
					break;
				}

				despues = despues->siguiente;
				contador_despues++;
			}

			antes->siguiente = despues;
			despues->anterior = antes;
			bandera = true;
			c -= 1;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(bandera) {
		cout<<"se ha eliminado el nodo"<<endl;
	}
}

void mayor_menor() {
	nodo *actual_myr = new nodo();
	nodo *actual_mnr = new nodo();

	if(vacia() == false) {
		actual_myr = primero;
		actual_mnr = primero;
		dato_1 = 0;		//mayor

		while(actual_myr != NULL) {
			if(actual_myr->dato > dato_1) {
				dato_1 = actual_myr->dato;
			}

			actual_myr = actual_myr->siguiente;
		}

		dato_0 = dato_1;		//menor

		while(actual_mnr != NULL) {
			if(actual_mnr->dato < dato_0) {
				dato_0 = actual_mnr->dato;
			}

			actual_mnr = actual_mnr->siguiente;
		}

		cout<<"Mayor: "<<dato_1<<endl;
		cout<<"Menor: "<<dato_0<<endl;
	}
}

void eliminar_dtxdt() {
	nodo *actual = new nodo();

	cout<<"Se borara toda la lista..."<<endl;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			cout<<"dato contenido en nodo: "<<actual->dato<<"... nodo eliminado"<<endl;

			eliminar_primero(bandera_nodo_eliminado, cantidad_datos);
			actual = actual->siguiente;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

float promedio() {
	nodo *actual = new nodo();

	float suma = 0;
	float promedio_ = 0;
	float ndt = contar(c_dt);

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			suma += actual->dato;
			actual = actual->siguiente;
		}

		cout<<"suma: "<<suma<<endl;
		cout<<"datos: "<<ndt<<endl;

		promedio_ = suma / ndt;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	return promedio_;
}

int suma_pares() {
	nodo *actual = new nodo();

	int suma = 0;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			if(actual->dato % 2 == 0) {
				suma += actual->dato;
			}

			actual = actual->siguiente;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;

		suma = 0;
	}

	return suma;
}

int suma_impares() {
	nodo *actual = new nodo();

	int suma = 0;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			if(actual->dato % 2 != 0) {
				suma += actual->dato;
			}

			actual = actual->siguiente;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;

		suma = 0;
	}

	return suma;
}

int suma_dt() {
	nodo *actual = new nodo();

	int suma_total = 0;

	if(vacia() == false) {
		actual = primero;

		while(actual != NULL) {
			suma_total += actual->dato;
			actual = actual->siguiente;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	return suma_total;
}