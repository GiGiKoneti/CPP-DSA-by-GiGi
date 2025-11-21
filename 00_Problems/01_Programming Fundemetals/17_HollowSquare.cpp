// Generate a Hollow Square using nested loops .

# include <iostream>
using namespace std;
 

int main() {
    for (int n =0;n<5;n++){
        for(int m=0;m<5;m++){
            if(n==0||n==4||m==0||m==4){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}


