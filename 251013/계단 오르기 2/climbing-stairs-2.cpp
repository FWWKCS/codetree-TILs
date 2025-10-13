#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int coin[1001];
vector<vector<int>> dp;
int main() {
    cin >> n;
    dp.resize(n+1, vector<int>(4, -1e9));
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    dp[0][0] = 0;
    // Please write your code here.
    for (int r = 1; r <= n; r++) {
        for (int c = 0; c <= 3; c++) {
            if (c > 0) {
                // 1칸 이동
                dp[r][c] = max(dp[r][c], dp[r-1][c-1] + coin[r]);
            }

            if (r > 1) {
                // 2칸 이동
                dp[r][c] = max(dp[r][c], dp[r-2][c] + coin[r]);
            }
        }
    }

    // for (auto r : dp) {
    //     for (auto c : r) cout << c << ' ';
    //     cout << '\n';
    // }

    cout << *max_element(dp[n].begin(), dp[n].end());
    return 0;
}
