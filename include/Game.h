#pragma once
#include "Grid.h"
#include "Tetromino.h"
#include <raylib.h>

class Game {
public:
    Game();
    ~Game();
    void update();
    void draw();
    bool isGameOver;
    int score;

private:
    void handleInput();
    void moveTetrominoDown();
    void moveTetrominoLeft();
    void moveTetrominoRight();
    void rotateTetromino();
    void lockTetromino();
    bool tetrominoFits();
    void resetGame();
    void updateScore(int lines, int points);

    Grid grid;
    Tetromino currentTetromino;
    Tetromino nextTetromino;
    Music backgroundMusic;
    Sound rotateSound;
    Sound clearSound;
    double lastUpdateTime;
    bool eventTriggered(double interval);
};
