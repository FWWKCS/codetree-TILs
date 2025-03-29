#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c;
int weight[10][10];

pair<int, int> A, B;
int answer = 0;

void check() {
    int W = 0;
    vector<int> vA, vB;
    for (int i = 0; i < m; i++) {
        vA.push_back(weight[A.first][A.second+i]);
        vB.push_back(weight[B.first][B.second+i]);
    }

    sort(vA.rbegin(), vA.rend());
    sort(vB.rbegin(), vB.rend());

    // for (auto x : vA) cout << x << ' '; cout << '\n';
    // for (auto x : vB) cout << x << ' '; cout << '\n';
 
    int tmp = c;
    for (int i = 0; i < m; i++) {
        if (vA[i] <= tmp) {
            W += vA[i]*vA[i];
            tmp -= vA[i];
        }
    }

    tmp = c;
    for (int i = 0; i < m; i++) {
        if (vB[i] <= tmp) {
            W += vB[i]*vB[i];
            tmp -= vB[i];
        }
    }

    // cout << W << '\n';
    answer = max(answer, W);
}

void dfs(int depth) {
    if (depth == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n-m; j++) {
                A = {i, j};
                dfs(depth+1);
            }
        }
    }

    if (depth == 1) {
        int lR = A.first, lC = A.second;

        for (int i = 0; i < n; i++) {
            if (i < lR) continue;
            for (int j = 0; j <= n-m; j++) {
                if (i == lR && j < lC+m) continue;
                // cout << lR << ' ' << lC << ' ' << i << ' ' << j << '\n';
                B = {i, j};
                check();
            }
        }
    }
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    // Please write your code here.
    dfs(0);
    cout << answer;
    return 0;
}