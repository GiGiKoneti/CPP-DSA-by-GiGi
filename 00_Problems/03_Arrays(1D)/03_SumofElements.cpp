// Calculate the sum of elements.

# include <iostream>
using namespace std;

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum=0;
    for (int i = 1; i < n; i++) {
        sum+=arr[i];
    }
    cout<<"Sumof of the elements in Array : "<<sum<<endl;
    return 0;
}