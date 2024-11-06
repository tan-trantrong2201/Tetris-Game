#include "Grid.h"
#include "Colors.h"
#include <iostream>

Grid::Grid() {
    reset();
    tileColors = getTileColors();
}

void Grid::reset() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cells[i][j] = 0;
}

void Grid::render() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = cells[i][j];
            DrawRectangle(j * tileSize + 10, i * tileSize + 10, tileSize - 1, tileSize - 1, tileColors[value]);
        }
    }
}

bool Grid::isOutside(int x, int y) {
    return x < 0 || x >= rows || y < 0 || y >= cols;
}

bool Grid::isEmpty(int x, int y) {
    return cells[x][y] == 0;
}

int Grid::clearFullRows() {
    int linesCleared = 0;
    for (int i = rows - 1; i >= 0; --i) {
        if (isRowFull(i)) {
            clearRow(i);
            ++linesCleared;
        }
        else if (linesCleared > 0) {
            moveRowsDown(i, linesCleared);
        }
    }
    return linesCleared;
}

bool Grid::isRowFull(int row) {
    for (int j = 0; j < cols; ++j)
        if (cells[row][j] == 0)
            return false;
    return true;
}

void Grid::clearRow(int row) {
    for (int j = 0; j < cols; ++j)
        cells[row][j] = 0;
}

void Grid::moveRowsDown(int startRow, int numRows) {
    for (int j = 0; j < cols; ++j) {
        cells[startRow + numRows][j] = cells[startRow][j];
        cells[startRow][j] = 0;
    }
}
