#pragma once
#include <raylib.h>
#include <vector>

extern const Color BACKGROUND_COLOR;
extern const Color BORDER_COLOR;
extern const Color TILE_COLORS[];

std::vector<Color> getTileColors();
