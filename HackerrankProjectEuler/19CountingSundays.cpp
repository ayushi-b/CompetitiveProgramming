#include <iostream>
using namespace std;

int mnth[13] = {0, 13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};


long long int get_d(long long int m,  long long int y) {

    if(m == 1 || m == 2) {
        y--;
    }

    long long int h = (1 + (13*(mnth[m] + 1))/5 + y + y/4 - y/100 + y/400) % 7;


    return h;
}


int main() {

    //ios::sync_with_stdio(false);
    //freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    long long int t;
    cin >> t;
    while(t--) {

        long long int y1, y2, m1, m2, d1, d2;
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;

        long long int ans = 0;
        long long int mstart = m1, mend = 12;

        if(d1 > 1) {
            mstart++;
        }

        if(y1 == y2) {
            mend = m2;
        }

        for(long long int m = mstart; m <= mend; ++m) {
            if(get_d(m, y1) == 1) {
                ans++;
            }
        }

        for(long long int y = y1+1; y<y2; ++y) {
            for(long long int m = 1; m<13; ++m) {
                if(get_d(m, y) == 1) {
                    ans++;
                }
            }
        }

        if(y1 != y2)
            for(long long int m = 1; m <= m2; ++m) {
                if(get_d(m, y2) == 1) {
                    ans++;
                }
            }

        cout << ans << endl;

    }


    return 0;
}

