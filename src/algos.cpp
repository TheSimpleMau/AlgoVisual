#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>

#define ARRAY_SIZE 100000

using namespace std;

#define timeToSort(sortFunction, array, array_name) \
  do {\
    auto start = chrono::system_clock::now();\
    sortFunction(array);\
    auto end = chrono::system_clock::now();\
    chrono::duration<float,std::milli> duration = end - start;\
    printf("duration of %s: %f ms\n", array_name, duration.count());\
  } while(0)\

void swap(vector<int> &arrayToSwap, int i, int j){
  int aux = arrayToSwap[i];
  arrayToSwap[i] = arrayToSwap[j];
  arrayToSwap[j] = aux;
}

vector<int> bubbleSort(vector<int> array){
  int aux;
  for (int i = 1; i < array.size() - 1; i++) {
    for (int j = 0; j < array.size() - i; j++) {
      if (array[j] > array[j+1]) {
        swap(array, j, j+1);
      }
    }
  }

  return array;
}

vector<int> insertionSort(vector<int> array){
  int i = 1;
  while (i < array.size()) {
    int j = i;
    while (j > 0 && array[j-1] > array[j]){
      swap(array, j, j-1);
      j -= 1;
    }
    i+=1;
  }
  return array;
}

vector<int> selectionSort(vector<int> array){
  for (int i = 0; i < array.size()-1; i++) {
    int mini = i;
    for (int j = i+1; j < array.size(); j++) {
      if (array[j] < array[mini]) {
        mini = j;
      }
    }
    swap(array, i, mini);
  }
  return array;
}

vector<int> merge(vector<int> arrayLeft, vector<int> arrayRight){
  vector<int> result;
  while (!arrayLeft.empty() && !arrayRight.empty()){
    if (arrayLeft[0] < arrayRight[0]){
      result.push_back(arrayLeft[0]);
      arrayLeft.erase(arrayLeft.begin());
    } else {
      result.push_back(arrayRight[0]);
      arrayRight.erase(arrayRight.begin());
    }
  }

  while (!arrayLeft.empty()){
    result.push_back(arrayLeft[0]);
    arrayLeft.erase(arrayLeft.begin());
  }

  while (!arrayRight.empty()){
    result.push_back(arrayRight[0]);
    arrayRight.erase(arrayRight.begin());
  }
  return result;
}

vector<int> mergeSort(vector<int> array){

  if (array.size() <= 1) {
    return array;
  }

  vector<int> arrayLeft;
  vector<int> arrayRight;

  for (int i = 0; i < array.size(); i++) {
    if (i < array.size()/2) {
      arrayLeft.push_back(array[i]);
    } else {
      arrayRight.push_back(array[i]);
    }
  }

  arrayLeft = mergeSort(arrayLeft);
  arrayRight = mergeSort(arrayRight);

  return merge(arrayLeft, arrayRight);
} 

void printArray(string array_name, vector<int> array){
  cout << array_name << ":\n";
  for (int i=0; i<ARRAY_SIZE; i++){
    printf("%d\n", array[i]);
  }
  printf("\n");
}

int main() {
  srand(time(0));

  vector<int> array;

  for (int i=0; i<ARRAY_SIZE; i++){
    array.push_back(1 + (rand()%ARRAY_SIZE));
  }
  // printArray("unsorted", array);
  //
  // vector<int> sorted_bubble = bubbleSort(array);
  // vector<int> sorted_insertion = insertionSort(array);
  // vector<int> sorted_selection = selectionSort(array);
  // vector<int> sorted_merge = mergeSort(array);
  //
  // printArray("sorted_bubble", sorted_bubble);
  // printArray("sorted_insertion", sorted_insertion);
  // printArray("sorted_selection", sorted_selection);
  // printArray("sorted_merge", sorted_merge);
  //

  printf("Sorting whit: bubbleSort...\n");
  timeToSort(bubbleSort,array, "bubbleSort");
  printf("Sorting whit: mergeSort...\n");
  timeToSort(mergeSort, array, "mergeSort");
  


  

  return 0;
}
