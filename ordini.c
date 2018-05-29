#include "ordini.h"

int dimFile (FILE *fp) {

	int result = 0;
	Ordine tmp;

	while (fscanf(fp, "%d/%d/%d %s %s %d %d", &(tmp.data.year), &(tmp.data.month), &(tmp.data.day), tmp.type, tmp.taste, &(tmp.num), &(tmp.id)) == 7) {

		result++;
	}

	rewind(fp);
	return result;
}

Ordine * leggiTutti (char * fileName, int *dim) {

	FILE *fp = fopen(fileName, "r");
	Ordine * result = NULL;
	Ordine tmp;
	int i;

	*dim = 0;
	
	if (fp == NULL) {

		printf("Impossibile aprire il file!");
		return result;	
	}

	*dim = dimFile(fp);

	result = (Ordine*)malloc(sizeof(Ordine) * (*dim));

	for (i = 0; i < *dim; i++) {

		if (fscanf(fp, "%d/%d/%d %s %s %d %d", &(tmp.data.year), &(tmp.data.month), &(tmp.data.day), tmp.type, tmp.taste, &(tmp.num), &(tmp.id)) == 7) {

			result[i] = tmp;
		}
	}

	fclose(fp);
	return result;
}

void stampaOrdine (Ordine *v, int dim) {

	int i;

	for (i = 0; i < dim; i++) {
		
		printf("Data: %d/%d/%d,", v[i].data.day, v[i].data.month, v[i].data.year);
		printf("tipo: %s, gusto: %s, quantita': %d, cliente: %d.\n",  v[i].type, v[i].taste, v[i].num, v[i].id);
	}
}

void ordina(Ordine * v, int dim) {

	Ordine * tmp = (Ordine *)malloc(sizeof(Ordine) * dim);
	mergeSort(v, 0, dim-1, tmp);
	free(tmp);
}

list leggiCosti (char *fileName) {