#include<bits/stdc++.h>
using namespace std;
    
int frac(int n, int d, int r) {
    
    int N = n*10;
    int x;
    
    while(r--) {
        
        if(N < d) {
            x = N;
            N = N*10;
        }
        else {
            x = N/d;
            N = (N%d)*10;
        }
    }
    
    return x;
    
}


int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n, d, r;
        cin >> n >> d >> r;
        int ans = frac(n, d, r);
        if(ans > 9) {
            ans = ans % 10;
        }
        cout << ans << endl;
    }
    
    return 0;
}