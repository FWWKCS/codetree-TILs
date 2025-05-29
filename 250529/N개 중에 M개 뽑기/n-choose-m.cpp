#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> S;

void dfs(int last) {
    if (S.size() == M) {
        for (auto x : S) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = last+1; i <= N; i++) {
        // if (S.find(i) != S.end()) continue;

        S.insert(i);
        dfs(i);
        S.erase(i);
    }
}

int main() {
    cin >> N >> M;

    // Please write your code here.
    dfs(0);
    return 0;
}
