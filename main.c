#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"

void menu();
void incluir_contato(struct Node **r);
void buscar_contato(struct Node *r);
void excluir_contato(struct Node **r);

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	struct Node *r;
	int op, quit = 0;
	inicArvore(&r);
	while(!quit){
		menu();
		scanf("%d", &op);
		getchar();
		switch(op){
			case 1:
				incluir_contato(&r);
				break;
			case 2:
				buscar_contato(r);
				break;
			case 3:
				excluir_contato(&r);
				break;
			case 4:
				printEmOrdemCrescente(r);
				break;
			case 5:
				printEmOrdemDecrescente(r);
				break;
			case 0:
				quit = 1;
				break;
			default:
				break;
		}
	}
	return 0;
}

void menu()
{
	printf("\n\n");
	printf("1 - Incluir Contato\n");
	printf("2 - Buscar Contato\n");
	printf("3 - Excluir Contato\n");
	printf("4 - Exibir Dados em Ordem Crescente\n");
	printf("5 - Exibir Dados em Ordem Decrescente\n");
	printf("0 - Sair\n");
	printf("Opção: ");
}

void incluir_contato(struct Node **r)
{
	struct Contato temp;
	struct Node *aux;
	int quit = 0;
	int telefone;
	printf("Digite o nome do novo contato: ");
	gets(temp.nome);
	aux = localizarNode(*r, temp.nome);
	if(!aux){
		inicListaTelefone(&temp.telefones);
		while(!quit){
			printf("Digite os telefones do contato ou 0 para parar de inserir: ");
			scanf("%d", &telefone);
			if(!telefone)
				quit = 1;
			else
				inserirTelefone(&temp.telefones, telefone);
		}
		insereNode(r, temp);
	}
	else{
		printf("\nO contato já existe\n");
		printf("\t%s\n", aux->contato.nome);
		printTelefones(&aux->contato.telefones);
	}
}

void buscar_contato(struct Node *r)
{
	char nome[50];
	struct Node *aux;
	printf("Digite o nome a ser procurado: ");
	gets(nome);
	aux = localizarNode(r, nome);
	if(!aux)
		printf("\nNenhum contato foi encontrado com este nome\n");
	else{
		printf("Dados do contato:\n\t%s\n", aux->contato.nome);
		printTelefones(&aux->contato.telefones);
	}
}

void excluir_contato(struct Node **r)
{
	struct Node *aux;
	char nome[50];
	printf("Digite o nome a ser excluído: ");
	gets(nome);
	aux = localizarNode((*r), nome);
	if(!aux)
		printf("\nContato não encontrado\n");
	else{
		excluirNode(r, nome);
		printf("\nO contato '%s' foi excluído com sucesso\n", nome);
	}
}