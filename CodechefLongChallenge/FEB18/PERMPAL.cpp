//
// Created by Ayushi Bansal on 04/02/18.
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


void solve(string s) {

    int l = s.size();

    map<char, int> mp;
    map<char, vector<int> > pos;
    vector<string> enc;

    rep(i, 0, l-1) {
        mp[s[i]]++;
        pos[s[i]].pb(i+1);
    }

    int odd = 0, x = 0, k;
    vector<int> perm(l);
    for(auto &ele: mp) {
        if(ele.second % 2) {
            odd++;

            if(odd > 1) {
                cout << "-1" << endl;
                return;
            }

            perm[l/2] = pos[ele.first][0];

            k = ele.second/2;
            rep(j, 0, k-1) {
                perm[x+j] = pos[ele.first][j+1];
                perm[l-(x+j)-1] = pos[ele.first][ele.second-j-1];
            }
        }
        else {
            k = ele.second/2;
            rep(j, 0, k-1) {
                perm[x+j] = pos[ele.first][j];
                perm[l-(x+j)-1] = pos[ele.first][ele.second-j-1];
            }
        }
        x += k;
    }

    rep(i, 0, l-1) {
        cout << perm[i] << " ";
    }
    cout << endl;

};


int main() {

    ios::sync_with_stdio(false);
    //freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    //time_t t0, t1;
    //t0 = time(nullptr);

    ll t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        solve(s);
    }

    //t1 = time(nullptr);
    //cout << "\ntime : " << t1 - t0 << "s";

    return 0;
}