#include <iostream>
#include <set>

using namespace std;

int n;
int grid[10][10];
set<int> cache;

int answer = 0;

void recursion(int sum, int row) {
    if (row == n) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cache.find(i) == cache.end()) {
            cache.insert(i);
            recursion(sum+grid[row][i], row+1);
            cache.erase(i);
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
    recursion(0, 0);
    cout << answer;
    return 0;
}
