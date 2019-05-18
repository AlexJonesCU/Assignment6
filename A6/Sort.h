//header - user defined class
#include <iostream>

using namespace std;


class Sort
{
  public:
    Sort(); //constructor
    Sort(int nameDefault); //overloaded constructor
    ~Sort(); //destructor

    //functions
    void ReadLines();
    void makeArrCopy(int m);

    void bubbleSort();
    void insertionSort();
    void swap(int* xp, int *yp);
    void selectionSort();
    bool isSorted();
    void shuffle();
    void shuffleSwap(int m, int r);
    void bogoSort();



    //local variables
    int fileArray[20];
    int fileArray2[20];
    int fileArray3[20];
    int fileArray4[20];
    string theName;
    string nameDefault;
    int counter;
    int data;
    int numberOfItemsToSort;

};
