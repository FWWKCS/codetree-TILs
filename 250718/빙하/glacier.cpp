#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int a[200][200];
vector<pair<int, int>> target;
vector<int> meltedLog;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs() {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    int total = 0; 

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cr, nc = dc[i] + cc;
            if (nr > -1 && nr < N && nc > -1 && nc < M && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                if (a[nr][nc] == 1) {
                    total++;
                    target.push_back({nr, nc});
                }
                else q.push({nr, nc});
            }
        }
    }

    for (auto t : target) {
        a[t.first][t.second] = 0;
    }
    target.clear();

    return total;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    while (true) {
        int result = bfs();
        if (result == 0) break;
        meltedLog.push_back(result);
    }

    cout << meltedLog.size() << ' ' << meltedLog.back();
    return 0;
}
