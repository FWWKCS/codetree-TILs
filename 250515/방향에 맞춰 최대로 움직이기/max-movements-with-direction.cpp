#include <iostream>
#include <vector>
using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;

int answer = 0;

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int cr, int cc, int depth) {
    int nr = cr, nc = cc;
    while (true) {
        // cout << "check pos: " << nr << ' ' << nc << "\n";
        nr += dr[move_dir[cr][cc]];
        nc += dc[move_dir[cr][cc]];
        if (nr == -1 || nr == n || nc == -1 || nc == n) break;

        if (num[nr][nc] > num[cr][cc]) {
            dfs(nr, nc, depth+1);
        }
    }

    answer = max(answer, depth);
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    // Please write your code here.
    dfs(r-1, c-1, 0);
    cout << answer;

    return 0;
}
