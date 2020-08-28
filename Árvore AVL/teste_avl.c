#include <stdio.h>
#include <stdlib.h>
#include "avl.c"

int main(int argc, char * argv[]){
	arvore teste;
	int caso;
	teste = NULL;

	while(1){
		scanf("%d", &caso);
		switch(caso){
			int valor;
			int controle;
			case 1:
					scanf("%d", &valor);
					teste = inserir(valor, teste, &controle);
					break;
			case 2:
					pre_order(teste);
					break;
			case 3:
					scanf("%d", &valor);
					teste = remover(valor, teste, &controle);
					break;
			case 999:
					exit(0);
		}
	}
}