#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll OFFSET = 20;
int N, M;
int nums[100];
vector<vector<ll>> dp;
int main() {
    cin >> N >> M;
    dp.resize(N, vector<ll>(2*OFFSET+1, 0));
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    // dp[r][c]: r번째 숫자를 더하거나 빼서 c가 만들어질 수 있는 경우의 수
    dp[0][nums[0]+OFFSET]++;
    dp[0][OFFSET-nums[0]]++;
    for (int r = 1; r < N; r++) {
        for (int c = -OFFSET; c <= OFFSET; c++) {
            if (c-nums[r] >= -OFFSET) { // 이전 값에서 nums[r]을 더함
                // if (dp[r-1][c+OFFSET-nums[r]] > 0) cout << r << ' ' << c << ' ' << dp[r-1][c+OFFSET-nums[r]] << '\n';
                dp[r][c+OFFSET] += dp[r-1][c+OFFSET-nums[r]];
            }
            if (c+nums[r] <= OFFSET) { // 이전 값에서 nums[r]을 뺌
                // if (dp[r-1][c+OFFSET+nums[r]] > 0) cout << r << ' ' << c << ' ' << dp[r-1][c+OFFSET+nums[r]] << '\n';
                dp[r][c+OFFSET] += dp[r-1][c+OFFSET+nums[r]]; 
            }
        }
    }

    // for (auto r : dp) {
    //     for (auto c : r) cout << c << ' ';
    //     cout << '\n';
    // }

    cout << dp[N-1][M+OFFSET];
    return 0;
}
