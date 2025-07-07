#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> visited;
int answer = 0;

void bfs(queue<pair<int, int>>& q) {
    
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;

            if (nr > -1 && nr < n && nc > -1 && nc < n && !visited[nr][nc] && !grid[nr][nc]) {
                visited[nr][nc] = 1;
                answer++;
                q.push({nr, nc});
            }
        }

    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    visited.resize(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        q.push({r-1, c-1});
        visited[r-1][c-1] = 1;
        answer++;
    }

    // Please write your code here.
    bfs(q);
    cout << answer;
    return 0;
}
