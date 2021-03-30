#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
string s;
int dp[100001];

int main() {
    cin >> s;
    for(int i = 1; i < s.length(); i++)
    {
        dp[i] = dp[i-1];
        if(s[i] == s[i-1])
        {
            dp[i]++;
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << endl;
    }

    // for(int i = 0; i < s.length(); i++) cout << dp[i] << ' ';
    // cout << endl;
    return 0;
}