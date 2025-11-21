// 1.	Odd or Even Counter — Given n numbers, count how many are even and how many are odd.

# include <iostream>
using namespace std ;

int main() {
    int num[5];
    int count = 0;
    cout<<"Enter any 5  Numbers : ";
    for (int i = 0;i<5-1;i++){
        cin>> num[i];
        if(num[i]%2==0){
            count+=1;
        }
    }
    cout<<"Number of Even Numbers : "<<count<<endl;
    cout<<"Number of Odd Numbers : "<<5-count<<endl;
    return 0;
}