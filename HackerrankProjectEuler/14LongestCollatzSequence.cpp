#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 5000005

vector<ll> memo(MAX, 0);
int result[MAX];

ll ans(ll n) {

    if(n<=MAX && memo[n]) {
        return memo[n];
    }

    ll c = 1;
    if(n & 1) {
        c += ans(3*n + 1);
    }
    else {
        c += ans(n/2);
    }
    if(n<=MAX)
        memo[n] = c;
    return c;
}

int main() {

    memo[1] = 1;
    ll res = 1;
    for(ll i = 1; i<MAX; ++i) {
        if(ans(i) >= ans(res)) {
            res = i;
        }
        result[i] = res;
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

