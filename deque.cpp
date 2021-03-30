#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int a[3001];
ll dp[3001][3001];

ll solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return a[l];
    return dp[l][r] = max(a[l]-solve(l+1, r), a[r]-solve(l, r-1));
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<3001; i++) {
        for (int j=0; j<3001; j++) {
            dp[i][j] = -1;
        }
    }
    cout << solve(1, n);
}