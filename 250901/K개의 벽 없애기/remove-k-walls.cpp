#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;

int answer = 1e9;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs() {
    vector<vector<int>> board(n, vector<int>(n, 1e9));
    board[r1][c1] = 0;
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(r1, c1, 0));

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int dt = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;
            if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] != 1 && board[nr][nc] > dt+1) {
                q.push(make_tuple(nr, nc, dt+1));
                board[nr][nc] = dt+1;
            }
        }
    }

    return board[n-1][n-1];
}

void dfs(int depth, int pos) {
    if (depth == k) {
        answer = min(answer, bfs());
        return;
    }

    for (int r = pos / n; r < n; r++) {
        for (int c = pos % n; c < n; c++) {
            if (grid[r][c] == 1) {
                grid[r][c] = 0;
                dfs(depth+1, r*n+c+1);
                grid[r][c] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.
    dfs(0, 0);

    cout << (answer < 1e9 ? answer : -1);

    return 0;
}
