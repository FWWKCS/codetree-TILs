#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, k;
int grid[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> board;

void bfs() {
    queue<tuple<int, int, int>> q;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 2) {
                q.push(make_tuple(r, c, 0));
                board[r][c] = 0;
            }
        }
    }

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int dt = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;
            if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] == 1 && board[nr][nc] > dt+1) {
                q.push(make_tuple(nr, nc, dt+1));
                board[nr][nc] = dt+1;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    board.resize(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) cout << -1 << ' ';
            else if (board[i][j] == 1e9) cout << -2 << ' ';
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
