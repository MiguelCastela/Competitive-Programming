import java.util.Random;
import java.util.Scanner;

public class Game {

    // Inicializa o tabuleiro com 2 peças aleatórias
    private static void initializeTabuleiro(int[][] tabuleiro) {
        addRandomPeca(tabuleiro);
        addRandomPeca(tabuleiro);
    }

    // Adiciona uma nova peça em uma posição aleatória vazia
    private static void addRandomPeca(int[][] tabuleiro) {
        Random rand = new Random();
        int row, col;
        do {
            row = rand.nextInt(4);
            col = rand.nextInt(4);
        } while (tabuleiro[row][col] != 0);
        tabuleiro[row][col] = (rand.nextInt(2) + 1) * 2;
    }

    // Imprime o tabuleiro
    private static void printTabuleiro(int[][] tabuleiro) {
        System.out.println("---------------------");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (tabuleiro[i][j] == 0) {
                    System.out.print("|    ");
                } else {
                    System.out.printf("| %2d ", tabuleiro[i][j]);
                }
            }
            System.out.println("|");
            System.out.println("---------------------");
        }
    }

    // Função principal de movimento
    private static int mover(int[][] tabuleiro, String direcao) {
        int pontos = 0;

        // Movimento conforme a direção
        switch (direcao) {
            case "j" -> {
                for (int i = 0; i < 4; i++) {
                    pontos += moverLinhaEsquerda(tabuleiro[i]);
                }
            }
            case "k" -> {
                for (int i = 0; i < 4; i++) {
                    pontos += moverLinhaDireita(tabuleiro[i]);
                }
            }
            case "i" -> {
                for (int j = 0; j < 4; j++) {
                    pontos += moverColunaCima(tabuleiro, j);
                }
            }
            case "m" -> {
                for (int j = 0; j < 4; j++) {
                    pontos += moverColunaBaixo(tabuleiro, j);
                }
            }
            default -> {
                System.out.println("Direção inválida!");
                return 0;
            }
        }

        // Adiciona uma nova peça se houve movimento
        if (pontos > 0) {
            addRandomPeca(tabuleiro);
        }
        return pontos;
    }

    // Funções auxiliares de movimento
    private static int moverLinhaEsquerda(int[] linha) {
        int pontos = 0;
        int[] novaLinha = new int[4];
        int posicao = 0;

        for (int j = 0; j < 4; j++) {
            if (linha[j] != 0) {
                novaLinha[posicao++] = linha[j];
            }
        }

        for (int j = 0; j < 3; j++) {
            if (novaLinha[j] != 0 && novaLinha[j] == novaLinha[j + 1]) {
                novaLinha[j] *= 2;
                pontos += novaLinha[j];
                novaLinha[j + 1] = 0;
            }
        }

        posicao = 0;
        for (int j = 0; j < 4; j++) {
            if (novaLinha[j] != 0) {
                linha[posicao++] = novaLinha[j];
            }
        }
        while (posicao < 4) {
            linha[posicao++] = 0;
        }
        return pontos;
    }

    private static int moverLinhaDireita(int[] linha) {
        int pontos = 0;
        int[] novaLinha = new int[4];
        int posicao = 3;

        for (int j = 3; j >= 0; j--) {
            if (linha[j] != 0) {
                novaLinha[posicao--] = linha[j];
            }
        }

        for (int j = 3; j > 0; j--) {
            if (novaLinha[j] != 0 && novaLinha[j] == novaLinha[j - 1]) {
                novaLinha[j] *= 2;
                pontos += novaLinha[j];
                novaLinha[j - 1] = 0;
            }
        }

        posicao = 3;
        for (int j = 3; j >= 0; j--) {
            if (novaLinha[j] != 0) {
                linha[posicao--] = novaLinha[j];
            }
        }
        while (posicao >= 0) {
            linha[posicao--] = 0;
        }
        return pontos;
    }

    private static int moverColunaCima(int[][] tabuleiro, int coluna) {
        int pontos = 0;
        int[] novaColuna = new int[4];
        int posicao = 0;

        for (int i = 0; i < 4; i++) {
            if (tabuleiro[i][coluna] != 0) {
                novaColuna[posicao++] = tabuleiro[i][coluna];
            }
        }

        for (int i = 0; i < 3; i++) {
            if (novaColuna[i] != 0 && novaColuna[i] == novaColuna[i + 1]) {
                novaColuna[i] *= 2;
                pontos += novaColuna[i];
                novaColuna[i + 1] = 0;
            }
        }

        posicao = 0;
        for (int i = 0; i < 4; i++) {
            if (novaColuna[i] != 0) {
                tabuleiro[posicao++][coluna] = novaColuna[i];
            }
        }
        while (posicao < 4) {
            tabuleiro[posicao++][coluna] = 0;
        }
        return pontos;
    }

    private static int moverColunaBaixo(int[][] tabuleiro, int coluna) {
        int pontos = 0;
        int[] novaColuna = new int[4];
        int posicao = 3;

        for (int i = 3; i >= 0; i--) {
            if (tabuleiro[i][coluna] != 0) {
                novaColuna[posicao--] = tabuleiro[i][coluna];
            }
        }

        for (int i = 3; i > 0; i--) {
            if (novaColuna[i] != 0 && novaColuna[i] == novaColuna[i - 1]) {
                novaColuna[i] *= 2;
                pontos += novaColuna[i];
                novaColuna[i - 1] = 0;
            }
        }

        posicao = 3;
        for (int i = 3; i >= 0; i--) {
            if (novaColuna[i] != 0) {
                tabuleiro[posicao--][coluna] = novaColuna[i];
            }
        }
        while (posicao >= 0) {
            tabuleiro[posicao--][coluna] = 0;
        }
        return pontos;
    }

    // Método principal
    public static void main(String[] args) {
        int[][] tabuleiro = new int[4][4];
        Scanner scanner = new Scanner(System.in);
        initializeTabuleiro(tabuleiro);

        while (true) {
            printTabuleiro(tabuleiro);
            System.out.print("Movimento (j-esquerda, k-direita, i-cima, m-baixo): ");
            String movimento = scanner.next().toLowerCase();

            int pontos = mover(tabuleiro, movimento);
            if (pontos == 0) {
                System.out.println("Movimento inválido!");
            }
        }
    }
}