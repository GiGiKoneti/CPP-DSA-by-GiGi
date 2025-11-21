#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a vector with 4 elements
    vector<int> vec = {1, 2, 3, 4};

    // Print current size and capacity
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // Add one element at the end using push_back()
    vec.push_back(5);

    // Print updated size and capacity
    cout << "After push_back(5):" << endl;
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // Remove the last element using pop_back()
    vec.pop_back();

    // Print final size and capacity
    cout << "After pop_back():" << endl;
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    return 0;
}