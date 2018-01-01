#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        ll sumsq = (n * (n+1))/2;
        sumsq = sumsq*sumsq;
        ll sqsum = (n * (n+1) * (2*n + 1))/6;
        cout << sumsq - sqsum << endl;
    }

    return 0;
}