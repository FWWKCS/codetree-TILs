#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100];
vector<vector<int>> dp;

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // Please write your code here.
    dp.resize(n, vector<int>(sum+1, 0));
    dp[0][arr[0]] = 1;
    
    for (int i = 0; i < n-1; i++) {
        for (int k = sum; k > -1; k--) {
            if (dp[i][k] == 1) {
                dp[i+1][k+arr[i+1]] = 1;
                dp[i+1][abs(k-arr[i+1])] = 1;
            }
        }
    }

    int answer = sum;
    // for (int r = 0; r < n; r++) {
    //     for (int c = 0; c <= sum; c++) cout << dp[r][c] << ' ';
    //     cout << '\n';
    // }
    for (int i = 0; i <= sum; i++) {
        if (dp[n-1][i] == 1) {
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}

