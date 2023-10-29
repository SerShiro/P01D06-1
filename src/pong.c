#include <stdio.h>
#include <stdlib.h>

void startGame();
void drawBorderLine(int WIDTH);
void draw(int HEIGHT, int WIDTH, int ballY, int ballX, int racketLeft, int racketRight, int RACKET_SIZE);
void endGame(int scoreLeft, int scoreRight);

int main() {
    startGame();
    return 0;
}

void startGame() {
    int WIDTH = 80, HEIGHT = 25, RACKET_SIZE = 3;
    int ballX = WIDTH / 2, ballY = HEIGHT / 2;
    int ballSpeedX = 1, ballSpeedY = 1;
    int racketLeft = (HEIGHT - RACKET_SIZE) / 2, racketRight = (HEIGHT - RACKET_SIZE) / 2;
    int scoreLeft = 0, scoreRight = 0;

    while (1) {
        system("clear");
        draw(HEIGHT, WIDTH, ballY, ballX, racketLeft, racketRight, RACKET_SIZE);
        drawBorderLine(WIDTH);

        printf("\t\t\t  Player 1: %d  Player  2: %d\n", scoreLeft, scoreRight);

        char key = getchar();
        if (key == 'a' && racketLeft > 0) racketLeft--;
        if (key == 'z' && racketLeft < HEIGHT - RACKET_SIZE) racketLeft++;
        if (key == 'k' && racketRight > 0) racketRight--;
        if (key == 'm' && racketRight < HEIGHT - RACKET_SIZE) racketRight++;
        if (key == 'e') {
            exit(0);
        }

        ballX += ballSpeedX;
        ballY += ballSpeedY;

        if (ballY <= 0 || ballY >= HEIGHT - 1) ballSpeedY = -ballSpeedY;

        if (ballX == 2 && ballY >= racketLeft && ballY < racketLeft + RACKET_SIZE) ballSpeedX = -ballSpeedX;
        if (ballX == WIDTH - 3 && ballY >= racketRight && ballY < racketRight + RACKET_SIZE)
            ballSpeedX = -ballSpeedX;

        if (ballX <= 0 || ballX >= WIDTH - 1) {
            if (ballX <= 0) {
                scoreRight++;
            } else {
                scoreLeft++;
            }
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            ballSpeedX = -ballSpeedX;
        }

        endGame(scoreLeft, scoreRight);
    }
}

void drawBorderLine(int WIDTH) {
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}

void draw(int HEIGHT, int WIDTH, int ballY, int ballX, int racketLeft, int racketRight, int RACKET_SIZE) {
    drawBorderLine(WIDTH);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            if (i == ballY && j == ballX) {
                printf("O");
            } else if (i >= racketLeft && i < racketLeft + RACKET_SIZE && j == 1) {
                printf("|");
            } else if (i >= racketRight && i < racketRight + RACKET_SIZE && j == WIDTH - 2) {
                printf("|");
            } else {
                printf(" ");
            }
            if (j == WIDTH - 1) {
                printf("#");
            }
        }
        printf("\n");
    }
}

void endGame(int scoreLeft, int scoreRight) {
    if (scoreLeft >= 21 || scoreRight >= 21) {
        system("clear");
        if (scoreLeft >= 21) {
            printf("Победил игрок 1! Поздравляем!\n");
        } else {
            printf("Победил игрок 2! Поздравляем!\n");
        }
        exit(0);
    }
}
