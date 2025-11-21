// Prime Check (Efficient) — Check if a number is prime using minimal loops.

# include <iostream>
using namespace std;

int main (){
    int num,factors=0;
    cout<<"Enter the number : ";
    cin>>num;
    for(int i =2 ; i<num;i++){
        if(num%i==0){
            factors += 1;
        }

    }
    (factors==0)? (num == 1 ) ? cout<<"1 is not prime nor composite."<<endl : cout<<"Prime"<<endl : cout<<"Not Prime"<<endl;
    return 0;
}