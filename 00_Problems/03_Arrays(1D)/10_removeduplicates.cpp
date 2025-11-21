// Remove duplicates from sorted array.
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1,1,2,2,3,3,4,4,5,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int j = 0;  

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) { 
            j++;               
            arr[j] = arr[i];   
        }
    }

    int newSize = j + 1;

    for (int i = 0; i < newSize; i++)
        cout << arr[i] << " ";

    return 0;
}
