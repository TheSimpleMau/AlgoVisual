#include "raylib.h"

int main(){

  InitWindow(800, 400, "Mi primera ventana con Raylib");
  SetTargetFPS(60);

  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Mi primera ventana!", 190, 200, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
