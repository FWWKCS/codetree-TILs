#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> tmp;

void dfs(int depth) {
    if (depth == N) {
        for (auto x : tmp) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= K; i++) {
        tmp.push_back(i);
        dfs(depth+1);
        tmp.pop_back();
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    dfs(0);
    return 0;
}
