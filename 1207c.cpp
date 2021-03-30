#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int t;
const ll MAX = 1e18;
char road[200001];
ll dp[200001][2];

int main() {
    cin >> t;
    int n, a, b;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> a >> b;
        int s = a + b;
        cin >> road;
        for(int j = 0; j <= n; j++)
        {
            dp[j][0] = MAX;
            dp[j][1] = MAX;
        }

        dp[0][0] = b;

        for(int j = 1; j <= n; j++)
        {
            if(road[j-1] == '0' && road[j] != '1')
            {
                dp[j][0] = min(dp[j-1][0] + s, dp[j-1][1] + s + a);
            }
            dp[j][1] = min(dp[j-1][1] + s + b, dp[j-1][0] + 2 * s);
        }

        cout << dp[n][0] << endl;
    }
    return 0;
}