#include <iostream>
#include <string>
using namespace std;

int n;
string s = "";
bool found = false;

bool check() {
    int len = s.length();
    for (int l = 1; l <= len / 2; l++) {
        string a = s.substr(len - 2 * l, l);
        string b = s.substr(len - l, l);
        if (a == b) return false;
    }
    return true;
}

void makeSequence() {
    if (found) return;

    if (s.length() == n) {
        cout << s << '\n';
        found = true;
        return;
    }

    for (int i = 4; i <= 6; i++) {
        s += to_string(i);
        if (check()) makeSequence(); 
        s.pop_back();
    }
}

int main() {
    cin >> n;
    makeSequence();
    return 0;
}
