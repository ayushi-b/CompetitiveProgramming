#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll power(ll a, ll b) {
    if(b == 0) {
        return 1;
    }

    ll ans = power(a, b/2) % mod;
    ans *= ans;
    ans %= mod;

    if(b & 1) {
        ans = (a % mod) * (ans) % mod;
    }

    return ans;
}


int main() {

    ll fact[2000005];
    fact[0] = 1;
    for(ll i = 1; i<2000005; ++i) {
        fact[i] = fact[i-1]*i % mod;
    }

    ll t;
    cin >> t;
    while(t--) {
        ll m, n;
        cin >> m >> n;

        ll ans = fact[m+n] % mod;
        ll ans1 = fact[m] % mod;
        ll ans2 = fact[n] % mod;
        ans1 = power(ans1, mod-2) % mod;
        ans2 = power(ans2, mod-2) % mod;
        ans *= ans1;
        ans %= mod;
        ans *= ans2;
        ans %= mod;

        cout << ans << endl;

    }

    return 0;
}

