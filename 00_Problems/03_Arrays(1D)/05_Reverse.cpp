// Reverse an array in place.
# include<iostream>
using namespace std;

int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start =0,end=n-1;

    while (start<end){
        int temp = arr[end];
        arr[end]=arr[start];
        arr[start]=temp;
        start++;
        end--;
    }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}