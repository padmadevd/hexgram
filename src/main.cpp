#include <raylib/raylib.h>

int main()
{
    InitWindow(720, 720, "hexgram");
    InitAudioDevice();

    while(!WindowShouldClose())
    {
        PollInputEvents();

        ClearBackground(RED);

        SwapScreenBuffer();
    }

    CloseAudioDevice();
    CloseWindow();
}