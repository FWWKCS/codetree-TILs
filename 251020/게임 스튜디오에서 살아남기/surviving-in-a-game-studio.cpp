#include <iostream>
#include <vector>
#define MOD 1'000'000'007
using namespace std;

int n;
vector<vector<vector<int>>> dp;

int main() {
    cin >> n;
    dp.resize(n, vector<vector<int>>(3, vector<int>(3, 0)));
    // Please write your code here.
    // G start
    dp[0][0][0] = 1;
    // B start
    dp[0][0][1] = 1;
    // T start
    dp[0][1][0] = 1;


    for (int f = 1; f < n; f++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                // G
                if (c == 0) {
                    dp[f][r][c] = (((dp[f-1][r][0] + dp[f-1][r][1]) % MOD) + dp[f-1][r][2]) % MOD;
                }

                // B
                if (c > 0) {
                    dp[f][r][c] = (dp[f][r][c] + dp[f-1][r][c-1]) % MOD;
                }

                // T
                if (r > 0 && c == 0) {
                    dp[f][r][c] = (((((dp[f][r][c] + dp[f-1][r-1][0]) % MOD) + dp[f-1][r-1][1]) % MOD) + dp[f-1][r-1][2]) % MOD;
                }
            }
        }
    }

    int answer = 0;
    for (auto r : dp[n-1]) {
        for (auto c : r) {
            // cout << c << ' ';
            answer = (answer + c) % MOD;
        }
        // cout << '\n';
    }
    cout << answer;
    return 0;
}
