#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void limpar_tabuleiro(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }
}

int venceu(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }

    return (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
           (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador);
}

int main(){
// variáveis e vetores
 char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}}; //Tabuleiro do jogo
int linha, coluna, linha_computador, coluna_computador; //Linhas e colunas para jogador e computador
int vencedor_X = 0, vencedor_O = 0, vencedor_maquina = 0; //decisao de vitroria
int opcao; // opcoes para decidir oque fazer 
int opcao_computador_jogador= 2; // Decisao de jogar contra maquina ou outro jogador
int fim_x = 0, fim_o = 0, deu_velha = 0; //finalizar as decisoes
srand(time(NULL)); //randonizador para o computador jogar

do{
    
printf("\n===== JOGO DA VELHA =====\n");
 printf("Pressione ENTER para ir ao menu");
    getchar();
    
system("cls");
//menu
printf("\n===== JOGO DA VELHA =====\n");

printf("\n----------------");
printf("\n|     MENU     |\n");
printf("----------------\n");


printf("[1] Jogar\n");
printf("[2] Configuracoes\n");
printf("[3] Placar\n");
printf("[4] Sair\n");
printf("Escolha uma opcao: ");
scanf("%d", &opcao);
getchar(); 
// lógica do jogo
switch (opcao){
case 1:
limpar_tabuleiro(tabuleiro);
fim_x = 0;
fim_o = 0;

if(opcao_computador_jogador == 1) {

while(1){
// Jogador X

do{
    printf("Digite a linha voce e 'X' (0-2): ");
    scanf("%d", &linha);
getchar();
    printf("Digite a coluna voce e 'X' (0-2): ");
    scanf("%d", &coluna);
getchar();

if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
    if (tabuleiro[linha][coluna] == ' '){
            tabuleiro[linha][coluna] = 'X';
            fim_x = 1; 
            } 
else{
            printf("Posicao ja ocupada! Tente novamente.\n");
            fim_x = 0; 
        }
    }
}
while(fim_x == 0);

system("cls");
// Exibir o tabuleiro após a jogada do jogador X
 printf("\n  f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }                                                    //Fim do loop para exibir o tabuleiro 
   
// Verificar vencedor X 
if (venceu(tabuleiro, 'X')) {

printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }                                                    


    printf("Jogador 'X' venceu!\n");
    vencedor_X++;
    break;}

else if(tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2] != ' ' &&
        tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' ' && tabuleiro[1][2] != ' ' &&
        tabuleiro[2][0] != ' ' && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

            printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

        printf("Deu velha! Ninguem venceu.\n");
        deu_velha++;
        break;
    }

do{
    // computador O

linha_computador = rand() % 3;
coluna_computador = rand() % 3;

if(linha_computador >= 0 && linha_computador < 3 && coluna_computador >= 0 && coluna_computador < 3) {
        if (tabuleiro[linha_computador][coluna_computador] == ' ') {
            tabuleiro[linha_computador][coluna_computador] = 'O';
            fim_o = 1; // Jogada válida, permitir que o jogador X jogue
        } else {
            printf("Posicao ja ocupada! Tente novamente.\n");
            fim_o = 0; // Permitir que o computador 'O' jogue novamente
        }
    }

}while(fim_o == 0);
    
                                                                        // Exibir o tabuleiro após a jogada do jogador O

    printf("\n  f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
        }
                                                                        //Fim do loop para exibir o tabuleiro

                                                           
    //verificar vencedor O

if (venceu(tabuleiro, 'O')) {

        printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

    printf("Computador 'O' venceu!\n");
    vencedor_maquina++;
    break;  

}
else if(tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2] != ' ' &&
         tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' ' && tabuleiro[1][2] != ' ' &&
         tabuleiro[2][0] != ' ' && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

            printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

        printf("Deu velha! Ninguem venceu.\n");
        deu_velha++;
    break;
        
            }

            
        }


}
   /////////////// =====================Modo de jogo contra outro jogador===================== ///////////////
else{
while(1){
// Jogador X

do{
    printf("Digite a linha voce e X (0-2): ");
    scanf("%d", &linha);
getchar();
    printf("Digite a coluna voce e X (0-2): ");
    scanf("%d", &coluna);
getchar();

if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
    if (tabuleiro[linha][coluna] == ' '){
            tabuleiro[linha][coluna] = 'X';
            fim_x = 1; // Jogada válida, permitir que o jogador O jogue
            } 
else{
            printf("Posicao ja ocupada! Tente novamente.\n");
            fim_x = 0; // Permitir que o jogador X jogue novamente
        }
    }
}while(fim_x == 0);
system("cls");
                                          // Exibir o tabuleiro após a jogada do jogador X
 printf("\n  f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
}
                                                                    //Fim do loop para exibir o tabuleiro 
// Verificar vencedor X 
if (venceu(tabuleiro, 'X')) {

    printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
    }   

    printf("Jogador X venceu!\n");
    vencedor_X++;
    break;}

 else if(tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2] != ' ' &&
         tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' ' && tabuleiro[1][2] != ' ' &&
         tabuleiro[2][0] != ' ' && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

            printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

        printf("Deu velha! Ninguem venceu.\n");
        deu_velha++;
        break;
    }

do{
    // Jogador O
    printf("Digite a linha do jogador O (0-2): ");
    scanf("%d", &linha);
getchar();
    printf("Digite a coluna do jogador O (0-2): ");
    scanf("%d", &coluna);
getchar();
if(linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
        if (tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = 'O';
            fim_o = 1; // Jogada válida, permitir que o jogador X jogue
        } 

        else {
            printf("Posicao ja ocupada! Tente novamente.\n");
            fim_o = 0; // Permitir que o jogador O jogue novamente
        }
    }

}while(fim_o == 0);
                                                                        // Exibir o tabuleiro após a jogada do jogador O

    printf("\n  f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
        }
                                                                        //Fim do loop para exibir o tabuleiro

    //verificar vencedor O

if (venceu(tabuleiro, 'O')) {

        printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

    printf("Jogador O venceu!\n");
    vencedor_O++;
    break;  

}
else if(tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2] != ' ' &&
         tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' ' && tabuleiro[1][2] != ' ' &&
         tabuleiro[2][0] != ' ' && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {

            printf("\n f0   f1   f2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
             
    }
        printf("\n");
if (i < 2) printf("  ---|---|---\n");
        }   

        printf("Deu velha! Ninguem venceu.\n");
        deu_velha++;
            break;
        
            }

        }

    }   
        break;
case 2:
system("cls");
do{
printf("\nCONFIGURACOES DO JOGO\n");
    printf("===============================\n");
    printf("[1] Jogar contra o COMPUTADOR\n");
    printf("[2] Jogar contra outro JOGADOR\n");
    printf("===============================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_computador_jogador);
    getchar();
    

    if(opcao_computador_jogador == 1) {
    printf("Modo de jogo contra o computador ativado!\n");
        printf("CONFIGURACOES ATUALIZADAS!\n");
} else if (opcao_computador_jogador == 2) {
    printf("Modo de jogo contra outro jogador ativado!\n");
        printf("CONFIGURACOES ATUALIZADAS!\n");
}


}while(opcao_computador_jogador < 1 || opcao_computador_jogador > 2);

break;

case 3:
system("cls");
   printf("===============\n");
    printf("PLACAR ATUAL\n");
    printf("===============================\n");    
    printf("Jogador X: %d vitorias\n", vencedor_X);
    printf("Jogador O: %d vitorias\n", vencedor_O);
    printf("Contra a Maquina: %d vitorias\n", vencedor_maquina);
    printf("Velhas: %d\n", deu_velha);
    printf("===============================\n");

    break;
case 4:

printf("Encerrando o jogo...\n");
    break;

default:
    printf("Ops... parece que deu algo errado, tente novamente!\n");
    break;
}

if(opcao < 1 || opcao > 4){
    printf("Opcao invalida! Tente novamente.\n");
}

}while(opcao != 4);
    printf("JOGO ENCERRADO! \n");

    return 0;
}
