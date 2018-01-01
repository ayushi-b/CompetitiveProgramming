#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    int grid[20][20], n = 20;
    for(int i = 0; i<20; ++i) {
        for(int j = 0; j<20; ++j) {
            cin >> grid[i][j];
        }
    }

    int dr[] = {-1, 0, 1, 1}, dc[] = {0, 1, 1, -1};
    ll mx = -1;

    for(int i = 0; i<20; ++i) {
        for(int j = 0; j<20; ++j) {
            for(int d = 0; d<4; ++d) {
                ll ans = 1;
                for(int n = 0; n<4; ++n) {
                    int ii = i + n*dr[d];
                    int jj = j + n*dc[d];

                    if(ii < 0 || ii > 19 || jj < 0 || jj > 19) {
                        ans = 0;
                        break;
                    }
                    else {
                        ans *= grid[ii][jj];
                    }
                }
                mx = max(ans, mx);
            }
        }
    }