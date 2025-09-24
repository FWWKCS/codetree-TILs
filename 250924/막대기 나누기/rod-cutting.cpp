#include <iostream>
#include <vector>
using namespace std;

int n;
int profit[101];
vector<int> dp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    // Please write your code here.
    dp.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j]+profit[i-j]);
        }
    }

    cout << dp[n];
    return 0;
}
