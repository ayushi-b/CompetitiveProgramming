//
// Created by Ayushi on 06/12/17.
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

int grid[101][101][101];
int x, y, z, a, b, c;

map<string, bool> memo;

void fill_grid(int i, int j, int k) {

    string str;
    str = to_string(i) + "," + to_string(j) + "," + to_string(k) + "," + to_string(grid[i][j][k]);

    if(memo[str]) {
        return;
    }
    else {
        memo[str] = true;
    }

    if(i + 1 <= x) {

        if(j + 1 <= y) {

            if(k + 1 <= z) {
                grid[i+1][j+1][k+1] = min(grid[i+1][j+1][k+1], grid[i][j][k] + c);

                grid[i+1][j+1][k] = min(grid[i+1][j+1][k], grid[i][j][k] + b);
                grid[i+1][j][k+1] = min(grid[i+1][j][k+1], grid[i][j][k] + b);
                grid[i][j+1][k+1] = min(grid[i][j+1][k+1], grid[i][j][k] + b);

                grid[i+1][j][k] = min(grid[i+1][j][k], grid[i][j][k] + a);
                grid[i][j+1][k] = min(grid[i][j+1][k], grid[i][j][k] + a);
                grid[i][j][k+1] = min(grid[i][j][k+1], grid[i][j][k] + a);

                fill_grid(i+1, j+1, k+1);

                fill_grid(i+1, j+1, k);
                fill_grid(i, j+1, k+1);
                fill_grid(i+1, j, k+1);

                fill_grid(i+1, j, k);
                fill_grid(i, j+1, k);
                fill_grid(i, j, k+1);

            }
            else {

                grid[i+1][j+1][k] = min(grid[i+1][j+1][k], grid[i][j][k] + b);

                grid[i+1][j][k] = min(grid[i+1][j][k], grid[i][j][k] + a);
                grid[i][j+1][k] = min(grid[i][j+1][k], grid[i][j][k] + a);


                fill_grid(i+1, j+1, k);

                fill_grid(i+1, j, k);
                fill_grid(i, j+1, k);

            }
        }
        else{
            if(k + 1 <= z) {

                grid[i+1][j][k+1] = min(grid[i+1][j][k+1], grid[i][j][k] + b);

                grid[i+1][j][k] = min(grid[i+1][j][k], grid[i][j][k] + a);
                grid[i][j][k+1] = min(grid[i][j][k+1], grid[i][j][k] + a);


                fill_grid(i+1, j, k+1);

                fill_grid(i+1, j, k);
                fill_grid(i, j, k+1);

            }
            else {
                grid[i+1][j][k] = min(grid[i+1][j][k], grid[i][j][k] + a);


                fill_grid(i+1, j, k);

            }
        }
    }
    else {

        if(j + 1 <= y) {

            if(k + 1 <= z) {

                grid[i][j+1][k+1] = min(grid[i][j+1][k+1], grid[i][j][k] + b);

                grid[i][j+1][k] = min(grid[i][j+1][k], grid[i][j][k] + a);
                grid[i][j][k+1] = min(grid[i][j][k+1], grid[i][j][k] + a);


                fill_grid(i, j+1, k+1);

                fill_grid(i, j+1, k);
                fill_grid(i, j, k+1);

            }
            else {
                grid[i][j+1][k] = min(grid[i][j+1][k], grid[i][j][k] + a);


                fill_grid(i, j+1, k);

            }
        }
        else{
            if(k + 1 <= z) {
                grid[i][j][k+1] = min(grid[i][j][k+1], grid[i][j][k] + a);


                fill_grid(i, j, k+1);
            }
            else {
                return;
            }
        }

    }


}


void solve() {

    // initialize grid
    for(int i = 0; i<=x; ++i)
        for(int j = 0; j<=y; ++j)
            for(int k = 0; k<=z; ++k)
                grid[i][j][k] = INT_MAX;

    grid[0][0][0] = 0;
    memo.clear();
    fill_grid(0, 0 , 0);

    cout << grid[x][y][z] << endl;

};


int main() {

    ios::sync_with_stdio(false);
    freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    time_t t0, t1;
    t0 = time(0);

    ll t;
    cin >> t;

    while(t--) {

        cin >> x >> y >> z >> a >> b >> c;
        solve();
    }

    t1 = time(0);
    cout << t1 - t0 << endl;

    return 0;
}
