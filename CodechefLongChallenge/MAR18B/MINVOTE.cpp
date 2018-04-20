//
// Created by Ayushi Bansal on 03/03/18.
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


void solve(vui minions, ui n) {

    ll temp;
    vui votes(n, 0);

    rep(i, 0, n-1) {

        //cout << "i = " << i << " min[i] = " << minions[i] << endl;
        if(i-1 >= 0) {
            votes[i-1]++;
            //cout << "added at i-1 = " << i-1 << endl;
        }
        if(i+1 < n) {
            votes[i+1]++;
            //cout << "added at i+1 = " << i+1 << endl;
        }

        temp = 0;

        //cout << "starting reverse loop from " << i-2 << " to " << 0 << endl;

        rrep(j, 0, i-2) {
            temp += minions[j+1];
            //cout << "sum = " << temp << endl;

            if(temp > minions[i]) {
                break;
            }

            if(temp <= minions[i]) {
                //cout << "added at " << j << endl;
                votes[j]++;
            }
        }

        temp = 0;
        //cout << "starting forward loop from " << i+2 << " to " << n-1 << endl;
        rep(j, i+2, n-1) {

            temp += minions[j-1];

            //cout << "sum = " << temp << endl;
            if(temp > minions[i]) {
                break;
            }

            if(temp <= minions[i]) {
                //cout << "added at " << j << endl;
                votes[j]++;
            }
        }
        //cout << endl;
    }

    rep(i, 0, n-1) {
        cout << votes[i] << " ";
    }
    cout << endl;

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

        ui n;
        cin >> n;
        //n = 30;

        vui minions(n);
        //vui minions(n, 1);
        //minions[n-1] = 1000000000;
        //vll sum(n, 0);
        //ll last = 0;
        rep(i, 0, n-1) {
            cin >> minions[i];
            //sum[i] = last + minions[i];
            //last = sum[i];
            //cout << sum[i] << " ";
        }

        //rep(k, 0, 1)
        //solve(minions, sum, n);
        solve(minions, n);

    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}

