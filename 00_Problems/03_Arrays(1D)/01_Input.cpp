// Input and Display elemts of an array .
# include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout<<"Enter 5 numbers for the Array : ";
    for (int i = 0;i<5;i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
