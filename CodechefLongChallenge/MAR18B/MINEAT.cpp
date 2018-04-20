//
// Created by Ayushi Bansal on 02/03/18.
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
#define ui unsigned int
#define vui vector<ui>
#define repui(i,j,n) for(ui (i)=(j);(i)<=(n);++(i))

vi arr;
ui n, h;

bool fn(int x) {

    ui hrs = 0;
    rep(i, 0, n-1) {
        hrs += ceil((double)arr[i]/(double)x);
    }

    if(hrs > h) {
        return false;
    }

    return true;
}


void solve(int sum, int lim) {

    auto start = (int) ceil((double)sum/(double)h);
    int end = lim, mid = lim, res;

    while(start <= end) {

        mid = (start+end)/2;

        if(mid == start && mid == end) {
            break;
        }

        res = fn(mid);

        if(res) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    if(fn(mid)) {
        cout << mid << endl;
    }
    else {
        cout << mid+1 << endl;
    }


};

int main()
{
    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {

        cin >> n >> h;

        arr.resize(n);
        int lim = 0, sum = 0;
        rep(i, 0, n-1) {
            cin >> arr[i];
            sum += arr[i];
            lim = max(lim, arr[i]);
        }

        solve(sum, lim);

    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}

