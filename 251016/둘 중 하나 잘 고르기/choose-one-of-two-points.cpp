#include <iostream>
#include <vector>
using namespace std;

int N;
int red[201];
int blue[201];
vector<vector<int>> dp;
int main() {
    cin >> N;
    dp.resize(2*N+1, vector<int>(N+1, -1e9));
    for (int i = 1; i <= 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }

    // Please write your code here.
    // dp[r][c]: r번째 카드를 고를때 red를 c번 고른 상태의 최대합
    dp[0][0] = 0;
    for (int r = 1; r <= 2*N; r++) {
        for (int c = 0; c <= N; c++) {
            if (c > 0 && dp[r-1][c-1] >= 0) dp[r][c] = max(dp[r][c], 
                                                        max(dp[r-1][c]+blue[r], dp[r-1][c-1]+red[r]));
            else if (dp[r-1][c] >= 0) dp[r][c] = max(dp[r][c], dp[r-1][c]+blue[r]);
        }
    }

    cout << dp[2*N][N];
    return 0;
}
