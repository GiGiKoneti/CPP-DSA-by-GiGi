// Count, even an odd numbers in an array.
# include<iostream>
using namespace std;

int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,10}, n = sizeof(arr)/sizeof(arr[0]),EvenCount=0,OddCount=0;
    

    for(int i =0 ;i<n;i++)
        (arr[i]%2 ==0)? EvenCount++ : OddCount++;

    cout<<"Number of Even elements in array : "<<EvenCount<<endl;
    cout<<"Number of odd elements in array : "<<OddCount<<endl;
    return 0;

}