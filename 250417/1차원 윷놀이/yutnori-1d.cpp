#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int nums[12];
int answer = 0;

void dfs(int depth, vector<int> info) {
    if (depth == n) {
        int point = 0;
        for (int x : info) {
            if (x == m) point++;
        }

        answer = max(answer, point);
        return;
    }

    for (int i = 0; i < k; i++) {
        int bpos = info[i];
        info[i] = min(info[i]+nums[depth], m);
        dfs(depth+1, info);
        info[i] = bpos;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> info(k, 1);
    // Please write your code here.

    dfs(0, info);
    cout << answer;
    return 0;
}
