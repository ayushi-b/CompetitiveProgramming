//
// Created by Ayushi on 04/02/18.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--(i))
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define debug(a)   cout<<(a)<<endl
#define maxi(a,b,c)  max(a,max(b,c))
#define mini(a,b,c)  min(a,min(b,c))
#define mp make_pair
#define mod 1000000007
#define MAX 1000005


void solve(int n, int m, int x, int k, string s) {

    int even_workers = 0 , odd_workers = 0;

    rep(i, 0, k-1) {
        if(s[i] == 'E') {
            even_workers++;
        }
        else {
            odd_workers++;
        }
    }

    int odd_months = (m+1)/2, even_months = m/2;

    int patents_left = n;
    patents_left -= min(odd_workers, odd_months*x);
    patents_left -= min(even_workers, even_months*x);

    if(patents_left > 0) {
        cout << "no" << endl;
    }
    else {
        cout << "yes" << endl;
    }

};


int main() {

    ios::sync_with_stdio(false);
    //freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        int n, m, x, k;
        cin >> n >> m >> x >> k;
        string s;
        cin >> s;
        if(k < n || m*x < n) {
            cout << "no" << endl;
            continue;
        }
        solve(n, m, x, k, s);

    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}