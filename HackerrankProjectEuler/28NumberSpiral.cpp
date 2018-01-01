#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll a, ll b) {

    if(b == 0) {
        return 1;
    }

    ll res = power(a, b/2) % mod;
    res = (res * res) % mod;
    if(b & 1) {
        res = (res * a) % mod;
    }

    return res % mod;

}

int main() {

    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;

        ll n = (N + 1) / 2;
        n %= mod;

        ll t1 = (((n * n) % mod) * n) % mod;
        t1 = (t1 * 8) % mod;
        ll t2 = (n * n) % mod;
        t2 = (t2 * 9) % mod;
        ll t3 = (7 * n) % mod;

        ll ans = (t1 - t2 + mod + t3) % mod;
        ans = (ans * 2) % mod;
        ans = ((ans % mod) * (power(3, mod-2) % mod)) % mod;
        ans -= 3;
        cout << ans << endl;
    }

    return 0;
}

