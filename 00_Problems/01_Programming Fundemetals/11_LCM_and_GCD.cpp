// LCM and GCD — Find LCM and GCD of two numbers using loops and conditional logic.

# include <iostream>
# include <math.h>

using namespace std ;



int main (){
    int a = 6,b=2;
    int tempA=a,tempB=b;
    int TwoPower2=0,ThreePower2=0,FivePower2=0,SevenPower1=0;
    int TwoPower1=0,ThreePower1=0,FivePower1=0,SevenPower2=0;


    while(tempA){
        if(tempA%2==0){
            TwoPower1+=1;
            tempA=tempA/2;

        }
        if(tempA%3==0){
            ThreePower1+=1;
            tempA=tempA/3;

        }   
        if(tempA%5==0){
            FivePower1+=1;
            tempA=tempA/5;

        } 
        if(tempA%7==0){
            SevenPower1+=1;
            tempA=tempA/7;

        } 
        cout<<".";
    }
    while(tempB){
        if(tempB%2==0){
            TwoPower2+=1;
            tempB=tempB/2;

        }
        if(tempB%3==0){
            ThreePower2+=1;
            tempB=tempB/3;

        }
        if(tempB%5==0){
            FivePower2+=1;
            tempB=tempB/5;

        }
        if(tempA%7==0){
            SevenPower1+=1;
            tempB=tempB/7;

        }
        cout<<",";
    }

    int LCM = pow(2,max(TwoPower1,TwoPower2))*pow(3,max(ThreePower1,ThreePower2))*pow(5,max(FivePower1,FivePower2))*pow(7,max(SevenPower1,SevenPower2));
    int GCD = 
    cout<<LCM<<endl;



}