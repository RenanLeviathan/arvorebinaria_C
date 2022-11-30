#include <stdio.h>
#include <stdlib.h>

struct Arvore{
	int info;
	struct Arvore *esq;
	struct Arvore *dir;
};
typedef struct Arvore Arvore;

//Insere elementos na árvore
Arvore* inserir(Arvore *a, int info){
	if(a==NULL){
		a=(Arvore*)malloc(sizeof(Arvore));
		a->info = info;
		a->esq = NULL;
		a->dir = NULL;
	}else{
		if(info > a->info){
			a->dir = inserir(a->dir, info);
		}else if(info < a->info){
			a->esq = inserir(a->esq, info);
		}else printf("Elemento já consta na árvore!!");
	}
	return a;
}

void buscar(Arvore *a, int info){
	if(a==NULL){
		printf("Árvore vazia!!");
	}else if(info < a->info){
		buscar(a->esq,info);
	}else if(info > a->info){
		buscar(a->dir, info);
	}else{
		printf("< %d >",a->info);
	}
}
Arvore* menor_subarvore_direita(Arvore* a){
	Arvore *temp;
	temp = a->dir;
	while(temp->esq){
		temp = temp->esq;
	}
	return temp;
}
void remover(Arvore *a, int info){
	if(a->info == info){
		if(a->esq==NULL && a->dir==NULL){//nó folha
			free(a);
		}else if(a->esq==NULL && a->dir!=NULL ){ //segundo caso
			Arvore* temp = a;
			a=a->dir;
			free(temp);
		}else if(a->dir==NULL && a->esq!=NULL){ //segundo caso
			Arvore* temp = a;
			a=a->esq;
			free(temp);
		}else{
			Arvore *temp;
			temp = menor_subarvore_direita(a);
			a->info = temp->info;
			temp->info = info;
			remover(a->dir,info);
		}
	}else if(info > a->info){
		remover(a->dir, info);
	}else{
		remover(a->esq, info);
	}
}

//Percorre a árvore em pré-ordem
void preordem(Arvore *a){
	if(a != NULL){
		printf("%d(",a->info);
		preordem(a->esq);
		preordem(a->dir);
		printf(")");
	}
}
void posordem(Arvore *a){
	if(a!=NULL){
		printf("(");
		posordem(a->esq);
		posordem(a->dir);
		printf(")");
		printf("%d",a->info);
	}
}