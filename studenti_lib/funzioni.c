#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

/** \fn studenti* aquisizione(int *dim);
 *
 *  Questa funzione ci permette di effettuare l'aquisizione
 *  da tastiera di un vettore di studenti. Si noti che la
 *  dimensione e passata per riferimento.
 *
 *  \param dim E' un puntatore a intero la quale dovrà
 *  contenere la dimensione dell'array inserito da tastiera.
 *
 *  \return Ritorna un puntatore a struttura aquisito da
 *  tastiera.
 *
 */
studenti* aquisizione(int *dim) {

	studenti *array= NULL;
	int i, sesso;


	printf("Inserisci dimensione del vettore\n");
	scanf("%d", dim);

	system("CLS");

	array= (studenti*) calloc(*dim, sizeof(studenti));

	for (i=0; i<*dim; i++) {

		printf("%do STUDENTE\n\n", i+1);
		printf("Inserisci nome:   ");
		scanf("%s", array[i].nome);
		system("CLS");

		printf("%do STUDENTE\n\n", i+1);
		printf("Inserisci cognome   ");
		scanf("%s", array[i].cognome);
		system("CLS");

		printf("%do STUDENTE\n\n", i+1);
		printf("Inserisci MAT.   ");
		scanf("%d", &array[i].matricola);
		system("CLS");

		printf("%do STUDENTE\n\n", i+1);
		printf("Inserisci eta   ");
		scanf("%d", &array[i].eta);
		system("CLS");

		printf("%do STUDENTE\n\n", i+1);
		printf("Inserisci data di nascita gg/mm/aaaa\n");
		scanf("%d %d %d", &array[i].nascita.gg, &array[i].nascita.mm, &array[i].nascita.aaaa);
		system("CLS");

		do {
			printf("%do STUDENTE\n\n", i+1);
			printf("0. MASCHIO\n");
			printf("1. DONNA\n\n");
			printf("Scelta:   ");
			scanf("%d", &sesso);

			if (sesso==0)
				array[i].sesso= maschio;

			else if (sesso==1)
				array[i].sesso= femmina;

			else {
				system("CLS");

				printf("Inserisci valore valido\n");
				system("pause");
				system("CLS");
			}

			system("CLS");
		}while(sesso!=1 && sesso!=0);

		do {

			printf("%do STUDENTE\n\n", i+1);
			printf("Inserisci codice fiscale \n");
			scanf("%s", array[i].cod_fiscale);

			if (strlen(array[i].cod_fiscale) != 16) {
				printf("DIMENSIONE NON VALIDA\n");
				system("pause");
				system("CLS");
			}
		}while(strlen(array[i].cod_fiscale)!=16);

		system("CLS");

	}

	return array;
}

/** \fn studenti* autoaquisizione(void)
 *
 *  Questa funzione ci permette di effettuare l'autoaquisizione
 *  di un vettore di studenti avvolorato direttamente da codice
 *  Si noti che la dimensione e nota a priori (5) quindi non
 *  ci sarà bisogno di tale valore di ritorno. (Avvalorata nel main)
 *
 *  \return Ritorna un puntatore a struttura.
 *
 */
studenti* autoaquisizione(void) {

	studenti *array= NULL;

	array= (studenti*) calloc(5, sizeof(studenti));

	strcpy(array[0].nome, "Rocco");
	strcpy(array[0].cognome, "Caliandro");
	array[0].matricola= 601859;
	array[0].eta= 20;
	array[0].nascita.gg= 29;
	array[0].nascita.mm= 12;
	array[0].nascita.aaaa= 1993;
	array[0].sesso= maschio;
	strcpy(array[0].cod_fiscale, "RCCCLN93T29D3OC9");

	strcpy(array[1].nome, "Piero");
	strcpy(array[1].cognome, "Bianchi");
	array[1].matricola= 601879;
	array[1].eta= 27;
	array[1].nascita.gg= 9;
	array[1].nascita.mm= 2;
	array[1].nascita.aaaa= 1986;
	array[1].sesso= maschio;
	strcpy(array[1].cod_fiscale, "PREBNC86T09D3SC9");

	strcpy(array[2].nome, "Angela");
	strcpy(array[2].cognome, "Rossi");
	array[2].matricola= 601857;
	array[2].eta= 22;
	array[2].nascita.gg= 18;
	array[2].nascita.mm= 12;
	array[2].nascita.aaaa= 1992;
	array[2].sesso= femmina;
	strcpy(array[2].cod_fiscale, "NGLRSS07T18DCAC9");

	strcpy(array[3].nome, "Francesca");
	strcpy(array[3].cognome, "Forte");
	array[3].matricola= 602859;
	array[3].eta= 26;
	array[3].nascita.gg= 1;
	array[3].nascita.mm= 11;
	array[3].nascita.aaaa= 1988;
	array[3].sesso= femmina;
	strcpy(array[3].cod_fiscale, "FRNFRT29T01DAX49");

	strcpy(array[4].nome, "Giampiero");
	strcpy(array[4].cognome, "Bucci");
	array[4].matricola= 601359;
	array[4].eta= 45;
	array[4].nascita.gg= 20;
	array[4].nascita.mm= 1;
	array[4].nascita.aaaa= 1969;
	array[4].sesso= maschio;
	strcpy(array[4].cod_fiscale, "GMPBCC69T19DADC9");

	return array;
}

/**  \boolean array_not_null(studenti *s)
 *
 *   Questa funzione ci permette di controllare se una struttura
 *   di tipo studenti (passato dal main) sia uguale o diverso
 *   da NULL. Nel caso in cui sarà uguale verrà stampato un
 *   messaggio di errore.
 *
 *   \param s puntatore a struttura studenti
 *   si vuole effettuare il controllo
 *
 *   \return ritorna un valore booleano:
 *
 *   	'TRUE' nel caso in cui la struct non sia NULL
 * 	 	'FALSE' altrimenti (=NULL)
 */
boolean array_not_null(studenti *s) {

	boolean res= TRUE;

	if (s==NULL) {

		system("CLS");
		printf("ERRORE! Impossibile stampare.\n\n una possibile causa di tale errore");
		printf(" potrebbe essere la mancata aquisizione dell' array\n\n");

		system("pause");
		system("CLS");

		res= FALSE;
	}

	return res;
}

/** \fn void void stampa(studenti *s, int dim)
 *
 * 	Questa e una procedura di stampa: visualizza a schermo tutte
 * 	le caratteristiche di ogni studente.
 *
 *  \param s puntatore alla struttura studenit
 *  \param dim intero il quale indica la dimensione del vettore
 *
 */
void stampa(studenti *s, int dim) {

	int i;

	if (s==NULL) {

		printf("ERRORE! Impossibile stampare.\n\n una possibile causa di tale errore");
		printf(" potrebbe essere la mancata aquisizione dell' array\n\n");

		system("pause");
		system("CLS");
	}

	else {
		for (i=0 ;i<dim; i++) {
			printf("*********   %do STUDENTE:   ********\n\n\n", i+1);
			printf("NOME:%30s\n\n", s[i].nome);
			printf("COGNOME:%27s\n\n", s[i].cognome);
			printf("MATRICOLA:%25d\n\n", s[i].matricola);
			printf("ETA:%31d\n\n", s[i].eta);
			printf("DATA DI NASCITA:%11d/%d/%d\n\n", s[i].nascita.gg, s[i].nascita.mm, s[i].nascita.aaaa);

			if (s[i].sesso==0)
				printf("SESSO:%29s\n\n", "maschio");
			else
				printf("SESSO:%29s\n\n", "femmina");

			printf("CF:%32s\n\n\n\n", s[i].cod_fiscale);

			system("pause");
			system("CLS");
		}
	}

}

/** \fn int eta_max(studenti *s, int dim)
 *
 *  Questa funzione calcola l'eta massima in un array
 *  di studenti.
 *
 *  \param s puntatore a struct studenti
 *  \param dim intero il quale indica la dimensione di tale array
 *
 *  \return ritorna l'età massima
 *
 */
int eta_max(studenti *s, int dim) {


	int max, i;

	max= s[0].eta;

	for(i=0; i<dim; i++) {

		if (s[i].eta > max)
			max= s[i].eta;
	}

	return max;
}

/** \fn int eta_min(studenti *s, int dim)
 *
 *  Questa funzione calcola l'eta minima in un array
 *  di studenti.
 *
 *  \param s puntatore a struct studenti
 *  \param dim intero il quale indica la dimensione di tale array
 *
 *  \return ritorna l'età minima
 *
 */
int eta_min(studenti *s, int dim) {

	int min, i;

	min= s[0].eta;

	for(i=0; i<dim; i++) {

		if (s[i].eta < min)
			min= s[i].eta;
	}

	return min;
}

/** \fn boolean controllo(int anno, int eta)
 *
 *  Questa funzione controlla se l'età inserita corrisponda
 *  all' anno.
 *  (Uno studente nato nel 1993 dovrà avere necessariamente 20 o 21 anni)
 *
 *  \param anno anno di nascita
 *  \param eta  età
 *
 *  \return un valore booleano
 *
 *  	'TRUE' se l'età corrisponde all' anno
 *  	'FALSE' altrimenti
 */
boolean controllo(int anno, int eta) {

	boolean res= FALSE;

	if (2014-eta==anno || 2014-eta==anno+1)
		res= TRUE;

	return res;
}

/** \fn boolean controllo_cf(char *codice_fiscale)
 *
 *  Questa funzione controlla che una stringa abbia lunghezza 16
 *  (nel nostro caso il codice fiscale)
 *
 *  \param codice_fiscale viene passato direttamente il CF e non
 *  l'intera struttura
 *
 *  \return un valore booleano
 *
 *  	'TRUE' se il CF ha effettivamente lunghezza pari a 16
 *  	'FALSE' altrimenti
 */
boolean controllo_cf(char *codice_fiscale) {

	boolean res= FALSE;

	if (strlen(codice_fiscale)==16)
		res= TRUE;


	return res;
}
