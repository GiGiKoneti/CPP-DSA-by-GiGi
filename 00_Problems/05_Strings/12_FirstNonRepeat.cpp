// Find the first non-repeating character.
# include<iostream>
using namespace std;

int main() {
    string word;
    cout<<"Enter the string :";
    getline(cin,word);

    vector<bool> visited(word.size(), false);

    for (int i = 0; i < word.size(); i++) {
        if (visited[i] == true)
            continue;

        int count = 1;

        for (int j = i + 1; j < word.size(); j++) {
            if (word[i] == word[j]) {
                visited[j] = true;
                count++;
            }
        }

        if (count==1){
            cout<<word[i];
            break;
        }
        
    }
    cout<<endl;

    return 0;
}