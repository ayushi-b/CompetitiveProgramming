//
// Created by Ayushi on 15/01/18.
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


vector<ll> maxSubArraySum(vector<ll> a, ll n) {

    ll max_so_far = LLONG_MIN, max_ending_here = 0,
            start =0, end = 0, s=0;

    rep(i, 0, n-1) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    //debug(max_so_far);

    vector<ll> ans = {max_so_far, start, end};
    return ans;
}


void solve(ll n, ll k) {

    vector<ll> arr(n), karr(3*n);

    ll sum = 0;

    rep(i, 0, n-1) {
        cin >> arr[i];
        karr[i] = karr[i+n] = karr[i+2*n] = arr[i];
        sum += arr[i];
    }

    //rep(i, 0, 3*n - 1) {
    //    cout << karr[i] << " ";
    //}
    //cout << endl;

    if(k < 3) {
        vector<ll> ans1 = maxSubArraySum(karr, k*n);
        cout << ans1[0] << endl;
        return;
    }

    vector<ll> ans = maxSubArraySum(karr, 3*n);

    //debug(ans[1]);
    //debug(ans[2]);
    if(ans[0] > 3*sum) {

        if(sum <= 0) {
            cout << ans[0] << endl;
        }
        else {
            cout << ans[0] + sum*(k-3) << endl;
        }
    }
    else {
        cout << k*sum << endl;
    }
};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        ll n, k;
        cin >> n >> k;
        solve(n, k);

    }

    //t1 = time(nullptr);
    //cout << "\n time : " << t1 - t0 << "s";

    return 0;
}
