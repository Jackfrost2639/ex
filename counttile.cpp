#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int dp[1005][1024+1][10+1];
int n, m;
const int MOD = 1e9 + 7;

int main() {
  cin >> n >> m;

  int MAX = 1 << n;
  
  dp[0][0][0] = 1;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < MAX; j++){
      for(int k = 0; k <= n; k++){
        dp[i+1][(~j)&((1<<n)-1)][0] += dp[i][j][k];
        dp[i+1][(~j)&((1<<n)-1)][0] %= MOD;
        
        for(int h = k; h < n-1; h++){
          if(!(j & (3 << h))){
            //printf("%d, %d\n", i, j + (3<<h));
            dp[i][j + (3<<h)][h + 2] += dp[i][j][k];
            dp[i][j + (3<<h)][h + 2] %= MOD;
          }
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= n; i++){
    ans += dp[m-1][MAX-1][i];
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}