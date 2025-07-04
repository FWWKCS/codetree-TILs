#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[100][100];

int dr[2] = {1, 0};
int dc[2] = {0, 1};

vector<vector<int>> visited;
int answer = 0;

void dfs(int cr, int cc) {
    if (cr == n-1 && cc == m-1) {
        answer = 1;
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (answer) return; 
        
        int nr = dr[i] + cr;
        int nc = dc[i] + cc;

        if (nr > -1 && nr < n && nc > -1 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            dfs(nr, nc);
            visited[nr][nc] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    dfs(0, 0);
    cout << answer;
    return 0;
}
