#include <iostream>
#include <vector>
using namespace std;

int w[101];
int v[101];

vector<vector<int>> dp;

int main() {
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }    

    dp.resize(N+1, vector<int>(M+1, 0));

    // Please write your code here.
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j-w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-w[i]], dp[i][j-w[i]])+v[i]);
            }
            else dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[N][M];
    return 0;
}