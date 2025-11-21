// Write an overloaded function for area of circle,rectangle,triangle.

# include <iostream>
using namespace std;

float Area(int l,int w){
    return l*w;
}
float Area(int r){
    return 3.14*r*r;
}
float Area(int a , int b, int c){
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    int r = 2, l=2,w=2,a=3,b=4,c=5;
    cout<<"Area of Circle : "<<Area(r)<<endl;
    cout<<"Area of Rectangle : "<<Area(l,w)<<endl;
    cout<<"Area of Triangle : "<<Area(a,b,c)<<endl;
    return 0;
}