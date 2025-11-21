// Implement a recursive function for Binary Search.

# include <iostream>
using namespace std;

void RecursiveBS(int arr[],int low ,int high,int target){
    
    int mid = (low+high)/2;
    if(target==arr[mid]){
        cout<<"Target is at "<<mid<<endl;
    }
    else if (arr[mid]<target){
        RecursiveBS(arr,low = mid+1,high,target);
    }
    else{
        RecursiveBS(arr,low,high=mid-1,target);
    }
    
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int target = 10;
    RecursiveBS(arr,0,9,10);
    return 0;

}