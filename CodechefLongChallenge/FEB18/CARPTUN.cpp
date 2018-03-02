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


void solve(vector<double> arr, double c, ll n) {

    double wait = arr[0], extra = 0;
    rep(i, 1, n-1) {

        double diff = arr[i] - arr[i-1];

        if(diff >= 0) {

            if(extra > 0) {
                wait += max((double)0, diff - extra);
                extra = max((double)0, extra - diff);
            }
            else {
                wait += diff;
            }
        }
        else {
            extra += abs(diff);
        }
    }

    double ans = (c-1)*wait;
    printf("%.9lf\n", ans);

};


int main() {

    ios::sync_with_stdio(false);
    //freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        ll n;
        cin >> n;
        vector<double> arr(n);

        rep(i, 0, n-1) {
            cin >> arr[i];
        }

        double c, d, s;
        cin >> c >> d >> s;

        solve(arr, c, n);

    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}
