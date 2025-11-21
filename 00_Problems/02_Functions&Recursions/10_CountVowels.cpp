// Make a function to count the vowels in a string.

# include <iostream>
using namespace std;

int CountVowel(string word){
    int count =0;
    for(int i = 0; i<word.length();i++){
        word[i] = tolower(word[i]);
        if (word[i]== 'a' ||word[i]== 'e' || word[i]== 'i' || word[i]== 'o' || word[i]== 'u' ){
            count+=1;
        }
    }
    return count;


}

int main() {
    string word = "hello";
    int count = CountVowel(word);
    cout<<count<<endl;
    return 0;
}