#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#define MAXLINE 1000

int compare(const void* a, const void* b);

void info(void);

void interprete(int* bufor, char* left, int* k);

void fill_left(int* bufor, int* k, char* left);

void fill_right(char* left, int k);

void generate_chains(int c, char **chains);

void print_chains(int c, char** chains);

#endif
