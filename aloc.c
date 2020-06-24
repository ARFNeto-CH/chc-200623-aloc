#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x; // coordenada x
	float y; // coordenada y
}	Ponto;

typedef struct
{
	int     N;  // numero de vertices
	Ponto** v;  // ponteiro para os ponteiros para vertices
}	PlanoA;

typedef struct
{
	int     N;  // numero de vertices
	Ponto   v[];// ponteiro para um vetor de vertices
}	PlanoB;

PlanoA*   _pol_criaA(const unsigned);
PlanoB*   _pol_criaB(const unsigned);

int main(int argc, char** argv)
{
	printf("(Usando Ponto** v ) tamanho da struct = %d\n", sizeof(PlanoA));
	printf("(Usando Ponto   v[] ) vetor de Pontos] tamanho da struct = %d\n", sizeof(PlanoB));
	int N = 4;
	PlanoA* QuatroL = _pol_criaA(N);
	printf("\n[Usando vetor de ponteiros para Ponto] %2d Vertices:\n",
		QuatroL->N);
	for (int i = 0; i < QuatroL->N; i += 1)
	printf("%2d: (%4.2f,%4.2f)\n", i,
		QuatroL->v[i]->x,
		QuatroL->v[i]->y);

	PlanoA Hexa;
	Hexa.N = 6;
	Hexa.v = NULL;

	Ponto   ponto1 = { 12.34f, 34.56f };
	PlanoB* HexaB = _pol_criaB(6);

	printf("\n[Usando vetor de Ponto] %2d Vertices:\n", HexaB->N);
	for (int i = 0; i < HexaB->N; i += 1)
		printf("%2d: (%4.2f,%4.2f)\n", i,
			HexaB->v[i].x,
			HexaB->v[i].y);

	printf("\n[Mudando o vertice 4 para [%4.2f,%4.2f]\n",
		ponto1.x, ponto1.y);
	HexaB->v[4] = ponto1;

	printf("[Usando vetor de Ponto] %2d Vertices:\n", HexaB->N);
	for (int i = 0; i < HexaB->N; i += 1)
		printf("%2d: (%4.2f,%4.2f)\n", i,
			HexaB->v[i].x,
			HexaB->v[i].y);


	return 0;
}


PlanoA* _pol_criaA(const unsigned vertices)
{
	// cria o obvio: o poligono
	PlanoA* pol = (PlanoA*)malloc(sizeof(PlanoA));
	pol->N = vertices; // claro

	// agora aloca o vetor de ponteiros para os vertices
	pol->v = (Ponto**)malloc(vertices * sizeof(Ponto*));
	for (unsigned i = 0; i < vertices; i += 1)
	{
		// agora cria e coloca um valor em cada vertice
		// so pra testar
		pol->v[i] = (Ponto*)malloc(sizeof(Ponto));
		pol->v[i]->x = i / 10.f, pol->v[i]->y = 2.5f * i;
	};	// for()
	return pol; // e afinal retorna o poligono criado
}


PlanoB* _pol_criaB(const unsigned N)
{
	// cria o obvio: o PlanoB
	int tam = sizeof(PlanoB) + N * sizeof(Ponto);
	printf("\nv[]: vertices = %d, tam = %d tam Ponto = %d\n",
		N, tam, sizeof(Ponto));
	PlanoB* pol = (PlanoB*)malloc(tam);
	pol->N = N; // claro

	// agora preenche o vetor de ponteiros para os vertices
	for (unsigned i = 0; i < N; i += 1)
	{
		// agora cria e coloca um valor em cada vertice
		pol->v[i].x = i / 10.f, pol->v[i].y = 2.5f * i;
	};	// for()
	return pol; // e afinal retorna o poligono criado
}

// fim
// https://www.clubedohardware.com.br/topic/1459604-aloca%C3%A7%C3%A3o-din%C3%A2mica-em-c/
