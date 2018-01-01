#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }

    return gcd(b, a%b);
}

int lcm(int a, int b) {
    if(a>b) {
        return a*b/gcd(a,b);
    }
    else{
        return a*b/gcd(b,a);
    }
}

int main() {

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans = lcm(ans,i);
        }
        cout << ans << endl;
    }

    return 0;
}

