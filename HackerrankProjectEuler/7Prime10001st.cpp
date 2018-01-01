#include <bits/stdc++.h>
#define ll long long
#define MAX1 1322500
#define MAX2 1150
using namespace std;

vector<int> prime(MAX1, 1), lst;

void sieve() {
    for (int i = 2; i<MAX2; ++i) {
        if(prime[i]) {
            for(int j = 2*i; j<MAX1; j+=i) {
                prime[j] = 0;
            }
        }
    }

    for(int i = 2; i<MAX1; ++i) {
        if(prime[i]) {
            lst.push_back(i);
        }
    }

}

int main() {
    sieve();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << lst[n-1] << endl;
    }

    return 0;
}

