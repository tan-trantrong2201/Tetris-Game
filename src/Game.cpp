#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game() : isGameOver(false), score(0), lastUpdateTime(0.0) {
    srand(static_cast<unsigned>(time(0)));
    grid = Grid();
    currentTetromino = Tetromino::getRandomTetromino();
    nextTetromino = Tetromino::getRandomTetromino();
    InitAudioDevice();
    backgroundMusic = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(backgroundMusic);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

Game::~Game() {
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();
}

void Game::update() {
    UpdateMusicStream(backgroundMusic);
    handleInput();
    if (eventTriggered(0.5)) {
        moveTetrominoDown();
    }
}

void Game::draw() {
    grid.render();
    currentTetromino.render(10, 10);
    nextTetromino.render(320, 250);
}

void Game::handleInput() {
    if (isGameOver && GetKeyPressed() != 0) {
        resetGame();
        isGameOver = false;
    }

    if (IsKeyPressed(KEY_LEFT)) moveTetrominoLeft();
    if (IsKeyPressed(KEY_RIGHT)) moveTetrominoRight();
    if (IsKeyPressed(KEY_DOWN)) {
        moveTetrominoDown();
        updateScore(0, 1);
    }
    if (IsKeyPressed(KEY_UP)) rotateTetromino();
}

void Game::moveTetrominoLeft() {
    currentTetromino.move(0, -1);
    if (!tetrominoFits()) currentTetromino.move(0, 1);
}

void Game::moveTetrominoRight() {
    currentTetromino.move(0, 1);
    if (!tetrominoFits()) currentTetromino.move(0, -1);
}

void Game::moveTetrominoDown() {
    currentTetromino.move(1, 0);
    if (!tetrominoFits()) {
        currentTetromino.move(-1, 0);
        lockTetromino();
    }
}

void Game::rotateTetromino() {
    currentTetromino.rotate();
    if (!tetrominoFits()) currentTetromino.rotateBack();
    else PlaySound(rotateSound);
}

void Game::lockTetromino() {
    for (auto& pos : currentTetromino.getPositions()) {
        grid.cells[pos.x][pos.y] = currentTetromino.id;
    }
    currentTetromino = nextTetromino;
    nextTetromino = Tetromino::getRandomTetromino();
    if (!tetrominoFits()) isGameOver = true;
    int linesCleared = grid.clearFullRows();
    if (linesCleared > 0) {
        PlaySound(clearSound);
        updateScore(linesCleared, 0);
    }
}

bool Game::tetrominoFits() {
    for (auto& pos : currentTetromino.getPositions()) {
        if (grid.isOutside(pos.x, pos.y) || !grid.isEmpty(pos.x, pos.y))
            return false;
    }
    return true;
}

void Game::resetGame() {
    grid.reset();
    currentTetromino = Tetromino::getRandomTetromino();
    nextTetromino = Tetromino::getRandomTetromino();
    score = 0;
}

void Game::updateScore(int lines, int points) {
    static const int lineScores[] = { 0, 100, 300, 500, 800 };
    if (lines >= 1 && lines <= 4)
        score += lineScores[lines];
    score += points;
}

bool Game::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
