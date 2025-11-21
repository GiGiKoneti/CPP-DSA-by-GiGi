// Check if string is Panagram.

# include <iostream>
# include <set>
# include <vector>
# include<algorithm>
using namespace std;

int main() {
    string line="The quick brown fox jumps over the lazy dog";
    line.erase(remove(line.begin(),line.end(),' '),line.end());
    for(char &i:line) i=tolower(i);
    set<char> alp(line.begin(),line.end());
    if(alp.size()==26) 
        cout<<" panagram";
    else
        cout<<" not Panagram";
    cout<<endl;
    return 0;
}