#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
int a[100][100];
vector<vector<int>> board;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    board[0][0] = 0;

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int cd = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;

            if (nr > -1 && nr < n && nc > -1 && nc < m && a[nr][nc] != 0 && board[nr][nc] > cd+1) {
                q.push(make_tuple(nr, nc, cd+1));
                board[nr][nc] = cd+1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    board.resize(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.

    bfs();
    cout << board[n-1][m-1];

    return 0;
}
