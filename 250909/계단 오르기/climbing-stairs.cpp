#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int dp[1001] = {0,};
    dp[2] = dp[3] = 1;
    for (int i = 4; i <= 1000; i++) {
        dp[i] = (dp[i-2] + dp[i-3]) % 10'007;
    }

    cout << dp[n];
    return 0;
}