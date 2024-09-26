#include <iostream>
#define MAX 1000
using namespace std;

int table[MAX+1];
int dp[MAX+1] = {0, };

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        table[i] = x;
    }

    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            if (j-i <= table[i]) dp[j] = max(dp[j], dp[i]+1);
        }
    }

    int answer = 0;
    for (int i = 2; i <= n; i++) {
        // cout << dp[i] << ' ';
        if (dp[i] == 0) break;
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}