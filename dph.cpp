#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

ll dp[1001][1001];
bool wall[1001][1001];
int h, w;
const ll MOD = 1e9 + 7;

int main() {
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            char t;
            cin >> t;
            if(t == '#')
            {
                wall[i][j] = true;
            }
        }
    }

    dp[1][1] = 1;

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(wall[i][j]) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]);
            dp[i][j] = dp[i][j] % MOD;
        }
    }

    cout << dp[h][w] << endl;
    return 0;
}