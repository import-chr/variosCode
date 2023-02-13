#include <stdio.h>

#define TAM 100

void main(void) {
	char cinta[TAM];
	int estado, i = 0;
	
	printf("AFD que valina el lenguaje c+a*|a+\n\n");
	printf("Introduce palabra a validar: ");
	scanf("%s", cinta);
	
	while(cinta[i] != '\0') {
		switch(cinta[i]) {
			case 'a':
				if(estado == 0) estado = 3;
				if(estado == 1) estado = 4;
				if(estado == 2) estado = 4;
				if(estado == 3) estado = 3;
				if(estado == 4) estado = 4;
				break;
			case 'b':
				if(estado == 0) estado = 4;
				if(estado == 1) estado = 2;
				if(estado == 2) estado = 2;
				if(estado == 3) estado = 4;
				if(estado == 4) estado = 4;
				break;
			case 'c':
				if(estado == 0) estado = 1;
				if(estado == 1) estado = 1;
				if(estado == 2) estado = 4;
				if(estado == 3) estado = 4;
				if(estado == 4) estado = 4;
				break;
		}
		
		i++;
	}
	
	if(estado == 1 || estado == 2 || estado == 3) {
		printf("Palabra valida");
	}
	else {
		printf("Palabra invalida");
	}
}
