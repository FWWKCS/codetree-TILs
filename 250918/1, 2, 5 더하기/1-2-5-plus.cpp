#include <iostream>
#include <vector>
#define MOD 10'007
using namespace std;

int n;
vector<int>dp;

int main() {
    cin >> n;
    dp.resize(n+1, 0);
    // Please write your code here.
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i-1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
        if (i-2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
        if (i-5 >= 0) dp[i] = (dp[i] + dp[i-5]) % MOD;
    }

    cout << dp[n];
    return 0;
}
