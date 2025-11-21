// Grade Calculator — Input 5 subject marks; print the average and grade (A/B/C/Fail).

# include <iostream>
using namespace std;

int main() {
    int marks[5] ;
    int sum;
    float Avg;
    cout<<"Enter all subjects marks : ";
    for(int i=0;i<5;i++){
        cin>>marks[i];
        sum+=marks[i];

    }
    Avg = sum/5;
    if(Avg>80){
        cout<<"A"<<endl;
    }
    else if (Avg>60){
        cout<<"B"<<endl;
    }
    else if (Avg>35){
        cout<<"C"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    return 0;
    
}