#ifndef AVL_H
#define AVL_H


typedef struct node_avl{
    struct node_avl *esquerda, *direita;
    int valor;
    int FB;
} node_avl;

typedef node_avl * arvore;

void inicializar(arvore *raiz);
arvore inserir(int valor, arvore raiz, int *cresceu);
void pre_order(arvore raiz);
void printar_elemento(arvore raiz);
int maior_elemento(arvore raiz);
arvore remover(int valorr, arvore raiz, int *diminuiu);
arvore rotacionar(arvore raiz);
arvore rotacao_simples_direita(arvore raiz);
arvore rotacao_simples_esquerda(arvore raiz);
arvore rotacao_dupla_direita(arvore raiz);
arvore rotacao_dupla_esquerda(arvore raiz);

#endif
