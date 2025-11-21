#include <iostream>
#include <cstring>  // Required for strcpy, strcat, strcmp
using namespace std;

int main() {
    // ---------- 1. strcpy() ----------
    char str1[100];
    char str2[100] = "Majd";

    // Copying literal string into str1
    strcpy(str1, "GiGi");
    cout << "str1 after copying 'GiGi': " << str1 << endl;

    // Copying str2 into str1
    strcpy(str1, str2);
    cout << "str1 after copying str2 ('Majd'): " << str1 << endl;

    // ---------- 2. strcat() ----------
    char str3[100] = "GiGi";
    char str4[100] = "Molki";

    // Concatenating str4 to str3 → str3 = "GiGiMolki"
    strcat(str3, str4);
    cout << "str3 after concatenation: " << str3 << endl;
    cout << "str4 remains unchanged: " << str4 << endl;

    // ---------- 3. strcmp() ----------
    char str5[100] = "BuBu";
    char str6[100] = "BuBu";
    char str7[100] = "DuDu";

    // Comparing identical strings → returns 0
    cout << "Comparing str5 and str6: " << strcmp(str5, str6) << endl;

    // Comparing str5 < str7 → returns negative value
    cout << "Comparing str5 and str7: " << strcmp(str5, str7) << endl;

    // Comparing str7 > str6 → returns positive value
    cout << "Comparing str7 and str6: " << strcmp(str7, str6) << endl;

    return 0;
}