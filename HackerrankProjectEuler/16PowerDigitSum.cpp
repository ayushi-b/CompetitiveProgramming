#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000+5

vector<ll> result(MAX, 0);

int main() {

    vector<int> s, temp;
    s.push_back(2);
    ll c = 0;
    for(ll i = 2; i <= MAX; ++i) {
        ll l = s.size(), res = 0, c = 0;
        for(int j = 0; j<l; ++j) {
            int sum = c + 2 * s[j];
            c = sum / 10;
            res += sum % 10;
            temp.push_back(sum % 10);
        }
        while(c) {
            res += c % 10;
            temp.push_back(c % 10);
            c /= 10;
        }
        result[i] = res;
        s = temp;
        temp.clear();
    }

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << result[n] << endl;
    }

    return 0;
}

