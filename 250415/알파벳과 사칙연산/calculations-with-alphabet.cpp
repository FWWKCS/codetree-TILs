#include <iostream>
#include <climits>

using namespace std;

string expression;
long long answer = LLONG_MIN;
int value[6] = {0, };

long long check() {
    long long cur = value[expression[0]-'a'];
    for (int i = 1; i < expression.length(); i+=2) {
        switch (expression[i]) {
            case '+':
                cur += value[expression[i+1]-'a'];
                break;
            case '-':
                cur -= value[expression[i+1]-'a'];
                break;
            case '*':
                cur *= value[expression[i+1]-'a'];
                break;
        }
    }

    return cur;
}

void dfs(int idx) {
    if (idx == 6) {
        answer = max(check(), answer);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        value[idx] = i;
        dfs(idx+1);
    }
}

int main() {
    cin >> expression;

    // Please write your code here.
    dfs(0);

    cout << answer;
    return 0;
}
