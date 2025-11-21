// Write a function to convert dfecimal to binary.

# include <iostream>
# include <algorithm>
using namespace std;

string DectoBit(int n){
    string bin = "";
    while(n>0){
        int bit = n%2;
        bin.push_back('0' + bit);
        n /= 2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

int main() {
    int n = 12;
    cout<<DectoBit(n)<<endl;
    return 0;
}