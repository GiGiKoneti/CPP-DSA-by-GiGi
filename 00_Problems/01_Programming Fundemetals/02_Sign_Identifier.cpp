// Sign Identifier — Input an integer x; print "Positive", "Negative", or "Zero".

# include <iostream>
using namespace std;

int main () {
    int num ;
    cout<<"Enter any integer : ";
    cin>>num;
    (num==0)? cout<<"Zero"<<endl : (num>0) ? cout<<"Positive"<<endl : cout<<"Negative"<<endl;
    return 0;
}
