#include <stdio.h>
#define TAM 100
void main(void)
{
	char cinta[TAM];
	int edo=0,i=0;
	printf("AFD que valida el lenguaje c+b*|a+ \n\n");
	printf("Introduce palabra a validar: ");
	scanf("%s",cinta);
	while(cinta[i]!='\0')
	{
		switch(cinta[i])
		{
			case 'a':	if(edo==0) edo=3;
						if(edo==1) edo=4;
						if(edo==2) edo=4;
						if(edo==3) edo=3;
						if(edo==4) edo=4;					
						break;
			case 'b':   if(edo==0) edo=4;
						if(edo==1) edo=2;
						if(edo==2) edo=2;
						if(edo==3) edo=4;
						if(edo==4) edo=4;
						break;
			case 'c':	if(edo==0) edo=1;
						if(edo==1) edo=1;
						if(edo==2) edo=4;
						if(edo==3) edo=4;
						if(edo==4) edo=4;
		}//switch
		i++;
	}//while
	if(edo==1||edo==2||edo==3)
		printf("Palabra valida");
	else
		printf("Palabra no valida");
}
