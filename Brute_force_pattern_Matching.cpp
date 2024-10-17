#include <iostream>
#include <string>
using namespace std;

void bruteForcePatternMatch(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text, pattern ;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    bruteForcePatternMatch(text, pattern);

    return 0;
}
