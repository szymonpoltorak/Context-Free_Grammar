#include "includes.h"
#include "functions.h"

int main(void) {
	int c = 0;
	char* chains[MAXLINE];

	srand(time(NULL));

	info();
	if (scanf_s("%d", &c) != 1) {
		fprintf(stderr, "Nie udalo sie wczytac znaku!\n");
		exit(EXIT_FAILURE);
	}

	if (c == 0) {
		printf("Liczba linii do wypisania jest rowna 0. Program zakonczy dzialanie.\n");
		exit(EXIT_SUCCESS);;
	}
	generate_chains(c, chains);
	qsort(chains, c, sizeof(*chains), compare);
	print_chains(c, chains);

	exit(EXIT_SUCCESS);;
}