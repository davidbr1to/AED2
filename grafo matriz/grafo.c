#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void inicializar (grafo *g, int tamanho) {
	int i,j;
	g->v = tamanho;
	g->mapa = (char *) malloc(sizeof(char) * tamanho);
	g->matriz = (long **) malloc(sizeof(long) * tamanho);
	for(i =0; i < tamanho; i++)
		g->matriz[i] = (long *) malloc(sizeof(long) * tamanho);

	for(i =0; i < tamanho; i++) {
		for(j=0; j < tamanho; j++) {
				if(i==j) {
					g->matriz[i][j] = 1;
				} else {
					g->matriz[i][j] = 0;
				}
		}
	}
}

/*void ler_arquivo_grafo(grafo *g, char caminho[]){
	int i;
	int vertices = -1;
	int arestas = -1;
	char t1, t2, t3, t4;
	FILE *arq = fopen(caminho, "rt");
	if(arq != NULL){
		fscanf(arq, "%d %d", &vertices, &arestas);
		inicializar(g, vertices);
		for(i=0; i<vertices; i++){
			fscanf(arq, "%c %c", &t1,&t2);
			g->mapa[i] = t2;
			struct vertice* novo = (vertice*)malloc(sizeof(vertice));
			novo->letra = t2;
			novo->d = 0;
			novo->pi = NULL;
			novo->cor = BRANCO;
			novo->f = 0;
			novo->index = i;
		}
		for(i=0; i<arestas; i++){
			fscanf(arq, "%c%c%c", &t1,&t2,&t3);
			adicionarAresta(g, t3, t4);
		}
		fclose(arq);
	}
}*/

void ler_arquivo_grafo(grafo*g ,char caminho[]){
		int i;
		int vertices = -1;
		int arestas = -1;
		char t1;//\n's
		char t2;//vertices
		char t3;
		char t4;
		FILE *arq = fopen(caminho,"rt");
		if(arq != NULL){
			fscanf(arq,"%d %d",&vertices,&arestas);
			inicializar(g,vertices);
		  for(i=0;i<vertices;i++){//vertices no t2
				fscanf(arq,"%c %c",&t1,&t2);
				g->mapa[i]=t2;//atualizacao do mapa
				struct vertice* novo = (vertice*)malloc(sizeof(vertice));
				novo->letra = t2;
				novo->d = 0;
				novo->pi = NULL;
				novo->cor = BRANCO;
				novo->f = 0;
				novo->index = i;
				g->vertices[i] = novo;
			}
			for(i=0;i<arestas;i++){//aresta entre t3 e t4
				fscanf(arq,"%c%c%c",&t1,&t3,&t4);
				adicionarAresta(g,t3,t4);
			}
			fclose(arq);
		}
}


void imprimir(grafo *g) {
		int i,j;
		for(i=0;i<(g->v);i++){
			printf("\t%c",g->mapa[i]);
		}
		printf("\n\n");
		for(i =0; i < g->v; i++) {
				printf("%c",g->mapa[i]);
				for(j = 0; j < g->v; j++) {
						printf("\t%ld", g->matriz[i][j]);
				}
				printf("\n");
		}
}

void adicionarAresta(grafo *g, char v1, char v2){
	int i, pos1,pos2;
	for(i=0;i<(g->v);i++){
		if(v1 == g->mapa[i]){
			pos1 = i;
		}
		if(v2 == g->mapa[i]){
			pos2 = i;
		}
	}
	g->matriz[pos1][pos2] = 1;
	g->matriz[pos2][pos1] = 1;
}

int verifAdj(grafo* g, char v1, char v2){
	int i, posi1, posi2;
	for(i=0; i<g->v; i++){
		if(g->mapa[i] == v1){
			posi1 = i;
		}
		if (g->mapa[i] == v2){
			posi2 = i;
		}
	}
	if(g->matriz[posi1][posi2] == 1){
		return 1;
	}
	else{
		return 0;
	}
}

void DFS(grafo * g){
	int i;
	for(i=0; i<g->v; i++){
		g->vertices[i]->cor = BRANCO;
		g->vertices[i]->pi = NULL;
	}
	int tempo = 0;
	for(i = 0; i < g->v; i++){
		if(g->vertices[i]->cor == BRANCO)
			tempo = DFS_VISIT (g, g->vertices[i], tempo);
		}
		for(i=0; i<g->v; i++){
			printf("%c: %d - %d\n", g->vertices[i]->letra, g->vertices[i]->d, g->vertices[i]->f);
		}
}

int DFS_VISIT(grafo *g, vertice * u, int tempo){
	u->cor = CINZA;
	tempo +=1;
	u->d = tempo;
	int i;
	for(i=0; i<g->v; i++){
		if(verifAdj(g, g->vertices[i]->letra, u->letra) & g->vertices[i]->letra != u->letra){
			if(g->vertices[i]->cor == BRANCO){
				g->vertices[i]->pi = u;
				tempo = DFS_VISIT(g, g->vertices[i], tempo);
			}
		}
	}
	u->cor = PRETO;
	tempo = tempo+1;
	u->f = tempo;
	return tempo;
}

int main(int argc, int* argv) {
	grafo g;
	char diretorio[100];
	scanf("%s",diretorio);
	ler_arquivo_grafo(&g,diretorio);
	imprimir(&g);
	//BGS(&g,'S');//busca em largura
	DFS(&g);//busca em profundidade

}