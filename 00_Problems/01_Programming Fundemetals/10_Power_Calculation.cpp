// Power Calculation — Compute a^b using loop multiplication (no pow() function).
# include <iostream>
using namespace std;

# include <iostream>
using namespace std;

int main() {
    int a = 2,b=5,pow=1;
    for(int i =0;i<b;i++){
        pow=pow*a;
    }
    cout<<pow<<endl;
    return 0;

}
