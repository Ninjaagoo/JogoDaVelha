![Ícone da linguagem C](c-icon.svg)

# Jogo da Velha

**Desenvolvido por: Ninjaagoo**

Este jogo da velha foi desenvolvido para estudar C e praticar o uso de matrizes. É possível jogar com outra pessoa ou contra o computador.

<img src="slaLegal.jpg" alt="Pelúcia com fones de ouvido e gorro" width="250">

## Como iniciar no Windows

1. Instale um compilador C, como o **GCC**, caso ainda não tenha um. Para conferir se ele está disponível, abra um terminal e digite `gcc --version`.
2. Baixe o projeto pelo botão **Code > Download ZIP** no GitHub e extraia o arquivo. Se você já tem a pasta do projeto no computador, pode usar essa pasta.
3. Abra a pasta extraída no VS Code e escolha **Terminal > Novo Terminal**. O terminal deve estar na mesma pasta do arquivo `jogo_velha_10.c`.
4. Compile o jogo:

```powershell
gcc jogo_velha_10.c -o jogo_velha_10.exe
```

5. Inicie o programa no mesmo terminal:

```powershell
.\jogo_velha_10.exe
```

O jogo recebe comandos digitados. Por isso, execute no **terminal**, e não na aba **Saída** do VS Code.

## Como jogar

1. Quando aparecer **Pressione ENTER para ir ao menu**, pressione **Enter**.
2. No menu, digite `1` e pressione **Enter** para iniciar uma partida. O modo inicial é **dois jogadores**.
3. O jogador **X** começa. Digite o número da **linha** e pressione **Enter**; depois digite o número da **coluna** e pressione **Enter**. Cada número deve ser de `0` a `2`.
4. No modo de dois jogadores, o jogador **O** faz a próxima jogada da mesma forma. No modo contra o computador, o programa escolhe a jogada de O.
5. Repita os turnos até alguém completar uma linha, coluna ou diagonal. Se todas as casas forem ocupadas sem vencedor, a partida termina em empate.

As linhas são numeradas de cima para baixo e as colunas da esquerda para a direita. Por exemplo, **linha `1` e coluna `2`** escolhe a casa do meio, à direita.

### Opções do menu

- `1` — Jogar. Cada nova partida começa com o tabuleiro vazio.
- `2` — Configurações. Escolha `1` para jogar contra o computador ou `2` para jogar com outra pessoa. Depois, volte ao menu e escolha **Jogar**.
- `3` — Ver o placar das partidas jogadas enquanto o programa está aberto.
- `4` — Sair. Ao fechar o programa, o placar é zerado.
