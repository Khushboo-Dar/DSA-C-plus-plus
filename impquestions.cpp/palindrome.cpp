#include <iostream>
#include <cctype> // Include the cctype header for tolower function
using namespace std;

bool isValid(char ch) {
    return (isalnum(ch) != 0);
}

int palindrome(string a) {
    int st = 0;
    int e = a.length() - 1;

    while (st <= e) {
        if (a[st] != a[e]) {
            return 0;
        } else {
            st++;
            e--;
        }
    }

    return 1;
}

bool checkPalindrome(string s) {
    string temp = "";

    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isValid(s[i])) {
            temp.push_back(tolower(s[i])); // Use tolower function here if needed
        }
    }

    return palindrome(temp);
}

int main() {
    string s;
    cin >> s;
    cout << (checkPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
