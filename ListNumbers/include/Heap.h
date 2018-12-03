// This is class Heap, main part will be done using this class
#ifndef HEAP_H
#define HEAP_H

// Minimum Heap
class Heap
{
    public:
        Heap(int[], int);                   // Constructor
        ~Heap();                            // Destructor
        void buildHeap();                   // Build the heap
        void heapify(int);                  // Heapify subtree rooted with index i
        void replaceMin(int);               // Replace root with new element num and heapify new root
        bool findDuplicate(int, int);       // Find the duplicates
        void swapValues(int*, int*);        // Swap the values
        int getMin();                       // Return the root node
        void print();                       // Print the array

    private:
        int *heapArr;       // Pointer to array of elements in heap
        int heapSize;       // Number of elements in heap
};

#endif // HEAP_H
