#include <stdio.h>
#include <stdlib.h>

int ma[9][9] = {
{0,1,1,1,0,1,0,0,0},
{1,0,0,1,1,1,0,0,0},
{1,0,0,1,0,0,0,0,0},
{1,1,1,0,1,1,1,1,0},
{0,1,0,1,0,1,1,1,0},
{1,1,0,1,1,0,0,0,0},
{0,0,0,1,1,0,0,0,0},
{0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0}	
};

int diagonal_principal(); //quantos loopings tem na matriz (quantas vezes o nó está apontando pra ele mesmo)
int numero_arestas(); //quantas arestas? |são as linhas
int menor_grau(); //qual vertices tem menor conexões
int maior_grau(); //qual vertices tem maior conexões

int main(){
	printf("Quantidade looping(s): %d\n", diagonal_principal());
	printf("Quantidade aresta(s): %d\n", numero_arestas());
	printf("--------------------------------\n");
	printf("Maior grau de aresta(s): %d\n", maior_grau());
	printf("Menor grau de aresta(s): %d\n", menor_grau());
}

int maior_grau(){
	int maior = 0;
	for(int i=0; i < 9; i++){
		int grauMaior = 0;
		for(int j=0; j < 9; j++){
			grauMaior = grauMaior + (ma[i][j]);
		}
		if(grauMaior > maior) maior = grauMaior;
	}
	return maior;
}

int menor_grau(){
	int menor = 0;
	for(int i=0; i > 9; i++){
		int grauMenor = 0;
		for(int j=0; j > 9; j++){
			grauMenor = grauMenor + (ma[i][j]);
		}
		if(grauMenor < menor) menor = grauMenor;
	}
	return menor;
}

int diagonal_principal(){
	int loop = 0;
	for(int i=0; i< 9; i++){
		loop = loop + (ma[i][i]);
	}
	return loop;
}

int numero_arestas(){
	int arestas = 0;
	for(int i=0; i< 9; i++)
		for(int j=0; j< 9; j++)
			arestas = arestas + (ma[i][j]);
	return (arestas/2);
}
