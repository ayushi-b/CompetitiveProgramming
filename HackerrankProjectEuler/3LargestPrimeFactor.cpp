#include <bits/stdc++.h>
#define ll long long
#define MAX1 1000001
#define MAX2 1000000000001
using namespace std;

vector<int> prime(MAX1,1);

void sieve() {
    for(ll i = 2; i<1000; ++i) {
        if(prime[i]) {
            for(ll j = 2*i; j < MAX1; j += i) {
                prime[j] = 0;
            }
        }
    }
}

ll maxfactor(ll n) {
    ll ans = 1;
    for(ll i = 2; i < MAX1 && n > 1; ++i) {
        if(prime[i]) {
            while(n%i == 0) {
                ans = max(ans, i);
                n /= i;
            }
        }
    }
    if(n>1) {
        ans = max(ans, n);
    }
    return ans;
}

int main() {
    prime[1] = 0;
    sieve();
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << maxfactor(n) << endl;
    }


    return 0;
}

