#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
# define NO_OF_CHARS 256

int max (int a, int b);
int max2 (int a, int b);
void badCharHeuristic( char *str, int size,
                        int badchar[NO_OF_CHARS]);

int search( char *txt,  char *pat);

void badCharHeuristic2( char *str, int size,
                        int badchar[NO_OF_CHARS]);

int search2( char *txt,  char *pat);