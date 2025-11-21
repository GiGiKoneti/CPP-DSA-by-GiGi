// Function reverse an integer.

# include <iostream>
using namespace std;

int Reverse(int n){
    int remainder=0, rev=0,temp=n;
    while(n){
        remainder = n%10;
        rev = rev*10 + remainder;
        n = n/10;

    }
    
    return rev;
}

int main(){
    int n = 12348;
    cout<<Reverse(n)<<endl;
    return 0;
}

/*
#include <iostream>        for n = 123450
#include <string>
#include <algorithm>
using namespace std;

string ReverseNumberAsString(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n = 12340;
    cout << ReverseNumberAsString(n) << endl;
    return 0;
}
*/