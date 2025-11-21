// Create a inverted pyramid of stars

# include<iostream>
using namespace std ;

int main() {
    int rows = 4,k=0;
    for ( int i = rows ; i>=1 ;i--,k=0){
        for(int j=rows-i;j>=1;j--){
            cout<<"  ";
        }
        while(k!= 2*i-1){
            cout<<"* ";
            k++;
        }
        cout<<endl;
    }
    return 0;

}