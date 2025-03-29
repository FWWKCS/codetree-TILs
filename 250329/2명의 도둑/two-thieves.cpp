#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c;
int weight[10][10];

pair<int, int> A, B;
int answer = 0;

int X, Y;

void gr(vector<int>& v, int k, int cur, int w, int& z) {
    z = max(z, w);
    for (int i = k+1; i < m; i++) {
        if (cur + v[i] <= c) {
            gr(v, i, cur+v[i], w+(v[i]*v[i]), z);
        }
    }
}


void check() {
    vector<int> vA, vB;
    for (int i = 0; i < m; i++) {
        vA.push_back(weight[A.first][A.second+i]);
        vB.push_back(weight[B.first][B.second+i]);
    }
    
    X = 0, Y = 0;
    gr(vA, -1, 0, 0, X);
    gr(vB, -1, 0, 0, Y);


    if (X+Y > answer) {
        // for (auto x : vA) cout << x << ' '; cout << '\n';
        // for (auto x : vB) cout << x << ' '; cout << '\n';
        // cout << X << ' ' << Y << '\n';
        // cout << X+Y << '\n';
        answer = X+Y;   
    }
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