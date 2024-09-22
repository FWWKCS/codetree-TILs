#include <iostream>
#define MAX 100
using namespace std;

int n; 
int table[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];

int main() {
    cin >> n;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            int x; cin >> x;
            table[r][c] = x;
        }
    }

    dp[1][1] = table[1][1];
    for (int i = 2; i <= n; i++) {
        dp[1][i] = max(table[1][i], dp[1][i-1]);
        dp[i][1] = max(table[i][1], dp[i-1][1]);
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            dp[r][c] = max(table[r][c], min(dp[r-1][c], dp[r][c-1]));
            cout << dp[r][c] << ' ';
        }
    }

    cout << dp[n][n];
    return 0;
}