// Leap Year Check — Given a year, determine if it’s a leap year.

# include <iostream>
using namespace std ;

int main() {
    int year;
    cout<<"Enter the year : ";
    cin>>year;
    ((year%4 == 0)&& (year%100 != 0) || (year%400 == 0)) ? cout<<"Leap"<<endl : cout<<"Non-Leap"<<endl;
    return 0;
}