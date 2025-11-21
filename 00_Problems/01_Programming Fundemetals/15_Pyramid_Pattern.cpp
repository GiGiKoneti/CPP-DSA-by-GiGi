/* Pyramid Pattern

   *
  ***
 *****
*******


*/

#include <iostream>
using namespace std;

int main() {
    int rows = 4,k=0;
    for ( int i = 1 ; i<=rows ;i++,k=0){
        for(int j=1;j<=rows-i;j++){
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