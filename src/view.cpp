#include "raylib.h"
#include <vector>
#include <algorithm>

#define WIDTH 1280
#define HEIGHT 720

#define WIDTH_MARGIN 100
#define HEIGHT_MARGIN 50
#define MULTIPLIER_HEIGHT 10

using namespace std;

void drawRectangles(vector<int> arrary){
  int totalWidth = WIDTH - WIDTH_MARGIN*2;
  int totalHeight = HEIGHT - HEIGHT_MARGIN*2;
  int numElements = arrary.size();
  int recWidth = totalWidth/numElements;
  // int recHeight = max_element(arrary) ;

  for (int i=0; i<numElements; i++){
    DrawRectangle(WIDTH_MARGIN + (recWidth * i), HEIGHT - HEIGHT_MARGIN - arrary[i]*MULTIPLIER_HEIGHT, recWidth, arrary[i]*MULTIPLIER_HEIGHT, RED);
    DrawRectangleLines(WIDTH_MARGIN + (recWidth * i), HEIGHT - HEIGHT_MARGIN - arrary[i]*MULTIPLIER_HEIGHT, recWidth, arrary[i]*MULTIPLIER_HEIGHT, BLACK);
  }

}


int main(){

  InitWindow(WIDTH, HEIGHT, "Mi primera ventana con Raylib");
  SetTargetFPS(60);

  vector<int> arrary;

  for (int i=1; i<11; i++){
    arrary.push_back(i);
  }

  // for (int i = 0; i < arrary.size(); i++) {
  //   printf("%d\n", arrary[i]);
  // }

  while (!WindowShouldClose()){
    BeginDrawing();
    DrawFPS(WIDTH/15, HEIGHT/15);
    drawRectangles(arrary);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
