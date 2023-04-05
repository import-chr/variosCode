#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
	int dato;
	nodo *next;
} *first, *last;

//Prototipos
void menu();										//menu ............................. done
void print_begin();									//imprime lista desde nodo primero . done
void print_last();									//imprime lista desde nodo ultimo .. done
void insert_last(int &);							//inserta al final ................. done
void insert_begin(int &);							//inserta al inicio ................ done
void insert_pos(int &, int);						//inserta en posicion .............. done
void modify_dt();
void modify_pos();
void delete_first();
void delete_last();
void delete_dt();
void delete_pos();

bool empty();										//valida existencia de datos ....... done
bool search();

int count();
int mayor();
int menor();
int suma();
int par();
int impar();

float prom();

//Variables
int opcion, size, position;

bool flag;

int main() {
	do {
		menu();

		cin>>opcion;

		switch(opcion) {
			case 1:
				system("cls");
				insert_last(size);
			break;
			case 2:
				system("cls");
				insert_begin(size);
			break;
			case 3:
				system("cls");
				print_begin();
			break;
			case 4:
				system("cls");
				print_last();
			break;
			case 5:
				system("cls");
				insert_pos(size, position);
			break;
			case 6:
				system("cls");
				search();
			break;
			case 7:
				system("cls");
				modify_dt();
			break;
			case 8:
				system("cls");
				modify_pos();
			break;
			case 9:
				system("cls");
				delete_first();
			break;
			case 10:
				system("cls");
				delete_last();
			break;
			case 11:
				system("cls");
				delete_dt();
			break;
			case 12:
				system("cls");
				delete_pos();
			break;
			case 13:
				system("cls");
				cout<<"El promedio de los datos es: "<<prom()<<endl;
			break;
			case 14:
				system("cls");
				cout<<"La suma de los datos pares es: "<<par()<<endl;
			break;
			case 15:
				system("cls");
				cout<<"La suma de los datos impares es: "<<impar()<<endl;
			break;
			case 16:
				system("cls");
				cout<<"La suma de los datos es: "<<suma()<<endl;
			break;
			case 17:
				system("cls");
				cout<<"Mayor de los datos es: "<<mayor()<<endl;
			break;
			case 18:
				system("cls");
				cout<<"Menor de los datos es: "<<menor()<<endl;
			break;
			case 19:
				system("cls");
				cout<<"Numero de nodos en la lista: "<<count()<<endl;
			break;
		}

		system("pause");
	} while(opcion != 20);

	return 0;
}

void menu() {
	cout<<"Listas Circulares"<<endl;
	cout<<"[1] Insertar al final"<<endl;
	cout<<"[2] Insertar al inicio"<<endl;
	cout<<"[3] Imprimir desde el inicio"<<endl;
	cout<<"[4] Imprimir desde el final"<<endl;
	cout<<"[5] Insertar en posicion"<<endl;
	cout<<"[6] Buscar dato"<<endl;
	cout<<"[7] Modificar por dato"<<endl;
	cout<<"[8] Modificar por posicion"<<endl;
	cout<<"[9] Eliminar primero"<<endl;
	cout<<"[10] Eliminar ultimo"<<endl;
	cout<<"[11] Eliminar dato"<<endl;
	cout<<"[12] Eliminar posicion"<<endl;
	cout<<"[13] Promedio de datos"<<endl;
	cout<<"[14] Sumar pares"<<endl;
	cout<<"[15] Sumar impares"<<endl;
	cout<<"[16] Sumar datos"<<endl;
	cout<<"[17] Dato mayor"<<endl;
	cout<<"[18] Dato menor"<<endl;
	cout<<"[19] Contar nodos"<<endl;
	cout<<"[20] Salir"<<endl;
	cout<<"	--->";
}

bool empty() {
	bool ans;

	first == NULL ? ans = true : ans = false;

	return ans;
}

void insert_last(int &num) {
	nodo *_new = new nodo();

	flag = false;

	cout<<"Ingrese el dato: ";
	cin>>_new->dato;

	if(empty()) {
		first = _new;
		first->next = NULL;
		last = _new;
		flag = true;
	}
	else {
		last->next = _new;
		_new->next = first;
		last = _new;
		flag = true;
	}

	if(flag) {
		cout<<"Nodo insertado"<<endl;
	}
	else {
		cout<<"Nodo no insertado"<<endl;
	}

	num++;
}

void print_begin() {
	nodo *actual = new nodo();

	cout<<"Datos en lista"<<endl;

	if(!empty()) {
		actual = first;

		do {			
			cout<<actual->dato<<endl;

			actual = actual->next;
		} while(actual != last->next);
	}
}

void print_last() {
	nodo *actual = new nodo();

	cout<<"Datos en lista"<<endl;

	if(!empty()) {
		actual = last;

		do {			
			cout<<actual->dato<<endl;

			actual = actual->next;
		} while(actual != last);
	}
}

void insert_begin(int &num) {
	nodo *_new = new nodo();

	flag = false;

	cout<<"Ingrese el dato: ";
	cin>>_new->dato;

	if(!empty()) {
		last->next = _new;
		_new->next = first;
		first = _new;
		flag = true;
	}
	else {
		insert_last(size);
	}

	if(flag) {
		cout<<"Nodo insertado"<<endl;
	}
	else {
		cout<<"Nodo no insertado"<<endl;
	}

	num++;
}

void insert_pos(int &num, int pos) {
	nodo *actual = new nodo();
	nodo *_new = new nodo();
	int counter = 0;
	flag = false;

	if(!empty()) {
		actual = first;

		cout<<"Ingrese la posicion: ";
		cin>>pos;
		cout<<"Ingrese el dato: ";
		cin>>_new->dato;

		if(pos < size && pos != 0) {
			while(actual != last) {
				if(counter == pos - 1) {
					break;
				}

				actual = actual->next;
				counter++;
			}

			_new->next = actual->next;
			actual->next = _new;
			flag = true;
		}
		else if(pos == 0) {
			insert_begin(size);
		}
		else if(pos == size) {
			insert_last(size);
		}
		else {
			cout<<"posicion invalida"<<endl;
		}
	}

	if(flag) {
		cout<<"Nodo insertado"<<endl;
	}
	else {
		cout<<"Nodo no insertado"<<endl;
	}

	num++;
}

bool search() {
	nodo *actual = new nodo();
	int dato, cont_pos = 0;
	bool flag02 = false;
	flag = false;

	if(empty() == false) {
		actual = first;

		cout<<"Ingrese el dato a buscar: ";
		cin>>dato;

		while(actual != last) {
			if(actual->dato == dato) {
				flag = true;
				flag02 = true;
				break;
			}

			cont_pos++;
			actual = actual->next;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	if(flag) {
		cout<<"Dato "<<actual->dato<<" encontrado en la posicion: "<<cont_pos<<endl;
	}
	else {
		cout<<"dato no encontrado"<<endl;
	}

	return flag02;
}

void modify_dt() {
	nodo *actual = new nodo();
	int nDt, dt;

	if(empty() == false) {
		actual = first;

		cout<<"Que dato modificara: "<<endl;
		cin>>dt;

		while(actual != last) {
			actual = actual->next;

			if(actual->dato == dt) {
				cout<<"Ingresa el nuevo dato: ";
				cin>>nDt;

				actual->dato = nDt;
				break;
			}
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void modify_pos() {
	nodo *actual = new nodo();
	int pos, nDt, cont_pos;

	if(empty() == false) {
		actual = first;

		cout<<"Que posicion modificara: "<<endl;
		cin>>pos;

		while(actual != last) {
			if(cont_pos == pos - 1) {
				cout<<"Ingrese el nuevo dato: ";
				cin>>nDt;

				actual->dato = nDt;
				break;
			}

			cont_pos++;
			actual = actual->next;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void delete_first() {
	nodo *actual = new nodo();
	actual = first;
	last->next = first->next;
	first = actual->next;

	cout<<"Nodo eliminado"<<endl;
}

int count() {
	int cant = 1;
	nodo *actual = new nodo();

	if(empty() == false) {
		actual = first;

		while(actual != last) {
			cant++;
			actual = actual->next;
		}
	}
	else {
		cout<<"Lista vacia"<<endl;
	}

	return cant;
}

void delete_last() {
	nodo *actual = new nodo();
	int e = count(), c;
	
	if(empty() == false) {
		actual = first;

		while(c != e) {
			actual = actual->next;
			c++;
		}

		last = actual;
		actual->next = first;

		cout<<"Nodo eliminado"<<endl;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void delete_dt() {
	nodo *actual = new nodo();
	nodo *prev = new nodo();
	int dt_del, cont, cont2;

	if(empty() == false) {
		actual = first;
		prev = first;

		cout<<"Dato a eliminar: ";
		cin>>dt_del;

		while(actual != last) {
			if(actual->dato == dt_del) {
				break;
			}

			actual = actual->next;
			cont++;
		}

		while(prev != last) {
			if(cont2 == cont - 1) {
				break;
			}

			cont2++;
			prev = prev->next;
		}

		prev->next = actual->next;

		cout<<"Nodo eliminado"<<endl;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

void delete_pos() {
	nodo *actual = new nodo();
	nodo *aux = new nodo();
	int pos, pa = 0, pax = 0;

	if(empty() == false) {
		actual = first;
		aux = first;

		cout<<"Posicion a eliminar: ";
		cin>>pos;

		while(actual != last) {

			if(pa == pos - 1) {
				break;
			}

			pa++;
			actual = actual->next;
		}

		while(aux != last) {
			if(pax == pos) {
				break;
			}

			pax++;
			aux = aux->next;
		}

		actual->next = actual->next->next;

		cout<<"nodo eliminado"<<endl;
	}
	else {
		cout<<"Lista vacia"<<endl;
	}
}

int suma() {
	nodo *actual = new nodo();
	int suma_ = 0;

	if(empty() == false) {
		actual = first;

		while(actual != last) {
			suma_ += actual->dato;
			actual = actual->next;
		}

		suma_ += actual->dato;
	}

	return suma_;
}

float prom() {
	float prom_ = 0;
	float sum = suma();
	float cant = count();

	cout<<"suma: "<<sum<<" cantidad: "<<cant<<endl;

	prom_ = sum / cant;

	return prom_;
}

int par() {
	nodo *actual = new nodo();
	int suma_ = 0;

	if(empty() == false) {
		actual = first;

		while(actual != last) {
			if(actual->dato % 2 == 0) {
				suma_ += actual->dato;
			}

			actual = actual->next;
		}
	}

	return suma_;
}

int impar() {
	nodo *actual = new nodo();
	int suma_ = 0;

	if(empty() == false) {
		actual = first;

		while(actual != last) {
			if(actual->dato % 2 != 0) {
				suma_ += actual->dato;
			}
			
			actual = actual->next;
		}
	}

	if(actual->dato % 2 != 0) {
		suma_ += actual->dato;
	}

	return suma_;
}

int mayor() {
	nodo *myr = new nodo;
	int mM = 0;

	if(empty() == false) {
		myr = first;

		while(myr != last) {
			if(myr->dato > mM) {
				mM = myr->dato;
			}

			myr = myr->next;
		}
	}

	if(myr->dato > mM) {
		mM = myr->dato;
	}

	return mM;
}

int menor() {
	nodo *mnr = new nodo;
	int mm = mayor();

	if(empty() == false) {
		mnr = first;

		while(mnr != last) {
			if(mnr->dato < mm) {
				mm = mnr->dato;
			}

			mnr = mnr->next;
		}
	}

	if(mnr->dato < mm) {
		mm = mnr->dato;
	}

	return mm;
}