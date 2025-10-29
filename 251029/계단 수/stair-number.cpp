#include <iostream>
#include <vector>
#define MOD 1'000'000'007
using namespace std;

int main() {
    int N; cin >> N;
    // Please write your code here.
    vector<vector<int>> dp(N+1, vector<int>(10, 0));
    for (int c = 1; c <= 9; c++) dp[1][c] = 1;

    for (int r = 2; r <= N; r++) {
        for (int c = 0; c < 10; c++) {
            if (c == 0) dp[r][c] = dp[r-1][1];
            else if (c == 9) dp[r][c] = dp[r-1][8];
            else dp[r][c] = (dp[r-1][c-1] + dp[r-1][c+1]) % MOD;
        }
    }

    int answer = 0;
    for (auto c : dp[N]) answer = (answer + c) % MOD;
    cout << answer;
    return 0;
}