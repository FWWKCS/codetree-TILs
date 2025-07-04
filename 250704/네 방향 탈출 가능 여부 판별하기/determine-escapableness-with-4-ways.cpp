#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> visited;
bool found = false;

void bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;

            if (nr > -1 && nr < n && nc > -1 && nc < m && a[nr][nc] == 1 && !visited[nr][nc]) {
                if (nr == n-1 && nc == m-1) found = true;
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    bfs(0, 0);
    cout << found;
    return 0;
}
