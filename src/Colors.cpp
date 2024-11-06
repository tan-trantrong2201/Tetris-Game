#include "Colors.h"

const Color BACKGROUND_COLOR = { 44, 44, 127, 255 };
const Color BORDER_COLOR = { 59, 85, 162, 255 };
const Color TILE_COLORS[] = {
    {26, 31, 40, 255},   // Empty
    {47, 230, 23, 255},  // Green
    {232, 18, 18, 255},  // Red
    {226, 116, 17, 255}, // Orange
    {237, 234, 4, 255},  // Yellow
    {166, 0, 247, 255},  // Purple
    {21, 204, 209, 255}, // Cyan
    {13, 64, 216, 255}   // Blue
};

std::vector<Color> getTileColors() {
    return std::vector<Color>(TILE_COLORS, TILE_COLORS + sizeof(TILE_COLORS) / sizeof(TILE_COLORS[0]));
}
