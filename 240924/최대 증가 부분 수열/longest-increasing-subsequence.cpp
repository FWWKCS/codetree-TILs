#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int table[N];
    int dp[N];

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        table[i] = x;
        dp[i] = 1;
    }

    dp[0] = 1;
    int answer = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i-1; j > -1; j--) {
            if (table[j] < table[i]) dp[i] = max(dp[i], dp[j] + 1);
            answer = max(answer, dp[i]);
        }
    }

    cout << answer;
    return 0;
}