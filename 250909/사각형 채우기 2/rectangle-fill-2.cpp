#include <iostream>
#define MOD 10'007
using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int dp[1001] = {0, };
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[i] = ((dp[i-2] * 2 % MOD) + dp[i-1]) % MOD;
    }
    cout << dp[n];
    return 0;
}
