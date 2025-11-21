// Write a function that returns the sum of elements in a 2D array.
# include <iostream>
using namespace std;

int Sum(int arr[10][10],int m, int n){
    int sum=0;
    for (int i = 0;i<m;i++){
        for (int j=0;j<n;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

int main() {
    int arr[10][10]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    cout<<Sum(arr,3,4)<<endl;
    return 0;
}