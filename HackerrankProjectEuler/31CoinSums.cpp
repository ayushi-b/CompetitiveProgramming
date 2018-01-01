#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int value(int i) {
    switch(i) {
        case 0 : return 1;
            break;
        case 1 : return 2;
            break;
        case 2 : return 5;
            break;
        case 3 : return 10;
            break;
        case 4 : return 20;
            break;
        case 5 : return 50;
            break;
        case 6 : return 100;
            break;
        case 7 : return 200;
            break;
    }
    return 0;
}

int main() {

    vector< vector<long long int> > arr(8, vector<long long int> (100005, 1));

    for(int i = 1; i<8; ++i) {
        for(int j = 2; j<100005; ++j) {
            if(value(i) <= j) {
                arr[i][j] = ( (arr[i-1][j] % MOD) + (arr[i][j-value(i)] % MOD) ) % MOD;
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << arr[7][n] << endl;
    }

    return 0;
}

