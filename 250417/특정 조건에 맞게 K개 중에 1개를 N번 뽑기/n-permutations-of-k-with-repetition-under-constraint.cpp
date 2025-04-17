#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> S;
// vector<int> arr;
int K, N;

void dfs(int depth, vector<int> arr) {
    if (depth == N) {
        S.insert(arr);
        return;
    }

    for (int i = 1; i <= K; i++) {
        arr[depth] = i;
        dfs(depth+1, arr);
    }
}

int main() {
    cin >> K >> N;
    vector<int> arr(N);
    // Please write your code here.
    dfs(0, arr);

    for (auto v : S) {
        bool check = true;
        for (int k = 0; k < N-2; k++) {
            if (v[k] == v[k+1] && v[k+1] == v[k+2]) {
                check = false;
                break;
            }
        }

        if (check) {
            for (auto x : v) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
