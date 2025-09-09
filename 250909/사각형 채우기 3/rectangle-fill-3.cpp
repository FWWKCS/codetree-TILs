#include <iostream>
#define MOD 1'000'000'007
using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    long long dp[1001] = {0, };
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= 1000; i++) {
        dp[i] = (((dp[i-1]*2) % MOD) + ((dp[i-2]*3) % MOD)) % MOD; 
        if (i > 2) dp[i] += (dp[i-3] * 2) % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n];
    return 0;
}
