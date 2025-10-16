#include <iostream>
#include <vector>
using namespace std;

int N;
int red[201];
int blue[201];
vector<vector<vector<int>>> dp;
int main() {
    cin >> N;
    dp.resize(2*N+1, vector<vector<int>>(N+1, vector<int>(N+1, 0)));
    for (int i = 1; i <= 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }

    // Please write your code here.
    // dp[i][r][c]: i번째 카드를 고르는 상황에서 red r번, blue c번 일때의 최대 합
    for (int i = 1; i <= 2*N; i++) {
        for (int r = 0; r <= N; r++) {
            for (int c = 0; c <= N; c++) {
                if (r+c == i) {
                    if (r > 0) {
                        // red 선택
                        dp[i][r][c] = max(dp[i][r][c], dp[i-1][r-1][c]+red[i]);
                    }
                    if (c > 0) {
                        // blue 선택
                        dp[i][r][c] = max(dp[i][r][c], dp[i-1][r][c-1]+blue[i]);
                    }
                }
            }
        }
    }

    cout << dp[2*N][N][N];
    return 0;
}
