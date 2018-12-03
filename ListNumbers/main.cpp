// Program to find largest k numbers in a file
#include <iostream>
#include<fstream>
#include <ctime>
#include "Heap.h"
#include "string"

using namespace std;

// Prototypes of functions
void k_largestElements(int, ifstream &);
void quickSort(int[], int, int);


// Function main
int main()
{
    // Declaring variables
    string fileName;
    int k;
    ifstream file;

    do {
        // Please, enter the name correctly with its extension
        cout << "What is the file name?" << endl;
        cout << "There is a numbers.txt file but you can create yours and test it" << endl;
        cout << "File name: ";
        cin >> fileName;

        // open the file
        file.open(fileName);

        // Check the file name correctness and do the operations
        if (file.is_open())
        {
            cout << "\nHow many largest elements ";
            cout << "do you want to print: \nK = ";
            cin >> k;

            // start clock
            int start_s = clock();
            k_largestElements(k, file);
            // finish clock
            int stop_s = clock();

            cout << "\nCPU time: " << (stop_s-start_s) * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;
        }

        else    // give an error message
        {
            cout << "\nError! File couldn't be opened...\n" << endl;
        }

    } while (!file.is_open());  // repeat loop until the file is found

    file.close();

    return 0;
}

//******************************************************************
// Definition of function "k_largestElements". Accepts k value and *
// text file as its arguments and displays largest k elements of   *
// file stream.                                                    *
//******************************************************************

void k_largestElements(int k, ifstream &file)
{
    int count = 0;              // total number of elements seen so far
    int fileNum;                // fileNum is for every value of file
    bool found = false;         // flag for finding duplicates

    // Create array and min heap of size k
    int *arr = new int[k];
    Heap heap(arr, k);

    // Check file and pass numbers to fileNum
    while (file >> fileNum)
    {
        found = false;

        // Just put to array first k-1 elements
        if (count < k-1)
        {
            found = heap.findDuplicate(count + 1, fileNum);

            if (!found) arr[count++] = fileNum;
        }

        // If it is k'th element, then put it to array
        // and build the heap
        else if (count == k-1)
        {
            found = heap.findDuplicate(count + 1, fileNum);

            if (!found)
            {
                arr[count++] = fileNum;
                heap.buildHeap();
            }
        }

        // If next element is greater than root node replace it
        else
        {
            found = heap.findDuplicate(count + 1, fileNum);

            if (!found && fileNum > heap.getMin())
            {
                heap.replaceMin(fileNum);
            }
        }
    }

    // Sort the array
    quickSort(arr, 0, k-1);

    // Print the array
    heap.print();
}

//****************************************************************
// Definition of function "quickSort". Accepts array, first and  *
// last indexes of an array as its argument and sorts the        *
// elements of an array.                                         *
//****************************************************************

void quickSort(int arr[], int left, int right)
{
    int l = left;       // left side of the pivot
    int r = right;      // right side of the pivot
    int temp;
    int pivot = arr[(left + right) / 2];    // pivot is middle element

    // Partition part
    while (l <= r)
    {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;

        if (l <= r)
        {
            // Swap a[l] and a[r]
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            // Go to next positions
            l++;
            r--;
        }
    };

    // Recursion part
    if (left < r)
        quickSort(arr, left, r);
    if (l < right)
        quickSort(arr, l, right);
}
