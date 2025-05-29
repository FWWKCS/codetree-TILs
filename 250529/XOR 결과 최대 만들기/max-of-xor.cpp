#include <iostream>

using namespace std;

int n, m;
int A[20];

int answer = 0;

void dfs(int cur, int last, int depth) {
    if (depth == m) {
        answer = max(answer, cur);
        return;
    }

    for (int i = last+1; i < n; i++) {
        dfs(cur^A[i], i, depth+1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    for (int i = 0; i <= n-m; i++) {
        dfs(A[i], i, 1);
    }

    cout << answer;
    return 0;
}