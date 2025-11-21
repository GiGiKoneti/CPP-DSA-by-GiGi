// Rotate a string by n positions.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "abcdef";
    int n = 2;

    n= n%s.size();
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}