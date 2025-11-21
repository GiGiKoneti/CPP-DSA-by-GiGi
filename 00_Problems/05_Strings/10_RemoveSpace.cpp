// Remove spaces from string.
# include <iostream>
using namespace std;

/*
int main() {
    string line = "My Name is GiGi",result;
    for(char &c : line){
        if(c!=' ')
            result+=c;
    }
    cout<<result<<endl;
}
*/

int main(){
    string line = "My Name is GiGi";
    line.erase(remove(line.begin(),line.end(),' '),line.end());
    cout<<line<<endl;
    return 0;
}
