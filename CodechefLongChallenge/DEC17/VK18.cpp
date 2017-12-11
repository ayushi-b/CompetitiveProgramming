//
// Created by Ayushi on 02/12/17.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,j,n) for(ll (i)=(j);(i)<=(n);++(i))
#define rrep(i,j,n) for(ll i = n ; (i)>=(j) ;--(i))
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 1000000

ll ans[MAX+1];
ll memo[2*MAX+1];
ll sum[2*MAX+1];


void solve() {

    int lim = 2*MAX;
    sum[0] = sum[1] = 0;
    for(int i = 2; i<lim; ++i) {

        vector<int> digArray;

        int a = i;
        while(a) {
            digArray.pb(a%10);
            a /= 10;
        }

        int l;
        l = (int) (digArray.size());

        int even = 0, odd = 0;
        for(int j = 0; j<l; ++j) {
            if(digArray[j]%2) {
                odd += digArray[j];
            }
            else {
                even += digArray[j];
            }
        }

        memo[i] = abs(even - odd);
        sum[i] = sum[i-1] + memo[i];
    }

    ans[0] = 0;
    for(int i = 1; i<MAX+1; ++i) {
        ans[i] = ans[i-1];

        ans[i] += 2*(sum[2*i] - sum[i]);
        ans[i] -= memo[2*i];

    }

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    solve();

    ll t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;
        cout << ans[n] << endl;

    }

    return 0;
}
