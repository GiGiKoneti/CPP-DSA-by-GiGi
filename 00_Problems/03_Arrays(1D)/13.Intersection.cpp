// Find the intersection of two arrays
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {3, 4, 5, 6, 7};

    vector<int> intersection;

    for (int i : arr1) {
        for (int j : arr2) {
            if (i == j) {
                intersection.push_back(i);
                break;   
            }
        }
    }

    for (int x : intersection)
        cout << x << " ";

    cout << endl;
    return 0;
}