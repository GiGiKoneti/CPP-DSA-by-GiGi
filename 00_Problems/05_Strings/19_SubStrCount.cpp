// Find substring occurrence count.
#include <iostream>
using namespace std;

int main() {
    string text = "abaa abababab";
    string sub  = "aba";
    int count = 0;

    for (int i = 0; i <= text.size() - sub.size(); i++) {
        bool match = true;

        for (int j = 0; j < sub.size(); j++) {
            if (text[i + j] != sub[j]) {
                match = false;
                break;
            }
        }

        if (match) count++;
    }

    cout << "Occurrences: " << count << endl;
    return 0;
}