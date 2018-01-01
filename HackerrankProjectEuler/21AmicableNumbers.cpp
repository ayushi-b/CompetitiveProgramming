#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100005
//#define max 301

ll divsum(ll n) {
    ll s = sqrt(n);
    ll ans = 1;
    for(int i = 2; i<=s; ++i) {
        if(n % i == 0) {
            ans += i + n/i;
            if(i == n/i) {
                ans -= i;
            }
        }
    }
    return ans;
}

int main() {

    ll sum[max], amm[max];

    for(int i = 1; i<max; ++i) {
        sum[i] = divsum(i);
    }

    amm[1] = sum[1] = 0;
    for(int i = 2; i<max; ++i) {
        amm[i] = amm[i-1];
        if(sum[i] < max && i == sum[sum[i]] && sum[i] != i) {
            amm[i] += i;
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << amm[n] << endl;
    }


    return 0;
}

