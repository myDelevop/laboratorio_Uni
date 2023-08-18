#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include <stdio.h>
#include <stdlib.h>

/**
 *  \def #define MAX_WORD 50
 *
 *  Costante la quale indica il valore massimo
 *  cui un nome o cognome possa assumere
 */

#define MAX_WORD 50

/**
 *  \def #define CF_LENGHT 17
 *
 *  Costante la quale indica la lunghezza del coddice fiscale (16)
 *  con l'aggiunta dello '\0'.
 */
#define CF_LENGHT 17 //lunghezza codice fiscale (compreso '\0'nelle stringhe)


/**
 *   \typedef \enum {maschio, femmina}genere;
 *
 *   Definizione di un nuovo tipo enumerato il quale indica
 *   il sesso di ogni studente
 */
typedef enum {maschio, femmina}genere;


/**
 *   \typedef \enum {FALSE, TRUE}boolean;
 *
 *   Definizione di un nuovo tipo enumerato booleano
 *
 */
typedef enum {FALSE, TRUE}boolean;

/** \typedef \struct data
 *
 *  Definizione di un nuovo tipo struct data, contenente
 *  tre interi rispettivamente giorno, mese, anno.
 *
 */
typedef struct {
	int gg;
	int mm;
	int aaaa;
} data;

/** \typedef \struct studenti
 *
 *  Definizione di un nuovo tipo struct studenti. Contiene il nome,
 *  cognome, matricola, eta, data di nascita(tipo struct data),
 *  sesso e codice fiscale.
 *
 */
typedef struct {
	char nome[MAX_WORD];
	char cognome[MAX_WORD];
	int matricola;
	int eta;
	data nascita;
	genere sesso;
	char cod_fiscale[CF_LENGHT];
} studenti;


//PROTOTIPI:

studenti* aquisizione(int *dim);
studenti* autoaquisizione(void);
boolean array_not_null(studenti *s);
void stampa(studenti* s, int dim);
boolean controllo(int anno, int eta);
int eta_max(studenti *s, int dim);
int eta_min(studenti *s, int dim);
boolean controllo_cf(char *codice_fiscale);

#endif /* FUNZIONI_H_ */
