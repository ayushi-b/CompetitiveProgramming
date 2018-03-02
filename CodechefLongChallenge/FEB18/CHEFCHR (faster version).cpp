#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("fi.txt", "r", stdin);freopen("fo.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--!=0)
    {
        string a="chef";
        string b;
        cin>>b;
        long long len_a=a.length();
        long long len_b=b.length();
        vector<int> cnt_a(26,0);
        vector<int> cnt_b(26,0);
        //cout << "len_b = " << len_b << endl;


        for (int i = 0; i < len_a; i++) {
            cnt_a[a[i]-'a']++;
            cnt_b[b[i]-'a']++;
        }

        int ab=0;

        if(equal ( cnt_a.begin(), cnt_a.end(), cnt_b.begin() ))
        {
            ab++;
        }


        for (int i = 0; i < len_b-len_a; i++) {
            cnt_b[b[i]-'a']--;
            cnt_b[b[i+len_a]-'a']++;

            if(equal ( cnt_a.begin(), cnt_a.end(), cnt_b.begin() ))
            {
                ab++;
            }

            //cout << "c : " << cnt_b['c' - 'a'] << endl;
            //cout << "h : " << cnt_b['h' - 'a'] << endl;
            //cout << "e : " << cnt_b['e' - 'a'] << endl;
            //cout << "f : " << cnt_b['f' - 'a'] << endl << endl;

            //cout << i+len_a << " " << i << endl;
        }
        if(ab)
        {
            printf("lovely ");
            printf("%d",ab);
        }
        else
        {
            printf("normal");
        }
        printf("\n");

    }

    return 0;
}  