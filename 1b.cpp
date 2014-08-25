#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void fun1(string &s) {
    int col = 0;
    int row = 0;

    size_t i = 0;
    while ('A' <= s[i] && s[i] <= 'Z') {
        col *= 26;
        col += s[i]-'A'+1;
        i++;
    }
    while (i < s.size()) {
        row *= 10;
        row += s[i]-'0';
        i++;
    }
    cout << 'R' << row << 'C' << col << endl;
}

void fun2(string &s) {
    int col = 0;
    int row = 0;

    size_t i = 1;
    while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
        row *= 10;
        row += s[i]-'0';
        i++;
    }
    if (row == 0) {
        fun1(s);
        return ;
    }
    if (i == s.size()) {
        cout << 'R' << row << 'C' << 18 << endl;
        return ;
    }
    i++;
    while (i < s.size()) {
        col *= 10;
        col += s[i]-'0';
        i++;
    }
    string scol;
    while (col) {
        if (col%26 == 0) {
            scol.push_back('Z');
            col /= 26;
            col--;
        }
        else {
            scol.push_back('A'+col%26-1);
            col /= 26;
        }
    }
    reverse(scol.begin(), scol.end());
    cout << scol << row << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        if (s[0] != 'R')
            fun1(s);
        else
            fun2(s);
    }

    return 0;
}
