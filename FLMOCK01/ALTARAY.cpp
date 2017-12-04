//
// Created by Ayushi on 26/11/17.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=n;++i)
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--i)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 100005


void solve(ll n) {

    vi arr(n), ans(n, 0);
    for(ll i = 0; i<n; ++i) {
        cin >> arr[i];
    }

    ans[n-1] = 1;
    int sign = -1;
    if(arr[n-1] > 0) {
        sign = 1;
    }

    for(ll i = n-2; i>=0; --i) {

        if(arr[i] > 0) {
            if(sign == -1) {
                ans[i] = ans[i+1] + 1;
            }
            else {
                ans[i] = 1;
            }
            sign = 1;
        }
        else {
            if(sign == 1) {
                ans[i] = ans[i+1] + 1;
            }
            else {
                ans[i] = 1;
            }
            sign = -1;
        }

    }

    for(ll i = 0; i<n; ++i) {
        cout << ans[i] << " ";
    }

    cout << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        solve(n);
    }

    return 0;
}
