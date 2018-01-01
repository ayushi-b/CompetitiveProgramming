#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;
    vector<string> num;
    for(int i = 0; i<n; ++i) {
        string s;
        cin >> s;
        num.push_back(s);
    }

    int c = 0;
    vector<int> ans;
    for(int dig = 49; dig >= 0; --dig) {
        int sum = c;
        for(int i = 0; i<n; ++i) {
            sum += num[i][dig] - '0';
        }

        ans.push_back(sum%10);
        c = sum/10;
    }

    while(c) {
        ans.push_back(c%10);
        c/=10;
    }

    int l = ans.size();
    for(int i = 0; i<10; ++i) {
        cout << ans[l - i - 1];
    }

    return 0;
}

