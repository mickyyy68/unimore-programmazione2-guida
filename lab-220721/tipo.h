/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/



typedef struct{
	char seme;
	int valore;
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
