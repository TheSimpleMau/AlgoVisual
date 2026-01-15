#include "algos.h"

int main() {
  srand(time(0));

  vector<int> array;
  vector<vector<int>> steps;

  for (int i=0; i<ARRAY_SIZE; i++){
    array.push_back(1 + (rand()%ARRAY_SIZE));
  }
  // printArray("unsorted", array);
  //
  vector<int> sorted_bubble = bubbleSort(array, steps);
  // vector<int> sorted_insertion = insertionSort(array);
  // vector<int> sorted_selection = selectionSort(array);
  // vector<int> sorted_merge = mergeSort(array);
  //
  printArray("sorted_bubble", sorted_bubble);
  // printArray("sorted_insertion", sorted_insertion);
  // printArray("sorted_selection", sorted_selection);
  // printArray("sorted_merge", sorted_merge);
  //
  //
  // printf("Sorting whit: bubbleSort...\n");
  // timeToSort(bubbleSort,array, "bubbleSort");
  // printf("Sorting whit: mergeSort...\n");
  // timeToSort(mergeSort, array, "mergeSort");
  
  printSteps(steps);
  

  return 0;
}
