// #include <iostream>
// #include <vector>
// using namespace std;

// int n;
// int arr[100+1];
// vector<vector<int>> dp;

// int main() {
//     cin >> n;
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         cin >> arr[i];
//         sum += arr[i];
//     }

//     // Please write your code here.
//     dp.resize(n+1, vector<int>(sum+1, -1));
//     dp[0][0] = 0;
    
//     int answer = 0;
//     // r번째 원소까지 볼 때
//     // |A-B| = c 일 때의 "그룹 A"가 가질 수 있는 최대값
//     for (int r = 1; r <= n; r++) {
//         int cur = arr[r];
//         cout << cur << '\n';
//         for (int c = sum; c > -1; c--) {
//             // A에 추가해 차를 늘림
//             if (c-cur > -1) {
//                 if (dp[r-1][c-cur] > -1) {
//                     dp[r][c] = max(dp[r][c], dp[r-1][c-cur] + cur);
//                 }
//             } 
//             else {
//                 if (dp[r-1][cur-c] > -1) {
//                     dp[r][c] = max(arr[r], dp[r-1][cur-c]);
//                 }
//             }

//             // B에 추가해 차를 줄임
//             if (c+cur <= sum && dp[r-1][c+cur] > -1) dp[r][c] = max(dp[r][c], dp[r-1][c+cur]);

//             // C에 추가해 차의 변화 없음
//             dp[r][c] = max(dp[r][c], dp[r-1][c]);
//         }
//     }

//     for (auto r : dp) {
//         for (auto c : r) cout << c << ' ';
//         cout << '\n';
//     }
//     // cout << answer;
//     // 
//     return 0;
// }
