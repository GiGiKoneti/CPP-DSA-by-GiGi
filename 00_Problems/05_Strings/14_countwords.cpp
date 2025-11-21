// Count words in a sentence.

/*
# include<iostream>
using namespace std;

int main() {
    string word="Hello World My name is GiGi";
    int count=0;
    for (char &c : word){
        if(c==' '){
            count++;
        }
    }
    cout<<count+1<<endl;
    return 0;

}
*/

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence = "Hello World, My name is GiGi?";
    string word;
    int count = 0;

    stringstream ss(sentence);

    while (ss >> word)   // extracts each word
        count++;

    cout << count << endl;
    return 0;
}