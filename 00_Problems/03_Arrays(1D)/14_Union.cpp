// Find the union of two arrays

# include <iostream>
# include <set>
# include<algorithm>
using namespace std;

int main() {
    int arr1[10]={1,2,3,4,5,6,7,8,9}, arr2[10]={6,7,8,9,10,11,12,13,14};
    int n1 = 9, n2 = 9;
    int arr3[20];
    

    for(int i = 0;i<n1;i++){
        arr3[i]=arr1[i];
    }
    for(int i =0;i<n2;i++){
        arr3[n1+i]=arr2[i];
    }
    set<int> SET(arr3,arr3+n1+n2);
    for(int i : SET){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}