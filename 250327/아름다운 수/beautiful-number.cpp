#include <iostream>
#include <string>
using namespace std;

int n;
string s = "";

int answer = 0;

bool check() {
    string tmp = "";
    for (char c : s) {
        if (tmp == "") tmp += c;
        else if (!tmp.empty() && tmp.back() == c) tmp += c;
        else return false;

        if (tmp.back()-'0' == tmp.length()) {
            tmp = "";
        } 
    }

    if (!tmp.empty()) return false;
    
    return true;
}

void dfs() {
    if (s.length() == n) {
        if (check()) answer++;
        return;
    } 

    for (int i = 1; i <= 4; i++) {
        s += to_string(i);
        dfs();
        s.pop_back();
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    dfs();

    cout << answer;
    return 0;
}
