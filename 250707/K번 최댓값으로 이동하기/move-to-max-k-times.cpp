#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int r, c;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>>& q) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[r][c] = 1;
    int val = grid[r][c];

    int tr = r, tc = c, tv = -1;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + r;
            int nc = dc[i] + c;

            if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] < val && !visited[nr][nc]) {
                if (grid[nr][nc] > tv) {
                    tr = nr; tc = nc; tv = grid[nr][nc];
                }
                else if (grid[nr][nc] == tv) {
                    if (nr < tr) {
                        tr = nr, tc = nc;
                    }
                    else if (nr == tr && nc < tc) {
                        tc = nc;
                    }
                }

                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    r = tr, c = tc;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--; c--;

    // Please write your code here.
    queue<pair<int, int>> q;
    while (k--) {
        q.push({r, c});
        bfs(q);
    }

    cout << r+1 << ' ' << c+1;
    return 0;
}
