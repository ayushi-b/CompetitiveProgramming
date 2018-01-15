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
#define debug(a)   cout<<a<<endl
#define maxi(a,b,c)  max(a,max(b,c))
#define mini(a,b,c)  min(a,min(b,c))
#define mp make_pair
#define mod 1000000007
#define MAX 1000005



int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(0);

    ll t;
    cin >> t;

    while(t--) {

        int arr[4];
        map<int, int> mp;

        rep(i, 0, 3) {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        bool flag = true;
        int count = 0;
        for(auto &ele: mp) {
            count++;
            if(ele.second != 2 && ele.second != 4) {
                flag = false;
            }
        }

        if(count > 2 ) {
            flag = false;
        }

        if(flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }

    //t1 = time(0);
    //cout << t1 - t0 << endl;

    return 0;
}
