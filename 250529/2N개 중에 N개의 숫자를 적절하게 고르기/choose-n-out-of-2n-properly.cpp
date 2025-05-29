#include <iostream>

using namespace std;

int n;
int num[20];

int S = 0;
int answer = 1e9;

void search(int total, int last, int depth) {
    if (depth == n) {
        answer = min(answer, abs((S-total)-total));
        return;
    }

    for (int i = last+1; i < n*2; i++) {
        search(total+num[i], i, depth+1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        S += num[i];
    }

    // Please write your code here.
    search(0, -1, 0);
    cout << answer;
    return 0;
}
