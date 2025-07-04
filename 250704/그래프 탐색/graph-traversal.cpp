#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<vector<int>> g;
set<int> s;

void dfs(int cur) {
    for (int x : g[cur]) {
        if (x != 1 && s.find(x) == s.end()) {
            s.insert(x);
            dfs(x);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n+1);

    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        g[f].push_back(t); 
        g[t].push_back(f);
    }

    // Please write your code here.
    dfs(1);
    cout << s.size();
    return 0;
}
