#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, m;
int grid[100][100];
vector<pair<int, int>> pos;

vector<pair<int, int>> rocks;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int answer = 0;

void bfs() {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q; 
    for (int i = 0; i < k; i++) {
        q.push(pos[i]);
        visited[pos[i].first][pos[i].second] = 1;
    }

    int total = k;
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr, nc = dc[i] + cc;
            if (nr > -1 && nr < n && nc > -1 && nc < n && !visited[nr][nc] && grid[nr][nc] == 0) {
                visited[nr][nc] = 1;
                total++;
                q.push({nr, nc});
            }
        }
    }

    answer = max(answer, total);
}

void dfs(int last, int depth) {
    if (depth == m) {
        bfs();
        return;
    }

    for (int i = last+1; i < rocks.size(); i++) {
        int r = rocks[i].first, c = rocks[i].second;
        grid[r][c] = 0;
        dfs(i, depth+1);
        grid[r][c] = 1;
    }
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) rocks.push_back({i, j});
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        pos.push_back({r-1, c-1});
    }

    // Please write your code here.
    dfs(-1, 0);
    cout << answer;
    return 0;
}
