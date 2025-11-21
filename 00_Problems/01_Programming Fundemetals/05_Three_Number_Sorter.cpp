// Three Number Sorter — Input 3 numbers; print them in ascending order using only conditionals (no arrays).

# include <iostream>
using namespace std;

int main() {
    int  a=245363,b=828928,c=537239;
    (a>b && a>c)? (b>c)? cout<<a<<","<<b<<","<<c<<endl: cout<<a<<","<<c<<","<<b<<endl : (b>c&&b>a)? (a>c)? cout<<b<<","<<a<<","<<c<<endl: cout<<b<<","<<c<<","<<a<<endl : (a>b)? cout<<c<<","<<a<<","<<b<<endl: cout<<c<<","<<b<<","<<a<<endl;
    cout<<endl;
    return 0;

}