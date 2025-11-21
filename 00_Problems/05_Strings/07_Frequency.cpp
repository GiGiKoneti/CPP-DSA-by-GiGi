// Count the frequency of each character.
# include<iostream>
using namespace std;
int main() {
    string word = "Hello World";

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

        cout << word[i] << " occurs " << count << " times" << endl;
    }

    return 0;
}