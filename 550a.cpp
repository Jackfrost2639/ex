#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

string s;
bool dp[100005][2];

int main() {
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(i-1 >= 0 && s[i] == 'B' && s[i-1] == 'A')
        {
            if(i-2 >= 0 && dp[i-2][1])
            {
                cout << "YES" << endl;
                return 0;
            }
            else
            {
                dp[i][0] = true;
            }
        }
        if(i-1 >= 0 && s[i] == 'A' && s[i-1] == 'B')
        {
            if(i-2 >= 0 && dp[i-2][0])
            {
                cout << "YES" << endl;
                return 0;
            }
            else
            {
                dp[i][1] = true;
            }
        }

        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
    }

    /*for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < s.length(); j++)
        {
            cout << dp[j][i] << ' ';
        }
        cout << endl;
    }*/
    cout << "NO" << endl;
    return 0;
}