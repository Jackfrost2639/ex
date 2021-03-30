#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;
typedef pair <int, pa> tri;

const int NUM = 110;
const int MOD = 1000000007;
const int INF = 1000000000;

int n;
int dp[505][130005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    dp[0][0] = 1;
    int run = (n+1)*n/2;

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= run; j++){
        dp[i][j] += dp[i-1][j];
        if(j-i >= 0) dp[i][j] += dp[i-1][j-i];

        dp[i][j] %= MOD;
      }
      cout << endl;
    }

    if(run % 2 == 0) cout << dp[n][run/2] << endl;
    else cout << 0 << endl;

    return 0;
}