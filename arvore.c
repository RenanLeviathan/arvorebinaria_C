#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
	Arvore *a = NULL;
	//5, 12, 9, 11, 13, 10 e 6
	a = inserir(a, 5);
	a = inserir(a, 12);
	a = inserir(a, 9);
	a = inserir(a, 11);
	a = inserir(a, 13);
	a = inserir(a, 10);
	a = inserir(a, 6);
	printf("\nImprimindo árvore em pré-ordem\n");
	preordem(a);
	printf("\nExclusão do 12\n");
	remover(a, 12);
	printf("\nImprimindo árvore em pré-ordem\n");
	preordem(a);
	free(a);
	a=NULL; //manter a segurança do endereço desalocado
	return 0;
}