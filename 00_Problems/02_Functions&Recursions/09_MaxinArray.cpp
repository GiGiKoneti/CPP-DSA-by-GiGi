// Write a function to find the maximum element in an array.
# include <iostream>
using namespace std;

int Findmax(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }

    }
    return max;

}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = Findmax(arr,n);
    cout<<max<<endl;
    return 0;

}