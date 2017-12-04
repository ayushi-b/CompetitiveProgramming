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


void solve(string str, ll l) {

    ll count = 0;
    rep(i, 0, l-1) {
        if(str[i] == '1') {
            count++;
        }
    }


    ll ans = (count*(count + 1))/2;
    cout << ans << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {
        ll l;
        cin >> l;
        string s;
        cin >> s;
        solve(s, l);
    }

    return 0;
}
