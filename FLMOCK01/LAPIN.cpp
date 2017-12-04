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


void solve(string s) {

    int l = s.size();
    int mid = (l+1)/2;

    map<char, int> rmap, lmap;

    for(int i = 0; i<mid; ++i) {
        rmap[s[i]]++;
        lmap[s[l-i-1]]++;
    }


    if(lmap == rmap) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }


};

int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {

        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}
