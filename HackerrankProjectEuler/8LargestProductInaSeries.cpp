#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        char num[1005];
        int k, n;
        cin >> n >> k;
        cin >> num;
        int p = 1;
        for(int i = 0; i<k; ++i) {
            p *= (num[i] - 48 );
        }
        //cout << "p=" << p << endl;
        int save = p;
        int temp = 1;
        for(int i = k; i<=n; ++i) {
            if(num[i-k] != '0')
                temp = p / (num[i-k] - 48);
            else {
                temp = 1;
                for(int j = i-k+1; j<i; ++j) {
                    temp *= (num[j] - 48 );
                }
            }
            temp *= (num[i] - 48);
            if(temp > save) {
                save = temp;
            }
            p = temp;
        }
        cout << save << endl;
    }
    return 0;
}

