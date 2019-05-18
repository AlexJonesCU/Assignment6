//implementation

#include "Sort.h"

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>

#include <ctime>

#include <fstream> //source: http://www.cplusplus.com/doc/tutorial/files/

using namespace std;

Sort::Sort() //default constructor
{}

Sort::Sort(int nameDefault)
{
    //theName = nameDefault;
}

Sort::~Sort()//destructor
{
  //delete []fileArray; // source: https://www.geeksforgeeks.org/destructors-c/
}

void Sort::ReadLines()
{
  cout << "What is the name of the txt file you wish to check?" << endl;
  cin >> theName;
  counter = 0;
  int i = 0;
  int j = 0;

  int line;

  ifstream SortFile (theName);
  if(SortFile.is_open())
  {
    while ( SortFile >> line) //source: Sorting ints - http://www.cplusplus.com/forum/general/198475/
    {
      fileArray[i] = line;
      counter++; //to keep track of the amount of elements in the array
      i++;
    }
  }
  for (int m = 0; m < 20; m++)
  {
    makeArrCopy(m);
    cout << "original: " << fileArray[m] << endl;
  }

  bubbleSort();
  insertionSort();
  selectionSort();
  bogoSort();
  cout << "Start Time: ";
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result))
            << result << " seconds";
}


void Sort::makeArrCopy(int m)
{
  fileArray2[m] = fileArray[m];
  fileArray3[m] = fileArray[m];
  fileArray4[m] = fileArray[m];
}

void Sort::bubbleSort()
{
  numberOfItemsToSort = fileArray[0]; //first number is the number of items you are sorting
  for (int m = 1; m <= numberOfItemsToSort; m++)
  {

    for(int n = 2; n <= numberOfItemsToSort; n++)
    {
      int temp = 0;
      if(fileArray[n-1] > fileArray[n]) //if element to the left is less than element to the right, switch them
      {
        temp = fileArray[n];
        fileArray[n] = fileArray[n-1];
        fileArray[n-1] = temp;
      }
    }
  }
  for (int m = 1; m <= numberOfItemsToSort; m++)
  {
    cout << "Bubble Sorted: " << fileArray[m] << endl;
  }
}

void Sort::insertionSort()
{
  numberOfItemsToSort = fileArray2[0]; //first number is the number of items you are sorting
  for(int m = 2; m <= numberOfItemsToSort; m++)
  {
    int key = fileArray2[m]; //sets the 2nd intem in the array(not counting first entry which is number of ints to the keys to check)
    int n = m - 1; //n is the left of m;
    while(m >= 0 && fileArray2[n] > key) //while m is a valid index of the array and they element in index n is greater than the key, switch it
    {
      fileArray2[n+1] = fileArray2[n];
      n = n-1;
    }
    fileArray2[n+1] = key; //move key one to the right
  }
  for (int m = 1; m <= numberOfItemsToSort; m++)
  {
    cout << "Insetion Sorted: " << fileArray[m] << endl;
  }
}

void Sort::swap(int* xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void Sort::selectionSort() //based of this source: https://www.geeksforgeeks.org/selection-sort/
{
  numberOfItemsToSort = fileArray3[0]; //first number is the number of items you are sorting
  int minIndex;
  for(int m = 0; m <= numberOfItemsToSort; m++)
  {
    minIndex = m;
    for(int n = m + 1; n <= numberOfItemsToSort; n++) //to the right of
    {
      if(fileArray3[n] < fileArray3[minIndex])
        minIndex = n; // if index n is less than the current min index, n index becomes new min
      swap(&fileArray3[minIndex], &fileArray3[m]);
    }
  }
  for (int m = 1; m <= numberOfItemsToSort; m++)
  {
    cout << "Selection Sorted: " << fileArray[m] << endl;
  }
}

bool Sort::isSorted()
{
  bool val = true;
  for(int m = 1; m <= numberOfItemsToSort; m++)
  {
    if(fileArray4[m] > fileArray4[m+1]) //if an element to right is less than an element to the left, it is not sorted
    {
      val = false; //array is not sorted
    }
  }
  return val;
}

void Sort::shuffleSwap(int m, int r)
{
  int temp = fileArray4[r];
  fileArray4[r] = fileArray4[m];
  fileArray4[m] = temp;
  //cout << "Here" << endl;
  bogoSort(); //recursion
}

void Sort::shuffle()
{
  int h = 0;
  while(isSorted() == false)
  {
    h++;
    shuffleSwap(fileArray4[h], rand()% numberOfItemsToSort + 1);  //gives element a new random index: https://www.geeksforgeeks.org/bogosort-permutation-sort/?fbclid=IwAR0m5HT42FGPrR-cZYWSeMQN6kdjgz6WJRcCVrTiGz6IdPg_ZWuNYr12kbE
  }
}


void Sort::bogoSort()
{
  numberOfItemsToSort = fileArray4[0]; //first number is the number of items you are sorting
  if(isSorted() == true)  // sorted doesnt randomly shuffle anymore
  {
    for (int i = 1; i <= numberOfItemsToSort; i++)
    {
      cout << "Bogo Sorted: " << fileArray4[i] << endl;
    }
  }
  else if(isSorted() == false)
  {
    shuffle();
  }
}
