#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, u, d;
int grid[8][8];
vector<pair<int, int>> sel;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int answer = 0;

void bfs() {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (auto s : sel) {
        q.push(s);
        visited[s.first][s.second] = 1;
    }

    int total = k;
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr, nc = dc[i] + cc;
            if (nr > -1 && nr < n && nc > -1 && nc < n && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                int gaps = abs(grid[cr][cc] - grid[nr][nc]);
                if (u <= gaps && gaps <= d) {
                    total++;
                    q.push({nr, nc});
                }
            }
        }
    }

    answer = max(answer, total);
}

void dfs(int lr, int lc, int depth) {
    if (depth == k) {
        bfs();
        return;
    }

    for (int r = lr; r < n; r++) {
        for (int c = lc+1; c < n; c++) {
            sel.push_back({r, c});
            dfs(lr, lc, depth+1);
            sel.pop_back();
        }
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    dfs(0, -1, 0);
    cout << answer;
    return 0;
}
