#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> lines;
vector<vector<int>> bo;
vector<int> target;

vector<vector<int>> rm;

int answer = 1e9;

void check(vector<vector<int>>& board, vector<int>& result) {
    for (int i = 1; i <= n; i++) {
        for (int r = 1; r <= 15; r++) {
            int cur = result[i];
            result[i] += board[r][cur];
        }
    }

    // for (auto x : result) cout << x << ' ';
    // cout << '\n';
}

void dfs(int depth, int last) {
    if (depth > answer) return;

    for (int i = last+1; i < m; i++) {
        int r = lines[i].first, c = lines[i].second;

        rm[r][c] = 1;
        rm[r][c+1] = -1;
        dfs(depth+1, i);
        rm[r][c] = rm[r][c+1] = 0;
    }

    
    vector<int> result(n+1);
    for (int i = 1; i <= n; i++) result[i] = i;

    check(rm, result);

    if (target == result) answer = min(answer, depth);
}

int main() {
    cin >> n >> m;
    bo.resize(16, vector<int>(n+1, 0));
    rm.resize(16, vector<int>(n+1, 0));
    target.resize(n+1);
    for (int i = 1; i <= n; i++) target[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        lines.push_back({b, a});
        bo[b][a] = 1;
        bo[b][a+1] = -1;
    }

    check(bo, target);

    // Please write your code here.
    dfs(0, -1);

    cout << answer;

    return 0;
}
