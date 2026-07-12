#include <raylib/raylib.h>

#include "assets.hpp"

int main()
{
    InitWindow(720, 720, "hexgram");
    InitAudioDevice();

    Assets::Load();

    Camera2D cam;
    cam.offset = {0, 0};
    cam.target = {0, 0};
    cam.rotation = 0;
    cam.zoom = 1;

    while(!WindowShouldClose())
    {
        PollInputEvents();

        ClearBackground(RED);

        BeginMode2D(cam);
        DrawTexture(Assets::tileBlankPng, 0, 0, WHITE);
        EndMode2D();

        SwapScreenBuffer();
    }

    CloseAudioDevice();
    CloseWindow();
}