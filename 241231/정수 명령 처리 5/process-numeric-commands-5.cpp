#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> stack;
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        if (s == "push_back") {
            int x; cin >> x;
            stack.push_back(x);
        }
        if (s == "pop_back") {
            stack.pop_back();
        }
        if (s == "size") {
            cout << stack.size() << '\n';
        }
        if (s == "get") {
            int k; cin >> k;
            cout << stack[k-1] << '\n';
        }
    }
    return 0;
}