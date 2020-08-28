#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


no* inserir(no *raiz, int chave) {
	//Caso Base
	if(raiz == NULL) {
		no * novo;
		//Passo 1 - Alocar memória
		novo = (no*) malloc (sizeof(no)); 
		//Passo 2 - Inicializar Valores
		novo->chave = chave;
		novo->esq = NULL;
		novo->dir = NULL;
		//Passo 3 - Retornar o ponteiro para o nó que foi criado
		return novo;
	} else {
		//Verificar se o valor deve ser inserido na esquerda (<) ou direita (>)
		if(chave >= raiz->chave) {
			raiz->dir = inserir(raiz->dir, chave);
		} else {
			raiz->esq = inserir(raiz->esq, chave);				
		}
		return raiz;		
	}
}

void preorder(no *raiz) {
	if(raiz != NULL) {
		printf("[%d]", raiz->chave);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

void inorder(no *raiz) {
	if(raiz != NULL) {
		inorder(raiz->esq);
		printf("[%d]", raiz->chave);
		inorder(raiz->dir);
	}
}

void posorder(no *raiz) {
	if(raiz != NULL) {
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->chave);
	}
}

no* remover(no *raiz, int chave){
	if (raiz==NULL){
		return NULL;
	}
	if (raiz->chave == chave){
		if(raiz->esq == NULL){
			return raiz->dir;;
		}
		if (raiz->dir == NULL){
			return raiz->esq;
		}
		raiz->chave = maior(raiz->esq);
		raiz->esq = remover(raiz->esq, raiz->chave);
	}
	if (chave > raiz->chave){
		raiz->dir = remover(raiz->dir, chave);
		}else{
		raiz->esq = remover(raiz->esq, chave);
		}
	return raiz;
}

int maior(no *raiz){
	if (raiz == NULL){
		return -1;
	}
	if (raiz->dir == NULL){
		return raiz->chave;
	}
	else{
		return maior(raiz->dir);
	}
}

int menor (no *raiz){
	if (raiz == NULL){
		return -1;
	}
	if (raiz->esq == NULL){
		return raiz->chave;
	}
	else{
	return menor(raiz->esq);
	}
}

int maior_entre(int valor1, int valor2){
	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
		}
}

int altura(no *raiz){
	if (raiz== NULL){
		return -1;
	}
	return 1 + maior_entre(altura(raiz->dir), altura(raiz->esq));
}

int quantidade_elementos(no* raiz){
	if (raiz == NULL){
		return 0;
	}
	int esquerda = quantidade_elementos(raiz->esq);
	int direita = quantidade_elementos(raiz->dir);
	return  1 + esquerda + direita;

}

int existe(no* raiz, int chave){
	if (raiz == NULL){
		return 0;
	}
	if (chave == raiz->chave){
		return 1;
	}
	if (chave > raiz->chave){
		return existe(raiz->dir, chave);
	}
	else{
		return existe(raiz->esq, chave);
	}
}

no* predecessor(no *raiz, int chave, no *temp){
	if (raiz == NULL){
		return NULL;
	}
	else if (raiz != NULL){
		if (chave < raiz->chave){
			predecessor(raiz->esq, chave, temp);
		}
		else if (chave > raiz->chave){
			if (raiz->chave > temp->chave){
				temp->chave = raiz->chave;
			}
			predecessor(raiz->dir, chave, temp);
		}
		else{
			if (raiz->esq == NULL){
				temp->chave = chave;
				return temp;
			}

		else{
			if (temp->chave > raiz->esq->chave){
			return temp;
		}

		else{
			raiz = raiz->esq;
			while (raiz->dir !=NULL){
				raiz = raiz->dir;
			}
			return raiz;
		}
		}
	}
}
}

no* sucessor(no *raiz, int chave, no *temp){
	if (raiz == NULL){
		return NULL;
	}else{
		if (temp->chave < chave){
			temp->chave = raiz->chave;
		}
		if (chave < raiz->chave){
			if (raiz->chave < temp->chave){
				temp->chave = raiz->chave;
		}
			sucessor(raiz->esq, chave, temp);
		}
	else if (chave > raiz->chave){
		sucessor(raiz->dir, chave, temp);
	}
	else {
		if(raiz->dir == NULL && temp->chave < chave){
			return NULL;
		}
		else if(raiz->dir == NULL){
			return temp;
		}
		else if(temp->chave <= chave || raiz->dir->chave < temp->chave) {
			raiz = raiz->dir;
			while (raiz->esq !=NULL){
				raiz = raiz->esq;
			}
			return raiz;
		}
	else{
		return temp;
	}
	}
	}
}