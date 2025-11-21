// Check if a string contains only numbers .
# include <iostream>
using namespace std;

int main() {
    string word="1234",result="Yes";
    
    for(char &c : word){
        if(!(c >= '0' && c <= '9')){
            result="No";
            break;
        
        }
    }
    cout<<result<<endl;
    return 0;
}