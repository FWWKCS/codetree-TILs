#include <iostream>
#define MAX 50
using namespace std;

int table[MAX+1][MAX+1];
int dp[MAX+1][MAX+1] = {0, };

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            table[i][j] = x;
        }
    }

    dp[1][1] = 1;
    for (int i = 2; i <= m; i++) dp[1][i] = -1;
    for (int i = 2; i <= n; i++) dp[i][1] = -1;

    int answer = 1;
    for (int r = 2; r <= n; r++) {
        for (int c = 2; c <= m; c++) {
            bool found = false;
            for (int y = r-1; y > 0; y--) {
                for (int x = c-1; x > 0; x--) {
                    if (table[r][c] > table[y][x] && dp[y][x] != -1) {
                        dp[r][c] = max(dp[r][c], dp[y][x] + 1);
                        found = true;
                    }
                }
            }
            
            if (!found) dp[r][c] = -1;
            else answer = max(answer, dp[r][c]);
        }
    } 

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << answer;
    return 0;
}