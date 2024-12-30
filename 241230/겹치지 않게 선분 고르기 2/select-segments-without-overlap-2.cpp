#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customSorted(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    int answer = 1;
    int n; cin >> n;
    vector<pair<int, int>> lines(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        lines[i] = {x, y};
    }

    sort(lines.begin(), lines.end(), customSorted);
    // for (pair line : lines) {
    //     cout << line.first << ' ' << line.second << '\n';
    // }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (lines[i].second < lines[j].first) dp[j] = max(dp[j], dp[i]+1);
            answer = max(answer, dp[j]);
        }
    }

    cout << answer;
    return 0;
}