#include "Heap.h"
#include <iostream>

using namespace std;

//*****************************************************************
// Definition of constructor. It takes array and size of an array *
// as its arguments and assigns them to its private variables.    *
//*****************************************************************

Heap::Heap(int arr[], int size)
{
    heapSize = size;       // store size of array
    heapArr = arr;          // store address of array
}

//**************************************************************
// Definition of destructor. Destructor deletes an object from *
// memory after completion of program.                         *
//**************************************************************

Heap::~Heap() {}

//*********************************************************************
// Definition of function "buildHeap". It builds the heap to maintain *
// the heap property.                                                 *
//*********************************************************************

void Heap::buildHeap()
{
    int h = (heapSize - 1)/2;      // height of heap tree

    for (int i = h; i >= 0; i--)    // heapify starting from top until bottom
    {
        heapify(i);
    }
}

//********************************************************************
// Definition of function "heapify". It takes the parent node as its *
// argument and rearranges the heap in such a way that the parent    *
// node is less than or equal to its children.                       *
//********************************************************************

void Heap::heapify(int i)
{
    int smallest = i;       // parent
    int l = 2*i + 1;        // left child
    int r = 2*i + 2;        // right child

    if (l < heapSize && heapArr[l] < heapArr[smallest])
        smallest = l;

    if (r < heapSize && heapArr[r] < heapArr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swapValues(&heapArr[i], &heapArr[smallest]);
        heapify(smallest);
    }
}

//******************************************************************
// Definition of function "replaceMin". It takes the number as its *
// argument and replaces the root node with that number            *
//******************************************************************

void Heap::replaceMin(int num)
{
   heapArr[0] = num;
   heapify(0);
}

//**************************************************************************
// Definition of function "findDuplicate". It takes the size of the array  *
// created so far and the value that needs to be compared as its arguments *
// and uses linear search to find duplicates.                              *
//**************************************************************************

bool Heap::findDuplicate(int size, int fileNum)
{
    bool found;

    for (int i = 0; i < size; i++)
    {
        if (heapArr[i] == fileNum)
        {
            found = true;
        }
    }

    return found;
}

//****************************************************************************
// Definition of function "swapValues". It takes two values as its arguments *
// and swaps them.                                                           *
//****************************************************************************

void Heap::swapValues(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//*********************************************************
// Definition of function "getMin". Returns the root node.*
//*********************************************************

int Heap::getMin()
{
    return heapArr[0];
}

//***************************************************************
// Definition of function "print". Prints all elements of heap. *
//***************************************************************

void Heap::print()
{
    cout << endl;
    for (int i = heapSize - 1; i >= 0; i--)
    {
        cout << heapSize - i << ". " << heapArr[i] << endl;
    }
}
