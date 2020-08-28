#include <stdio.h>
#include "bst.h"

int main(int argc, char *argv[]) {
	no * arvore;
	//inicialização da arvore
	arvore = NULL;
	int opcao;
	no* temp = NULL;
	no *retorno;
	do {
		scanf("%d", &opcao);
		switch(opcao) {
                int chave;
    		case 1: 
        		scanf("%d", &chave);                
				arvore = inserir(arvore, chave);
                break;
			case 2:
				preorder(arvore);				
                break;
            case 3:
            	inorder(arvore);
            	break;
            case 4:
            	posorder(arvore);
            	break;
            case 5:
            	scanf("%d", &chave);
            	arvore = remover(arvore, chave);
            	break;
            case 6:
            	printf("%d ", maior(arvore));
            	break;
            case 7:
            	printf("%d ", menor(arvore));
            	break;
            case 8:
            	printf("%d ", altura(arvore));
            	break;
            case 9:
            	printf("%d ", quantidade_elementos(arvore));
            	break;
            case 10:
            	scanf("%d", &chave);
            	printf("%d ", existe(arvore, chave));
            	break;
            case 11:
            	temp = inserir(temp, -1);
            	scanf("%d", &chave);
            	retorno = predecessor(arvore, chave, temp);
            	printf("%d ", retorno->chave);
            	break;
            case 12:
            	temp = inserir(temp, -1);
            	scanf("%d", &chave);
            	retorno = sucessor(arvore, chave, temp);
            	printf("%d ", retorno->chave);
            	break;
			default:
				;
		}

	} while(opcao != 99);
} 
