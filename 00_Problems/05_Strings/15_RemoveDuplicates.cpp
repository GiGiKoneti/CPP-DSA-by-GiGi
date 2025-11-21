// Remove duplicate characters.
# include<iostream>
using namespace std;

int main(){
    string word="heLlo Worldw";
    for(char &c : word)
        c=tolower(c);

    vector<bool> visited(word.size(),false);

    for(int i =0;i<word.size();i++){
        if(visited[i]==true)
            continue;

        for(int j= i+1;j<word.size();j++){
            if(word[i]==word[j]){
                visited[j]=true;
                word[j]='*';
            }
        }

    }
    word.erase(remove(word.begin(),word.end(),'*'),word.end());
    cout<<word<<endl;
    return 0;

    
}