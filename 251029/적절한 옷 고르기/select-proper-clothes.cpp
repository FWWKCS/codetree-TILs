#include <iostream>
#include <vector>
using namespace std;

int N, M;
int s[200], e[200], v[200];
vector<vector<int>> dp;
int main() {
    cin >> N >> M;
    dp.resize(M+1, vector<int>(N, -1e9));
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }

    for (int x = 0; x < N; x++) {
        if (s[x] <= 1 && 1 <= e[x]) dp[1][x] = 0;
    }

    // Please write your code here.
    for (int r = 2; r <= M; r++) {
        for (int c = 0; c < N; c++) {
            if (s[c] <= r && r <= e[c]) {
                for (int k = 0; k < N; k++) {
                    dp[r][c] = max(dp[r][c], dp[r-1][k] + abs(v[k]-v[c]));
                }
            }
        }
    }

    int answer = -1e9;
    for (int x = 0; x < N; x++) {
        answer = max(answer, dp[M][x]);
    }

    cout << answer;
    return 0;
}
