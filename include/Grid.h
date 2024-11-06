#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    void reset();
    void render();
    bool isOutside(int x, int y);
    bool isEmpty(int x, int y);
    int clearFullRows();
    int cells[20][10];

private:
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowsDown(int startRow, int numRows);
    const int rows = 20;
    const int cols = 10;
    const int tileSize = 30;
    std::vector<Color> tileColors;
};
