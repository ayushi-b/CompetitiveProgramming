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
#define MAX 1000005


void solve(int x, int y) {

    vector<vector<char>> cake(x, vector<char>(y));

    for(int i = 0; i<x; ++i) {
        for (int j = 0; j<y; ++j) {
            cin >> cake[i][j];
        }
    }

    int cost[2] = {3, 5}; // g2r, r2g
    int costs[2] = {0, 0};
    char color[2] = {'R', 'G'};


    //k = 0, even rows start with red (i.e. even cols = red)
    //k = 0, odd rows start with green (i.e. even cols = green)
    //k = 1, even rows start with green (i.e. even cols = green)
    //k = 1, odd rows start with red (i.e. even cols = red)
    for(int k = 0; k<2; ++k) {
        for (int l = 0; l < 2; ++l) {

            for (int r = l; r < x; r += 2) {
                for (int c = 0; c < y; ++c) {

                    // odd cols
                    if (c % 2) {
                        if (cake[r][c] != color[1-(k==l)]) {
                            costs[k] += cost[1-(k==l)];
                        }
                    }

                    // even cols
                    else {
                        if (cake[r][c] != color[(k==l)]) {
                            costs[k] += cost[(k==l)];
                        }
                    }

                }
            }

        }
    }

    cout << min(costs[0], costs[1]) << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    ll t;
    cin >> t;

    while(t--) {

        int x, y;
        cin >> x >> y;
        solve(x, y);

    }

    return 0;
}
