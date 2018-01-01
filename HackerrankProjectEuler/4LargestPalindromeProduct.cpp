#include <bits/stdc++.h>
using namespace std;

bool palin(int x) {
    int arr[10], i = 0;
    int l, r = x;
    while(r) {
        l = r%10;
        r = r/10;
        arr[i++] = l;
    }

    for(int j = 0; j <= i/2; ++j) {
        if(arr[j] != arr[i-j-1]) {
            return false;
        }
    }
    return true;
}

int main() {

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = n-1; i>10000; --i) {
            int flag = 0;
            if(palin(i)) {
                for(int j = 357; j <= 999; ++j) {
                    if(i%j == 0 && i/j < 1000) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

