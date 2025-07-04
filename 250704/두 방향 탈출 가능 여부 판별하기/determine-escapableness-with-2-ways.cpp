#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int dr[2] = {1, 0};
int dc[2] = {0, 1};

int answer = 0;

void dfs(int cr, int cc) {
    if (cr == n-1 && cc == n-1) {
        answer = 1;
        return;
    }

    for (int i = 0; i < 2; i++) {
        int nr = dr[i] + cr;
        int nc = dc[i] + cc;

        if (grid[nr][nc] == 1) {
            dfs(nr, nc);
        }
    }
}

int main() {
    cin >> n >> m;

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
