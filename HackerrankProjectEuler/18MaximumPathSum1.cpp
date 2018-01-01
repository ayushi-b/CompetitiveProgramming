#include <bits/stdc++.h>
using namespace std;

int grid[20][20], n;

int ans(int x, int y) {

    if(x >= n || y >= n) {
        return 0;
    }

    int sum;
    sum = grid[x][y] + max(ans(x+1, y), ans(x+1, y+1));
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<=i; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << ans(0, 0) << endl;
    }
    return 0;
}

