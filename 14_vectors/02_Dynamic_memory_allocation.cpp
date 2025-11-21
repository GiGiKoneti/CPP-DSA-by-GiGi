#include <iostream>
using namespace std;

// Function demonstrating DMA for a single integer
void funcINT() {
    int *ptr = new int;  // Allocate memory on the heap for a single integer
    *ptr = 5;            // Assign value
    cout << "Value from funcINT(): " << *ptr << endl;
    delete ptr;          // Free the allocated memory
}

int main() {
    // Call function to demonstrate DMA for a single integer
    funcINT();

    // DMA for an array
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];  // Allocate memory on heap for an array of given size

    // Fill array with consecutive numbers starting from 1
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free allocated memory for the array
    delete[] arr;

    return 0;
}



// ==================== Static Memory Allocation ====================
// 1. Memory is allocated at compile time.
// 2. Size must be known and fixed before execution.
// 3. Stored in Stack or Data Segment (depending on scope).
// 4. Memory is automatically managed by the compiler.
// 5. Faster access but limited flexibility.
// 6. Example:
// int arr[5];  // Statically allocated array of size 5

// ==================== Dynamic Memory Allocation ====================
// 1. Memory is allocated at runtime (during program execution).
// 2. Useful when the size of data is not known in advance.
// 3. Stored in Heap memory.
// 4. Memory must be manually deallocated using `delete` or `delete[]`.
// 5. Provides flexibility to allocate memory based on user input or conditions.
// 6. Slightly slower due to runtime allocation and pointer access.
// 7. Example:
// int* arr = new int[5];  // Dynamically allocated array of size 5
// delete[] arr;           // Must free memory to avoid memory leaks



// ==================== What is a Memory Leak in C++? ====================
//
// A memory leak occurs when dynamically allocated memory (on the heap)
// is not properly deallocated using `delete` or `delete[]`.
//
// This means the program loses the reference (pointer) to the memory,
// so it can't be reused or freed — but it still consumes system resources.
//
// Over time (especially in long-running programs), memory leaks
// can slow down or crash the application due to excessive memory usage.
//
// ==================== Common Causes ====================
// 1. Forgetting to free memory using `delete` or `delete[]`.
// 2. Reassigning a pointer without deleting the old memory it pointed to.
// 3. Improper use of pointer logic or control flow (like early return).
//
// ==================== Example of Memory Leak ====================
//      int* ptr = new int(10);   // Allocates memory
//      ptr = new int(20);        // Memory to 10 is leaked (no delete done)
//      delete ptr;               // Only 20 is deleted

// ==================== How to Avoid It ====================
// - Always pair `new` with `delete`, and `new[]` with `delete[]`.
// - Use smart pointers (like std::unique_ptr or std::shared_ptr).
// - Keep track of ownership and delete memory in all code paths.