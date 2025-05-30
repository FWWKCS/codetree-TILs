#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> seq;
set<int> s;

void recursion() {
    if (seq.size() == n) {
        for (auto x : seq) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (s.find(i) == s.end()) {
            seq.push_back(i);
            s.insert(i);
            recursion();
            seq.pop_back();
            s.erase(i);
        }
    }
} 

int main() {
    cin >> n;
    // Please write your code here.
    recursion();
    return 0;
}
