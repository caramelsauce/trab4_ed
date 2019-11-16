#ifndef ARVORE_H
#define ARVORE_H

#include "listaTelefone.h"

struct Contato{
	char nome[50];
	struct listaTelefones telefones;
};

struct Node{
	struct Contato contato;
	struct Node *esq, *dir;
};

void inicArvore(struct Node **r);

void insereNode(struct Node **r, struct Contato temp);

void insere(struct Node **r, struct Node *novo);

void excluirNode(struct Node **r, char *nome);

struct Node *encontrarMaior(struct Node **r);

struct Node *localizarNode(struct Node *r, char *nome); 

void printEmOrdemCrescente(struct Node *r);

void printEmOrdemDecrescente(struct Node *r);

#endif
