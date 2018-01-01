#include <bits/stdc++.h>
#define ll long long
#define MAX 90
using namespace std;

map<ll, ll> memo;

void compute() {
    ll i;
    for(i = 3; i < MAX; ++i) {
        memo[i] = memo[i-1] + memo[i-2];
    }
}

ll ans(ll n) {
    ll res = 0;
    for (int i = 1; memo[i] <= n; ++i) {
        if(memo[i] % 2 == 0) {
            res += memo[i];
        }
    }
    return res;
}

int main() {

    memo[1] = 1;
    memo[2] = 2;
    compute();

    ll n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ans(n) << endl;
    }

    return 0;
}

