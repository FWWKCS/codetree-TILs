#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seq[i] = x;
    }

    int answer = 1;
    vector<int> upper(N, 1), lower(N, 1);
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (seq[j] > seq[i]) upper[j] = max(upper[j], upper[i]+1);
            answer = max(answer, upper[j]);
        }
    }

    for (int i = 0; i < N-1; i++) {
        for (int k = i+1; k < N; k++) {
            if (seq[k] < seq[i]) lower[k] = max(max(upper[k], lower[k]), max(upper[i]+1, lower[i]+1));
            else lower[k] = max(upper[k], lower[k]);
            answer = max(answer, lower[k]);
        }
    }

    // for (auto x : upper) cout << x << ' ';
    // cout << '\n';
    // for (auto x : lower) cout << x << ' ';
    // cout << '\n';
    cout << answer;
    return 0;
}