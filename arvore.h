#include <stdio.h>
#include <stdlib.h>

struct Arvore{
	int info;
	struct Arvore *esq;
	struct Arvore *dir;
};
typedef struct Arvore Arvore;

//Insere elementos na árvore
void inserir(Arvore **a, int info){
	if((*a)==NULL){
		*a=(Arvore*)malloc(sizeof(Arvore));
		(*a)->info = info;
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}else{
		if(info > (*a)->info) inserir(&(*a)->dir, info);
		else inserir(&(*a)->esq, info);
	}
}

//Percorre a árvore em pré-ordem
void preordem(Arvore *a){
	if(a != NULL){
		printf("(%d",a->info);
		preordem(a->esq);
		preordem(a->dir);
		printf(")");
	}
}