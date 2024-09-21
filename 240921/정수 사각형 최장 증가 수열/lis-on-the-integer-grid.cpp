#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dfs(vector<vector<int>> &table, vector<vector<int>> &dp, int r, int c) {
    if (dp[r][c] > -1) return dp[r][c];
    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // 어디서 table[r][c]로 이동할 수 있을지 (자신보다 작은 수가 주변에 있는지) 탐색
    bool found = false;
    for (int i = 0; i < 4; i++) {
        int dy = r+dr[i];
        int dx = c+dc[i];
        
        if (dy > -1 && dy < table.size() && dx > -1 && dx < table.size() && table[dy][dx] < table[r][c]) {
            found = true;
            dp[r][c] = max(dp[r][c], dfs(table, dp, dy, dx) + 1);
        }
    }

    if (!found) dp[r][c] = 1;
    
    return dp[r][c];
}

int main() {
    FASTIO;

    int n; cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int x; cin >> x;
            table[r][c] = x;
        }
    }

    int answer = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            answer = max(answer, dfs(table, dp, r, c));
        }
    }

    cout << answer;

    return 0;
}