//
// Created by Ayushi on 06/01/18.
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
#define debug(a) cout<<(a)<<endl
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define mp make_pair
#define mod 1000000007
#define MAX 1000005


void solve(vector< vector<int> > sq, int n) {

    ll ans = sq[n-1][n-1], last = ans;
    bool found;

    //cout << ans << endl;

    rrep(i, 0, n-2) {
        found = false;
        rrep(j, 0, n-1) {
            if(sq[i][j] < last) {
                last = sq[i][j];
                ans += last;
                //cout << ans << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans << endl;
};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        unsigned int n;
        cin >> n;

        vector< vector<int> > sq(n, vector<int>(n));

        rep(i, 0, n-1) {
            rep(j, 0, n-1) {
                cin >> sq[i][j];
            }
            sort(sq[i].begin(), sq[i].end());
        }

        solve(sq, n);

    }

    //t1 = time(nullptr);
    //cout << "\n time : " << t1 - t0 << "s";

    return 0;
}
