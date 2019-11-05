#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


int main(int argc, char *argv[]) {
	struct Node *r;
	struct Contato temp;
	inicArvore(&r);
	inicListaTelefone(&temp.telefones);
	strcpy(temp.nome, "teste");
	inserirTelefone(&temp.telefones, 123456);
	insereNode(&r, temp);
	inicListaTelefone(&temp.telefones);
	strcpy(temp.nome, "bucethanos");
	inserirTelefone(&temp.telefones, 123456);
	insereNode(&r, temp);
	inicListaTelefone(&temp.telefones);
	strcpy(temp.nome, "sashagreysafadinha");
	inserirTelefone(&temp.telefones, 123456);
	insereNode(&r, temp);
	printEmOrdem(r);
	return 0;
}
