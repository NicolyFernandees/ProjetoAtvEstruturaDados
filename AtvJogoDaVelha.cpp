#include <stdlib.h>
#include <stdio.h>


void iniciar(); //cria a matriz
void jogar(); //Quem? Posição? | Linha e Coluna
void verifica_ganhador(int linha, int coluna, char letra); //verifica o ganhador do jogo
void finalizar(); //finaliza o jogo da velha. após verificar vencedor
void mostrar_matriz(); //exibe as linhas e colunas


char jogo_da_velha [3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

char jogador = ' ';
int main(){
	mostrar_matriz();
	//printf("\n------ Jogo da Velha ------\n");
	jogador = 'x';
	jogar();
	
	
	return 0;
}

void valida_linha(int linha, int coluna, char letra){
	if(jogo_da_velha[1][0] == letra && jogo_da_velha[1][0] == letra && jogo_da_velha[1][0] == letra) return 1;
	return 0;
}

void valida_coluna(int coluna, char letra){
	if(jogo_da_velha[0][coluna] == letra && jogo_da_velha[1][coluna] == letra && jogo_da_velha[2][coluna] == letra) return 1;
	return 0;
}

void valida_diag_p(int coluna, char letra){
	if(jogo_da_velha[coluna][coluna] == letra && jogo_da_velha[coluna][coluna] == letra && jogo_da_velha[coluna][coluna] == letra) return 1;
	return 0;
}

void valida_diag_s(char letra){
	if(jogo_da_velha[0][2] == letra && jogo_da_velha[1][1] == letra && jogo_da_velha[2][0] == letra) return 1;
	return 0;
}


void verifica_jogador(int linha, int coluna, char letra){
	if(linha == coluna) return valida_diag_p(coluna, letra);
	if((linha == 0 && coluna == 2) || (linha == 1 && coluna == 1) || (linha == 2 && coluna == 0)) return valida_diag_s(linha);
	
	return valida_linha(linha, letra);
	return valida_coluna(coluna, letra);
}

void troca_jogador(){
	if(jogador == 'x') jogador = 'o';
	else jogador = 'x';
}

void jogar(){
	int linha, coluna;
	printf("Escolher a linha: \n");
	scanf("%d", &linha);
	printf("Escolher a coluna: \n");
	scanf("%d", &coluna);
	
	//validar jogada... while
	jogo_da_velha[linha -1 ][coluna -1 ] = jogador;
	mostrar_matriz();
	troca_jogador();
};

void mostrar_matriz(){
	int linha;
	int coluna;
	for(linha = 0; linha < 3; linha++){
		printf("|");
		for(coluna = 0; coluna < 2; coluna++){
			printf("%c, ", jogo_da_velha[linha][coluna]);
		}
			printf("%c ", jogo_da_velha[linha][2]);
			printf("|\n");
	}
			printf("|\n");
};
