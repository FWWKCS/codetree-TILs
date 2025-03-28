#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> l;
int answer = 0;

void dfs(int depth, int last) {
    answer = max(answer, depth);

    for (int i = 0; i < n; i++) {
        if (last < l[i].first) {
            dfs(depth+1, l[i].second);
        }
    }
}

int main() {
    cin >> n;
    l.resize(n);
    
    for (auto &x : l) {
        int x1, x2; cin >> x1 >> x2;
        x = {x1, x2};
    }
    sort(l.begin(), l.end());

    // Please write your code here.
    dfs(0, 0);
    cout << answer;
    return 0;
}
