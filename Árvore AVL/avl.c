#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void inicializar(arvore *raiz){
    *raiz == NULL;
}

arvore inserir(int valor, arvore raiz, int *cresceu){
    if(raiz == NULL){
        arvore novo = (arvore)malloc(sizeof(struct node_avl));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->FB = 0;
        *cresceu = 1;
        return novo;
    } else {
        if(valor>raiz->valor){
            raiz->direita = inserir(valor, raiz->direita, cresceu);
            if(*cresceu){
                switch(raiz->FB){
                    case 0:
                            raiz->FB = 1;
                            *cresceu = 1;
                            break;
                    case -1:
                            raiz->FB = 0;
                            *cresceu = 0;
                            break;
                    case 1:
                            raiz->FB = 2;
                            cresceu = 0;
                            return rotacionar(raiz);
                }
            }
        } else{
            raiz->esquerda = inserir(valor, raiz->esquerda, cresceu);
            if(*cresceu){
                switch(raiz->FB){
                    case 0:
                            raiz->FB = -1;
                            *cresceu = 1;
                            break;
                    case -1:
                            raiz->FB = -2;
                            *cresceu = 0;
                            return rotacionar(raiz);
                    case 1:
                            raiz->FB = 0;
                            cresceu = 0;
                            break;
                }
            }
        }
        return raiz;
    }
}

int maior_elemento(arvore raiz){
    if (raiz == NULL){
        return -1;    
    }
    if (raiz->direita == NULL){
        return raiz->valor; 
    }
    else{
    return maior_elemento(raiz->direita);
    }
}

arvore remover(int valor, arvore raiz, int *diminuiu){
    if(raiz==NULL){
        return NULL;
    }
    if (raiz->valor == valor){
        *diminuiu = 1;
        if(raiz->esquerda == NULL){
            return raiz->direita;
        }
        else if(raiz->direita == NULL){
            return raiz->esquerda;
        }else{
            raiz->valor = maior_elemento(raiz->esquerda);
            raiz->esquerda = remover(raiz->valor, raiz->esquerda, diminuiu);
            if(*diminuiu){
                switch(raiz->FB){
                    case 0:
                            raiz->FB = 1;
                            *diminuiu = 0;
                            break;
                    case -1:
                            raiz->FB = 0;
                            break;
                    case 1:
                            raiz->FB = 2;
                            if(raiz->direita->FB==0){
                            *diminuiu = 0;
                            }else{
                            *diminuiu = 1;
                            }
                            return rotacionar(raiz);
                }
            }
        }
    }
    else if(valor>raiz->valor){
        raiz->direita = remover(valor, raiz->direita, diminuiu);
        if(*diminuiu){
            switch(raiz->FB){
                case -1:
                        raiz->FB = -2;
                        if(raiz->esquerda->FB==0){
                            *diminuiu = 0;
                        }else{
                            *diminuiu = 1;
                        }
                        return rotacionar(raiz);
                case 0:
                        raiz->FB = -1;
                        *diminuiu = 0;
                        break;
                case 1:
                        raiz->FB = 0;
                        break;

            }
        }
    } else if(valor< raiz->valor){
        raiz->esquerda = remover(valor, raiz->esquerda, diminuiu);
        if(*diminuiu){
            switch(raiz->FB){
                case 0:
                    raiz->FB = 1;
                    *diminuiu = 0;
                    break;
                case -1:
                        raiz->FB = 0;
                        *diminuiu = 1;
                        break;
                case 1: 
                        raiz->FB = 2;
                        if(raiz->direita->FB == 0){
                            *diminuiu = 0;
                        }else{
                            *diminuiu = 1;
                        }
                        return rotacionar(raiz);
            }
        }
    }
    return raiz;
}

void pre_order(arvore raiz){;
    if(raiz!=NULL){
        printar_elemento(raiz);
        pre_order(raiz->esquerda);
        pre_order(raiz->direita);    
    };
}

void printar_elemento(arvore raiz) {
    printf("[%d,%d]", raiz->valor, raiz->FB);
}

arvore rotacionar(arvore raiz){
    if(raiz->FB > 0){
        switch (raiz->direita->FB){
            case 0:
                    return rotacao_simples_esquerda(raiz);
                    break;
            case 1: 
                    return rotacao_simples_esquerda(raiz);
                    break;
            case -1:
                    return rotacao_dupla_esquerda(raiz);
                    break;
        }
    } else{
        switch (raiz->esquerda->FB){
            case 0:
                    return rotacao_simples_direita(raiz);
                    break;
            case 1:
                    return rotacao_dupla_direita(raiz);
                    break;
            case -1: 
                    return rotacao_simples_direita(raiz);
                    break;
        }
    }
}

arvore rotacao_simples_direita(arvore p){
    arvore u, t2;

    u = p->esquerda;
    t2 = u->direita;

    p->esquerda = t2;
    u->direita = p;

    if(u->FB ==0){
        p->FB = -1;
        u->FB = 1;
    }else{
        p->FB = 0;
        u->FB = 0;
    }
    return u;
}

arvore rotacao_simples_esquerda(arvore p){
    arvore u, t2;

    u = p->direita;
    t2 = u->esquerda;
    p->direita = t2;
    u->esquerda = p;

    if(u->FB ==0){
        p->FB = 1;
        u->FB = -1;        
    }else{
        p->FB = 0;
        u->FB = 0;
    }
    return u;
}

arvore rotacao_dupla_direita(arvore p){
    arvore u, v, t2, t3;

    u = p->esquerda;
    v = u->direita;
    t2 = v->esquerda;
    t3 = v->direita;

    u->direita = t2;
    v->esquerda = u;
    p->esquerda = v;

    p->esquerda = t3;
    v->direita = p;

    switch(v->FB){
        case 0:
                u->FB = 0;
                p->FB = 0;
                break;
        case 1:
                u->FB = -1;
                p->FB = 0;
                v->FB = 0;
                break;
        case -1:
                u->FB = 0;
                p->FB = 1;
                v->FB = 0;
                break;
    }
    return v;
}

arvore rotacao_dupla_esquerda(arvore p){
    arvore u, v, t2, t3;
    u = p->direita;
    v = u->esquerda;
    t2 = v->esquerda;
    t3 = v->direita;

    u->esquerda = t3;
    v->direita = u;
    p->direita = v;


    p->direita = t2;
    v->esquerda = p;

    switch(v->FB){
        case 0:
                p->FB = 0;
                u->FB = 0;
                break;
        case 1:
                u->FB = 0;
                p->FB = -1;
                v->FB = 0;
                break;
        case -1:
                u->FB = 1;
                p->FB = 0;
                v->FB = 0;
                break;
    }
    return v;
}