#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, h, m;
int grid[100][100];

vector<vector<int>> answer;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c) {
    int result = 1e9;

    vector<vector<int>> board(n, vector<int>(n, 1e9));

    board[r][c] = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(r, c, 0));

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int dt = get<2>(q.front());

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr;
            int nc = dc[i] + cc;
            if (nr > -1 && nr < n && nc > -1 && nc < n && grid[nr][nc] != 1 && board[nr][nc] > dt+1) {
                if (grid[nr][nc] == 3) {
                    // renew
                    result = min(result, dt+1);
                }
                else {
                    q.push(make_tuple(nr, nc, dt+1));
                    board[nr][nc] = dt+1;
                }
            }
        }
    }

    return result < 1e9 ? result : -1;
}   


int main() {
    cin >> n >> h >> m;
    answer.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 2) {
                cout << bfs(r, c) << ' ';
            }
            else cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
