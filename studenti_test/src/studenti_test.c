#include <stdlib.h>
#include <stdio.h>
#include "funzioni.h"
#include "CUnit/Basic.h"


void test_controllo_anno (void) {

	int i;
	studenti *array= NULL;

	CU_ASSERT_TRUE(controllo(4, 5)==FALSE);
	CU_ASSERT_TRUE(controllo(1993, 20)==TRUE);
	CU_ASSERT_TRUE(controllo(1993, 21)==TRUE);
	CU_ASSERT_TRUE(controllo(1993, 19)==FALSE);
	CU_ASSERT_TRUE(controllo(1993, 22)==FALSE);

	array= autoaquisizione();

	for (i=0; i<5; i++) {
		CU_ASSERT_TRUE(controllo(array[i].nascita.aaaa, array[i].eta)==TRUE);
	}
}

void test_eta_max() {

	studenti *array= NULL;

	array= autoaquisizione();

	CU_ASSERT_TRUE(eta_max(array, 5)==45);
	CU_ASSERT_TRUE(eta_max(array, 5)!=46);
	CU_ASSERT_TRUE(eta_max(array, 5)!=44);
	CU_ASSERT_TRUE(eta_max(array, 5)!=43);
	CU_ASSERT_TRUE(eta_max(array, 5)!=47);

}

void test_eta_min() {

	studenti *array= NULL;

	array= autoaquisizione();

	CU_ASSERT_TRUE(eta_min(array, 5)==20);
	CU_ASSERT_TRUE(eta_min(array, 5)!=19);
	CU_ASSERT_TRUE(eta_min(array, 5)!=21);
	CU_ASSERT_TRUE(eta_min(array, 5)!=18);
	CU_ASSERT_TRUE(eta_min(array, 5)!=22);

}

void test_cod_fiscale(void) {

	int i;
	studenti *array= NULL;

	array= autoaquisizione();

	for(i=0; i<5; i++) {

		CU_ASSERT_TRUE(strlen(array[0].cod_fiscale)==16);
	}

	for(i=0; i<5; i++) {

		CU_ASSERT_TRUE(strlen(array[0].cod_fiscale)!=15);
	}

	for(i=0; i<5; i++) {

		CU_ASSERT_TRUE(strlen(array[0].cod_fiscale)!=14);
	}

}

void test_nome() {

	studenti *array= NULL;

	array= autoaquisizione();

	CU_ASSERT_STRING_EQUAL(array[0].nome, "Rocco");
	CU_ASSERT_STRING_EQUAL(array[1].nome, "Piero");
	CU_ASSERT_STRING_EQUAL(array[2].nome, "Angela");
	CU_ASSERT_STRING_EQUAL(array[3].nome, "Francesca");
	CU_ASSERT_STRING_EQUAL(array[4].nome, "Giampiero");

	CU_ASSERT_STRING_NOT_EQUAL(array[0].nome, "rocco");
	CU_ASSERT_STRING_NOT_EQUAL(array[1].nome, "Pier");

}

void test_cognome() {

	studenti *array= NULL;

	array= autoaquisizione();

	CU_ASSERT_STRING_EQUAL(array[0].cognome, "Caliandro");
	CU_ASSERT_STRING_EQUAL(array[1].cognome, "Bianchi");
	CU_ASSERT_STRING_EQUAL(array[2].cognome, "Rossi");
	CU_ASSERT_STRING_EQUAL(array[3].cognome, "Forte");
	CU_ASSERT_STRING_EQUAL(array[4].cognome, "Bucci");

	CU_ASSERT_STRING_NOT_EQUAL(array[0].cognome, "caliandro");
	CU_ASSERT_STRING_NOT_EQUAL(array[1].cognome, "Piero");

}

void test_nome_null() {

	int i;
	studenti *array= NULL;

	array= autoaquisizione();

	for(i=0; i<5; i++) {

		CU_ASSERT_PTR_NOT_NULL(array[i].nome);
	}

}

void test_cognome_null() {

	int i;
	studenti *array= NULL;

	array= autoaquisizione();

	for(i=0; i<5; i++) {

		CU_ASSERT_PTR_NOT_NULL(array[i].cognome);
	}

}

void test_data() {

	studenti *array= NULL;
	int i;

	array= autoaquisizione();

	for (i=0; i<5; i++) {

		CU_ASSERT_TRUE(array[i].nascita.gg>0);
		CU_ASSERT_TRUE(array[i].nascita.mm>0);
		CU_ASSERT_TRUE(array[i].nascita.aaaa>0);
	}
}



int suite_void_init (void) {
    return 0;
}

int suite_void_cleanup (void) {
    return 0;
}


int main(int argc, char *argv[]) {
    CU_ErrorCode error;

    CU_TestInfo test_array_studenti[] = {
      { "test di controllo anno()", test_controllo_anno },

      { "test di controllo eta massima()", test_eta_max },

      { "test di controllo eta minima()", test_eta_min },

      { "test di controllo lunghezza codice fiscale=16()", test_cod_fiscale },

      { "test di controllo nome()", test_nome },

      { "test di controllo cognome()", test_cognome },

      { "test di controllo nome!=NULL()", test_nome_null },

      { "test di controllo cognome!=NULL()", test_cognome_null },

      { "test di controllo data non negativa()", test_data },

      CU_TEST_INFO_NULL,
    };


     //...

    CU_SuiteInfo suites[] = {
      { "test suite per studenti ", suite_void_init, suite_void_cleanup, test_array_studenti },

      //...

      CU_SUITE_INFO_NULL,
    };



   if (CUE_SUCCESS != CU_initialize_registry()) {
      error = CU_get_error();
      system("PAUSE");
      return -1;
   }

   error = CU_register_suites(suites);

   if (CUE_SUCCESS != error) {
      CU_cleanup_registry();
      error = CU_get_error();
      system("PAUSE");
      return -1;
   }


   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();


   CU_cleanup_registry();
   error = CU_get_error();
   system("PAUSE");

   return error;
}
