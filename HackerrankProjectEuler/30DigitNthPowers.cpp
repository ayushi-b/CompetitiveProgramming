#include <bits/stdc++.h>
using namespace std;

int main() {

    int ans = 0;
    int n;
    cin >> n;
    for(int i = 100; i<1000000; ++i) {
        int sum = 0, x = i;
        while(x) {
            sum += pow((x % 10), n);
            x /= 10;
        }
        if(sum == i) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}

