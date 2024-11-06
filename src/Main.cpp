#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <cstdio>

int main() {
    InitWindow(500, 620, "Tetris Clone");
    SetTargetFPS(60);

    Font gameFont = LoadFontEx("monogram.ttf", 64, 0, 0);
    Game game;

    while (!WindowShouldClose()) {
        game.update();

        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        DrawTextEx(gameFont, "Score", { 365, 15 }, 38, 2, WHITE);
        DrawTextEx(gameFont, "Next", { 370, 175 }, 38, 2, WHITE);

        if (game.isGameOver) {
            DrawTextEx(gameFont, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
        }

        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3f, 6, BORDER_COLOR);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3f, 6, BORDER_COLOR);

        char scoreStr[10];
        sprintf(scoreStr, "%d", game.score);
        Vector2 textSize = MeasureTextEx(gameFont, scoreStr, 38, 2);
        DrawTextEx(gameFont, scoreStr, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);

        game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
