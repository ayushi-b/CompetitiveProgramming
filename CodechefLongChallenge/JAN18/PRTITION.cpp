//
// Created by Ayushi on 14/01/18.
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

vector<int> a;

bool subsetsum(vector<ll> arr, ll n, vector<ll> s) {

    ll last0, last1;

    rrep(i, 0, n) {

        if(s[0] >= arr[i]) {
            a[i] = 0;
            s[0] -= arr[i];
            last0 = i;
        }
        else if(s[1] >= arr[i]) {
            a[i] = 1;
            s[1] -= arr[i];
        }
        else {
            last1 = last0 - 1;
            s[0] += arr[last0] - arr[last1];
            s[1] += arr[last1] - arr[last0];
            a[last0] = 1 - a[last0];
            a[last1] = 1- a[last1];
            i++;
        }
    }

    return (s[0] == 0 && s[1] == 0);

}



void partition(ll x, ll n, ll sum) {

    vector<ll> arr(n-1), pos(n-1, 0);

    int k = 0, r = 0;
    while(k < x-1) {
        r++;
        arr[k++] = r;
    }
    r++;
    while(k < n-1) {
        r++;
        arr[k++] = r;
    }

    a.resize(n-1, -1);
    vector<ll> s = {sum, sum};

    bool res = subsetsum(arr, n-2, s);

    if(!res) {
        cout << "impossible\n";
    }
    else {

        rep(i, 1, x-1) {
            cout << a[i-1];
        }

        cout << "2";

        rep(i, x, n-1) {
            cout << a[i-1];
        }

        cout << endl;
    }

}


void solve(ll x, ll n) {

    if(n < 4) {
        cout << "impossible\n";
        return;
    }

    ll sum;
    if(n % 2 == 0) {
        ll r = n/2;
        sum = r * (n + 1);
    }
    else {
        ll r = (n+1)/2;
        sum = r * n;
    }

    sum -= x;

    if(sum % 2) {
        cout << "impossible\n";
        return;
    }

    partition(x, n, sum/2);
};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        ll n, x;
        cin >> x >> n;

        solve(x, n);
    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}
