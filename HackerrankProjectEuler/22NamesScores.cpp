#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int m = n;
    vector<string> names;
    while(m--) {
        string s;
        cin >> s;
        names.push_back(s);
    }
    map<string, int> rank;
    sort(names.begin(), names.end());
    for(int i = 0; i<n; ++i) {
        rank[names[i]] = i+1;
    }

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i<s.size(); ++i) {
            ans += s[i] - 64;
        }
        ans *= rank[s];
        cout << ans << endl;
    }

    return 0;
}

