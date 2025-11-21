// Rotate an array by K positions.
# include <iostream>
# include<algorithm>
using namespace std;

int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int k = 2;
    int size = sizeof(arr)/sizeof(arr[0]);
    k = k % size;
    reverse(arr,arr+k);
    reverse(arr+k,arr+size);
    reverse(arr,arr+size);

    for(int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}