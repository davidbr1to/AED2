#ifndef GRAFO_H
#define GRAFO_H

typedef enum {BRANCO=0, CINZA=1, PRETO=2} cor_vertice;

typedef struct grafo {
	int v;
	char *mapa;
	long **matriz;
	struct vertice* vertices[]; //Array de vértices para a DFS (Busca Profundidade)
} grafo;

typedef struct vertice{
    int index;
    char letra;
		cor_vertice cor;
		int d;
		int f;
		struct vertice* pi;
}vertice;

void inicializar (grafo *g, int tamanho);

void imprimir(grafo *g);

void ler_arquivo_grafo(grafo *g, char caminho[]);

void adicionarAresta(grafo *g, char v1, char v2);

int verifAdj(grafo* g, char v1, char v2);

void DFS(grafo * g); //Busca Profundidade

int DFS_VISIT(grafo* g, vertice * u, int tempo);

#endif