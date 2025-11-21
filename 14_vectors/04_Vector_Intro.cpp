/*
    ============================
    📚 C++ STL (Standard Template Library)
    ============================

    STL is a powerful set of C++ template classes that provides common 
    data structures and algorithms. It enables **code reusability, efficiency,**
    and reduces development time.

    ---------------------------------
    🔧 STL is divided into 4 components:
    ---------------------------------

    1. Containers:
       -> Used to store collections of data.
       -> Types:
          - Sequential Containers: vector, list, deque, array, forward_list
          - Associative Containers: set, multiset, map, multimap
          - Unordered Containers: unordered_set, unordered_map, etc.

    2. Algorithms:
       -> Predefined functions to perform operations like sorting, searching, reversing, etc.
       -> Examples: sort(), binary_search(), count(), find(), reverse(), accumulate()

    3. Iterators:
       -> Objects that point to elements of containers.
       -> Used to traverse through containers (like pointers).
       -> Types: input, output, forward, bidirectional, random access iterators.

    4. Functors (Function Objects):
       -> Objects that behave like functions.
       -> Allow customization of operations (e.g., using custom comparator in sorting).

    -------------------------------------
    ⚡ Example: Using vector and sort()
    -------------------------------------

    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
        std::vector<int> v = {4, 1, 3, 2};

        // Sorting using STL algorithm
        std::sort(v.begin(), v.end());

        // Printing sorted vector
        for (int i : v) {
            std::cout << i << " ";
        }
        return 0;
    }

    ---------------------------------------
    ✅ Advantages of using STL:
    ---------------------------------------
    - Saves time with ready-made data structures and algorithms.
    - Type-safe and template-based (generic programming).
    - Highly optimized and well-tested.

    🔒 NOTE:
    - STL is template-based, so you can use any datatype (int, float, user-defined class).
    - Always release dynamically allocated memory if using raw pointers (or prefer smart pointers).
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ✅ Declaring an empty vector of integers
    vector<int> vec1;
    cout << "Size of vec1: " << vec1.size() << endl;

    // ✅ Initializing vector using initializer list
    vector<int> vec2 = {1, 2, 3};
    cout << "Size of vec2: " << vec2.size() << endl;

    // ✅ Creating a vector of size 10, all elements initialized to -1
    vector<int> vec3(10, -1);
    cout << "Size of vec3: " << vec3.size() << endl;

    // ✅ Printing elements of vec3 using index-based loop
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << " ";
    }
    cout << endl;

    // ❌ Wrong: Pointer arithmetic like *(vec3 + 4) is invalid with STL vectors.
    // ✅ Correct way to access 5th element (index 4)
    cout << "Element at index 4 in vec3: " << vec3[4] << endl;

    return 0;
}