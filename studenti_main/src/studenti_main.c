#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(void) {

	int menu, i=0;
	int dim= 5; //nel caso in cui facciamo direttamente l autoaquisiozione
	boolean res;
	studenti *array= NULL;

	do {

		printf("1. AQUISIZIONE DA TASTIERA\n\n");
		printf("2. AUTOAQUISIZIONE\n\n");
		printf("3. STAMPA\n\n");
		printf("4. CONTROLLO ETA/ANNO\n\n");
		printf("5. RICERCA ETA MINIMA\n\n");
		printf("6. RICERCA ETA MASSIMA\n\n");
		printf("0. ESCI\n\n\n\n");
		printf("Scelta:  ");
		scanf("%d", &menu);


		switch (menu) {

		case 1:
			system("CLS");
			array= aquisizione(&dim);
			break;

		case 2:
			system("CLS");
			array= autoaquisizione();
			break;

		case 3:

			system("CLS");
			stampa(array, dim);
			break;

		case 4:

			system("CLS");

			if (array_not_null(array)) {

			res= TRUE;

			for (i=0; i<dim && res!=FALSE; i++) {
				res= controllo(array[i].nascita.aaaa, array[i].eta);
			}

			if (res==TRUE)
				printf("Tutte le date sono corrette\n");

			if (res==FALSE)
				printf("La %da data e scorretta\n", i);

			system("PAUSE");
			system("CLS");
			}
			break;

		case 5:

			system("CLS");

			if (array_not_null(array)) {

			printf("L'eta minima e:   %d\n\n", eta_min(array, dim));

			system("pause");
			system("CLS");

			}

			break;

		case 6:

			system("CLS");

			if (array_not_null(array)) {

			printf("L'eta massima e:   %d\n\n", eta_max(array, dim));

			system("pause");
			system("CLS");
			}


			break;
		}

	}while(menu!=0);

	return 0;
}
