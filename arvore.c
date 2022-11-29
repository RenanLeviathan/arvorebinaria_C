#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
	Arvore *a = NULL;
	inserir(&a, 3);
	inserir(&a, 2);
	inserir(&a, 1);
	inserir(&a, 4);
	inserir(&a, 5);
	inserir(&a, 6);
	inserir(&a, 7);
	inserir(&a, 16);
	inserir(&a, 15);
	inserir(&a, 17);
	preordem(a);
	return 0;
}