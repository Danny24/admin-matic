 /**
 * 
 * @author Denny Alexis Herrera Marín
 * @title cPass
 * @version 1.0
 * 
 */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void cPass(char *pass, int longitud){
	int cont=0;
	char cla;

	do{
		cla = getch();

		if(cla!=13 && cla!='\b'){
			printf("*");
			pass[cont] = cla;
			cont++;
		}
		if(cla=='\b' && cont !=0){
			printf("\b");
			printf(" ");
			printf("\b");
			cont--;
			pass[cont] = NULL;
		}
		
	}while(cla!=13 && cont<longitud);

	pass[cont] = NULL;

}