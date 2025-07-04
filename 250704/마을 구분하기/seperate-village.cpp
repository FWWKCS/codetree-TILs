#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> visited;
int total = 0;
vector<int> result;

void dfs(int cr, int cc) {
    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + cr;
        int nc = dc[i] + cc;

        if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            total++;
            dfs(nr, nc);
        }
    }
}

int main() {
    cin >> n;
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] && !visited[i][j]) {
                visited[i][j] = 1;
                total = 1;
                dfs(i, j);
                result.push_back(total);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto x : result) cout << x << '\n';
    return 0;
}
