#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100000];
vector<int> dp;
int main() {
    cin >> n;
    dp.resize(n, -1e9);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
    }

    cout << dp[n-1];
    return 0;
}
