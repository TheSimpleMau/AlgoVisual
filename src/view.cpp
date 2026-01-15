#include "raylib.h"
#include "algos.h"
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

void drawSteps(vector<vector<int>> steps, int &currentIndex){
  drawRectangles(steps[currentIndex]);
  if (currentIndex < steps.size()-1){
    currentIndex += 1;
  } else {
    currentIndex = 0;
  }
  WaitTime(0.25);
}

int main(){

  InitWindow(WIDTH, HEIGHT, "Algorithms visualizer");
  SetTargetFPS(60);

  vector<int> array;
  vector<vector<int>> steps;
  int currentIndex = 0;

  randomArray(array);
 
  // bubbleSort(array, steps);
  // insertionSort(array, steps);
  // selectionSort(array, steps);
  mergeSort(array, steps);

  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawSteps(steps, currentIndex);
    DrawFPS(WIDTH/15, HEIGHT/15);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
