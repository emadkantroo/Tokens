#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++; // Move to next character in s
        }
        j++; // Move to next character in t
    }
    return i == s.length(); // Check if all characters in s were found
}

int main() {
    string s = "abc";
    string t = "ahbgdc";
    if (isSubsequence(s, t)) {
        cout << "Yes, s is a subsequence of t.";
    } else {
        cout << "No, s is not a subsequence of t.";
    }
    return 0;
}
