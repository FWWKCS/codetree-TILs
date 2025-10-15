#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int first_cards[1000+1];
int second_cards[1000+1];
vector<vector<int>> dp;
int main() {
    cin >> n;
    dp.resize(n+1, vector<int>(n+1, -1e9));
    for (int i = 1; i <= n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> second_cards[i];
    }

    // Please write your code here.
    dp[0][0] = 0;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            int score = (first_cards[c] > second_cards[r] ? second_cards[r] : 0);
            // 비교
            if (r > 1 && first_cards[c] > second_cards[r-1] && dp[r-1][c] >= 0) {
                dp[r][c] = max(dp[r][c], dp[r-1][c]+score);
            }
            
            if (c > 1 && first_cards[c-1] < second_cards[r] && dp[r][c-1] >= 0) {
                dp[r][c] = max(dp[r][c], dp[r][c-1]+score);
            }

            // 버림
            if (dp[r-1][c-1] >= 0) dp[r][c] = max(dp[r][c], dp[r-1][c-1]+score);
        }
    }

    // for (auto r : dp) {
    //     for (auto c : r) cout << c << ' ';
    //     cout << '\n';
    // }

    int answer = *max_element(dp[n].begin(), dp[n].end());
    for (int r = 0; r <= n; r++) answer = max(answer, dp[r][n]);
    cout << answer;
    return 0;
}
