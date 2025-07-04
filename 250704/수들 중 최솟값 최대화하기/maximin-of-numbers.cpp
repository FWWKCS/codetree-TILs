#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[10][10];
vector<int> col(10, 0);

int answer = 0;

void solve(int cur, int row) {
    if (row == n) {
        answer = max(answer, cur);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i]) {
            col[i] = 1;
            solve(min(cur, grid[row][i]), row+1);
            col[i] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    solve(1e9, 0);
    cout << answer;

    return 0;
}
