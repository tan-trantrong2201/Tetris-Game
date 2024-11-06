#pragma once
#include <vector>
#include "Position.h"
#include "Colors.h"

class Tetromino {
public:
    Tetromino();
    static Tetromino getRandomTetromino();
    void render(int offsetX, int offsetY);
    void move(int dx, int dy);
    void rotate();
    void rotateBack();
    std::vector<Position> getPositions();
    int id;

private:
    int rotationIndex;
    int xOffset;
    int yOffset;
    int tileSize;
    std::vector<std::vector<Position>> rotations;
};
