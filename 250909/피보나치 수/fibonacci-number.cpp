#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    int dp[45] = {0, };
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= 45; i++) dp[i] = dp[i-1] + dp[i-2];
    cout << dp[N];
    return 0; 
}
