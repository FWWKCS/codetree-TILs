#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[20][20];

vector<pair<int, int>> pos;
vector<int> mode;

int answer = 0;

int check() {
    vector<vector<int>> table(n, vector<int>(n, 0));

    for (int i = 0; i < pos.size(); i++) {
        int r = pos[i].first, c = pos[i].second;
        int m = mode[i];
        table[r][c] = 1;
        switch (m) {
            case 1: {
                table[max(r-2, 0)][c] = 1;
                table[max(r-1, 0)][c] = 1;
                table[min(r+1, n-1)][c] = 1;
                table[min(r+2, n-1)][c] = 1;
                break;
            }
            case 2: {
                table[max(r-1, 0)][c] = 1;
                table[r][max(c-1, 0)] = 1;
                table[min(r+1, n-1)][c] = 1;
                table[r][min(c+1, n-1)] = 1;
                break;
            }
            case 3: {
                if (r-1 > -1 && c-1 > -1) table[r-1][c-1] = 1;
                if (r-1 > -1 && c+1 < n) table[r-1][c+1] = 1;
                if (r+1 < n && c-1 > -1) table[r+1][c-1] = 1;
                if (r+1 < n && c+1 < n) table[r+1][c+1] = 1;
                break;
            }
        }
    }

    int total = 0;
    for (auto &r : table) {
        for (auto &c : r) {
            if (c) total++;
        }
    }

    return total;
}

void dfs(int depth) {
    if (mode.size() == pos.size()) {
        answer = max(answer, check());
        return;
    }

    for (int i = 1; i <= 3; i++) {
        mode.push_back(i);
        dfs(depth+1);
        mode.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) pos.push_back({i, j});
        }
    }

    // Please write your code here.
    dfs(0);
    cout << answer;
    return 0;
}
