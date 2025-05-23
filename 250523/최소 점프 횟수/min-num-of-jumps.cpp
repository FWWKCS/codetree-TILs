#include <iostream>

using namespace std;

int n;
int num[10];

int answer = 1e9;

void track(int cur, int step) {
    if (cur == n-1) {
        answer = min(answer, step);
        return;
    }

    for (int i = 1; i <= num[cur]; i++) {
        if (cur+i < n) track(cur+i, step+1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    track(0, 0);
    cout << (answer < 1e9 ? answer : -1); 
    return 0;
}
