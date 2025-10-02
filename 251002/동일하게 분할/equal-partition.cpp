#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[101];
vector<vector<int>> dp;

int sum = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // Please write your code here.
    // A-B = diff index
    const int OFFSET = sum;
    dp.resize(n+1, vector<int>(sum*2+1, 0));
    dp[0][OFFSET] = 1;
    for (int r = 1; r <= n; r++) {
        for (int c = -sum; c <= sum; c++) {
            // A에 추가
            if (c+OFFSET-arr[r] > -1 && dp[r-1][c+OFFSET-arr[r]] == 1) dp[r][c+OFFSET] = 1;

            // B에 추가
            if (c+OFFSET+arr[r] <= sum+OFFSET && dp[r-1][c+OFFSET+arr[r]] == 1) dp[r][c+OFFSET] = 1;  
        }
    }

    // for (auto r : dp) {
    //     for (auto c : r) cout << c << ' ';
    //     cout << '\n';
    // }
    
    cout << (dp[n][OFFSET] == 1 ? "Yes" : "No");
    return 0;
}
