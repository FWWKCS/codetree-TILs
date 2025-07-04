#include <iostream>
#include <vector>
using namespace std;

int n;
int A[10][10];

int answer = 1e9;
vector<int> visited;

void route(int total, vector<int>& visited, int cur, int depth) {
    if (depth == n) {
        if (A[cur][0] != 0) answer = min(answer, total+A[cur][0]);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (A[cur][i] != 0 && !visited[i]) {
            visited[i] = 1;
            route(total+A[cur][i], visited, i, depth+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    visited.resize(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Please write your code here.
    route(0, visited, 0, 1);
    cout << answer;

    return 0;
}
