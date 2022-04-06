#include "functions.h"

int compare(const void* a, const void* b) {
	char** _a = (char**)a;
	char** _b = (char**)b;

	if (strlen(*_a) > strlen(*_b))
		return 1;
	else if (strlen(*_a) < strlen(*_b))
		return -1;
	else
		return strcmp(*_a, *_b);
}

void info(void) {
	printf("Program wypisuje n lancuchow z jezyka opisanego za pomoca gramatyki bezkontekstowej\n");
	printf("Gramatyka opisana jako : S -> aSa|bSb|a|b|e\n");
	printf("Podaj n : ");
}

void interprete(int* bufor, char* left, int* k) {
	for (int i = 0, j = *k; j > 0; j--, i++){
		if (bufor[i] == 1)
			left[i] = 'a';
		if (bufor[i] == 2)
			left[i] = 'b';
	}
}

void fill_left(int* bufor, int* k, char* left) {
	int i = 0, j = 0;
	for (i = 0, j = *k; j > 0; j--, i++)
		bufor[i] = rand() % 2 + 1;

	interprete(bufor, left, k);

	(*k)++;

	bufor[i] = rand() % 3;
	if (bufor[i] == 0) {
		left[i] = 'a';
	}
	if (bufor[i] == 1 ) {
		left[i] = 'b';
	}
	if (bufor[i] == 2) { // epsilon
		(*k)--;
	}
}

void fill_right(char* left, int k) {
	for (int i = 0, j = 2 * k - 2; j >= k; j--, i++) {
		left[j] = left[i];
	}
}

void generate_chains(int c, char ** chains) {
	int bufor[MAXLINE];
	char left[MAXLINE];
	int t = 0;
	int len = c;

	while (len > 0) {
		int k = rand() % 9 + 1;
		fill_left(bufor, &k, left);
		fill_right(left, k);

		int f = 0;

		int j = 2 * k - 1;
		char* temp = (char*)malloc((j + 1) * sizeof(*temp));

		for (int i = 0; i < j; i++)
			temp[i] = left[i];
		temp[j] = '\0';

		for (int i = 0; i < t; i++) {
			if (strcmp(chains[i], temp) == 0) {
				f = 1;
				break;
			}
		}
		if (f == 1)
			continue;
		
		chains[t++] = temp;
		len--;
	}
}

void print_chains(int c, char** chains) {
	for (int i = 0; i < c; i++)
		printf("%s\n", chains[i]);
}