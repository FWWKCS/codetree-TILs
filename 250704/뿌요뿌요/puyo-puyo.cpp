#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];

int bc = 0, mB = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int count = 0;
vector<vector<int>> visited;

void dfs(int cr, int cc, int x) {
    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + cr;
        int nc = dc[i] + cc;
        
        if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] == x && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            count++;
            dfs(nr, nc, x);
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

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                count = 1;
                dfs(i, j, grid[i][j]);

                mB = max(mB, count);
                if (count >= 4) bc++;
            }
        }
    }

    cout << bc << ' ' << mB;
    return 0;
}
