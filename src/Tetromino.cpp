#include "Tetromino.h"
#include <cstdlib>

Tetromino::Tetromino() : rotationIndex(0), xOffset(0), yOffset(0), tileSize(30) {}

Tetromino Tetromino::getRandomTetromino() {
    int type = rand() % 7;
    Tetromino tetromino;
    tetromino.id = type + 1;

    switch (type) {
    case 0: // I-Block
        tetromino.rotations = {
            { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) },
            { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) }
        };
        break;
    case 1: // J-Block
        tetromino.rotations = {
            { Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1) },
            { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) },
            { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) },
            { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) }
        };
        break;
    case 2: // L-Block
        tetromino.rotations = {
            { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 0) },
            { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) },
            { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) },
            { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) }
        };
        break;
    case 3: // O-Block
        tetromino.rotations = {
            { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) }
        };
        break;
    case 4: // S-Block
        tetromino.rotations = {
            { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) },
            { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) }
        };
        break;
    case 5: // T-Block
        tetromino.rotations = {
            { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) },
            { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) },
            { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) },
            { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) }
        };
        break;
    case 6: // Z-Block
        tetromino.rotations = {
            { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) },
            { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) }
        };
        break;
    }

    tetromino.xOffset = 0;
    tetromino.yOffset = 3;
    return tetromino;
}

void Tetromino::render(int offsetX, int offsetY) {
    auto positions = getPositions();
    for (auto& pos : positions) {
        DrawRectangle(pos.y * tileSize + offsetX, pos.x * tileSize + offsetY, tileSize - 1, tileSize - 1, TILE_COLORS[id]);
    }
}

void Tetromino::move(int dx, int dy) {
    xOffset += dx;
    yOffset += dy;
}

void Tetromino::rotate() {
    rotationIndex = (rotationIndex + 1) % rotations.size();
}

void Tetromino::rotateBack() {
    rotationIndex = (rotationIndex - 1 + rotations.size()) % rotations.size();
}

std::vector<Position> Tetromino::getPositions() {
    const auto& shape = rotations[rotationIndex];
    std::vector<Position> positions;
    for (const auto& pos : shape) {
        positions.push_back(Position(pos.x + xOffset, pos.y + yOffset));
    }
    return positions;
}
