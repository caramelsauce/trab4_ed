#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void inicArvore(struct Node **r)
{
	(*r) = NULL;
}

void insere(struct Node **r, struct Node *novo)
{
	if((*r) != NULL){
		if(strcmp((*r)->contato.nome, novo->contato.nome) > 0){
			if((*r)->esq == NULL)
				(*r)->esq = novo;
			else
				insere(&(*r)->esq, novo);
		}
		else{
			if((*r)->dir == NULL)
				(*r)->dir = novo;
			else
				insere(&(*r)->dir, novo);
		}
	}
	else
		(*r) = novo;
}

void insereNode(struct Node **r, struct Contato temp)
{
	struct Node *novo = malloc(sizeof(struct Node));
	novo->contato = temp;
	novo->esq = NULL;
	novo->dir = NULL;
	insere(r, novo);
}

void excluirNode(struct Node **r, char *nome)
{
	struct Node *aux;
	if((*r) != NULL){
		if(strcmp(nome, (*r)->contato.nome) == 0){
			aux = (*r);
			if((*r)->esq == NULL)
				(*r) = (*r)->dir;
			else
				if((*r)->dir == NULL)
					(*r) = (*r)->esq;
				else{
					aux = encontrarMaior(&((*r)->esq));
					(*r)->contato = aux->contato;
				}
			excluirListaTelefones(&aux->contato.telefones);
			free(aux);
		}
		else{
			if(strcmp(nome, (*r)->contato.nome) < 0)
				excluirNode(&((*r)->esq), nome);
			else
				excluirNode(&((*r)->dir), nome);
		}
	}
}

struct Node * encontrarMaior(struct Node **r)
{
	struct Node *aux = (*r);
	if((*r)->dir == NULL){
		(*r) = (*r)->esq;
		return(aux);
	}
	else
		return encontrarMaior(&((*r)->dir));
}

void printEmOrdem(struct Node *r)
{
	if(r != NULL){
		printEmOrdem(r->esq);
		printf("%s\n", r->contato.nome);
		printTelefones(&r->contato.telefones);
		printEmOrdem(r->dir);
	}
}
