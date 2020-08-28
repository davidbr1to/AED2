#ifndef BST_H
#define BST_H
typedef struct no {
	int chave;
	struct no *esq;
	struct no *dir;	
} no;
//Op 1
no* inserir(no *raiz, int chave);
//Op 2
void preorder(no *raiz);
//Op 3
void inorder(no *raiz);
//Op 4
void posorder(no *raiz);
//Op 5
no* remover(no *raiz, int chave);
//Op 6
int maior(no *raiz);
//Op 7
int menor(no *raiz);
//Função auxiliar para a Op8
int maior_entre(int valor1, int valor2);
//Op 8
int altura(no *raiz);
//Op 9
int quantidade_elementos(no *raiz);
//Op 10
int existe(no *raiz, int chave); //Retornar 1(existe) ou 0(não existe)
//Op 11
no* predecessor(no *raiz, int chave, no *temp);
//Op 12
no* sucessor(no *raiz, int chave, no *temp);




#endif
