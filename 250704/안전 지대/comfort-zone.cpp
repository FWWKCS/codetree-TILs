#include <iostream>
#include <vector>
using namespace std;

int N, M;
int grid[50][50];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int aK = 0, t = 0;

vector<vector<int>> visited;
void dfs(int cr, int cc, int K) {
    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + cr;
        int nc = dc[i] + cc;

        if (nr > -1 && nr < N && nc > -1 && nc < M && grid[nr][nc] > K && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            dfs(nr, nc, K);
        }
    }
}

int main() {
    cin >> N >> M;

    int mH = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            mH = max(mH, grid[i][j]);
        }
    }

    for (int K = 1; K <= mH; K++) {
        visited.resize(N, vector<int>(M, 0));
        int total = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] > K && !visited[i][j]) {
                    visited[i][j] = 1;
                    dfs(i, j, K);
                    total++;
                }
            }
        }

        visited.clear();
        if (total > t) {
            aK = K; t = total;
        }
    }

    cout << aK << ' ' << t;
    return 0;
}
