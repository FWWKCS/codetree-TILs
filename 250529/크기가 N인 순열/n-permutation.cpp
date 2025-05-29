#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> v;
set<int> s;

void pm() {
    if (s.size() == n) {
        for (auto x : v) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            v.push_back(i);
            s.insert(i);
            pm();
            v.pop_back();
            s.erase(i);
        }
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    pm();
    return 0;
}
