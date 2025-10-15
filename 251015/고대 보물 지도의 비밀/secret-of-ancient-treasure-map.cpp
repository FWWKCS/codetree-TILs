#include <iostream>
#include <vector>
using namespace std;

int n, k;
int numbers[100000];
vector<vector<int>> dp;
int main() {
    cin >> n >> k;
    dp.resize(n, vector<int>(k+1, -1e9));
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.
    // dp[r][c]: r번째 원소가 마지막으로 합에 적용되며, 음수가 c번째인 경우 
    if (numbers[0] < 0) dp[0][1] = numbers[0];
    else dp[0][0] = numbers[0];

    for (int r = 1; r < n; r++) {
        for (int c = 0; c <= k; c++) {
            if (numbers[r] < 0) {
                if (c > 0) dp[r][c] = max(numbers[r], dp[r-1][c-1]+numbers[r]);
                // 구간을 새로 시작하거나 합치거나
            }
            else { // 양수
                // 구간을 새로 시작하거나 합치거나
                dp[r][c] = max(numbers[r], dp[r-1][c]+numbers[r]);
            }
        }
    }

    int answer = -1e9;
    for (auto r : dp) {
        for (auto c : r) {
            // cout << c << ' ';
            answer = max(answer, c);
        } 
        // cout << '\n';
    }
    cout << answer;
    return 0;
}
