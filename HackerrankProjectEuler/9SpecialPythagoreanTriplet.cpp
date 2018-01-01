#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a, b, c, ans = -1;
        int x = (n+1)/2;
        for(a = n/3; a < x; ++a) {
            for(int b = x-a; b < a; ++b) {

                c = n - a - b;
                if(c > b) {
                    continue;
                }
                if(a+b > c && b+c > a && a+c > b) {
                    ll asq = a*a;
                    ll bsq = b*b;
                    ll csq = c*c;
                    if(asq == bsq + csq) {
                        ans = max(ans, a*b*c);
                    }
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}

