#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int n;
int r1, c1, r2, c2;
vector<vector<int>> board;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(r1, c1, 0));
    board[r1][c1] = 0;

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int cd = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;
            if (nr > 0 && nr <= n && nc > 0 && nc <= n && board[nr][nc] > cd+1) {
                q.push(make_tuple(nr, nc, cd+1));
                board[nr][nc] = cd+1;
            }
        }
    }
} 

int main() {
    cin >> n;
    board.resize(n+1, vector<int>(n+1, 1e9));
    cin >> r1 >> c1 >> r2 >> c2;

    // Please write your code here.
    bfs();

    cout << (board[r2][c2] < 1e9 ? board[r2][c2] : -1);
    return 0;
}
