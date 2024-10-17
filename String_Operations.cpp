#include <bits/stdc++.h>
using namespace std;

void substring(string& substr, const string& str, int initial, int len) {
    int strlen = str.length();

    if (strlen < (initial + len)) {
        cout << "Invalid initial position or length." << endl;
        return;
    }
    int i = initial;
    int j = 0;
    while (j < len) {
        substr[j] = str[i];
        j++;
        i++;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the initial position: ";
    int initial;
    cin >> initial;
    cout << "Enter the length: ";
    int len;
    cin >> len;
    string substr(len, ' ');

    substring(substr, str, initial, len);

    cout << "Extracted substring: " << substr << endl;

    return 0;
}
