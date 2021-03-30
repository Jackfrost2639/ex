#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;
int farm[100005];
int dp[100005][3][25];

int main() {  
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    char t;
    cin >> t;

    if(t == 'H') farm[i] = 0;
    else if(t == 'P') farm[i] = 1;
    else if(t == 'S') farm[i] = 2;
  }

  dp[0][0][0] = farm[0] == 0 ? 1 : 0;
  dp[0][1][0] = farm[0] == 1 ? 1 : 0;
  dp[0][2][0] = farm[0] == 2 ? 1 : 0;

  for(int i = 1; i < n; i++){
    for(int j = 0; j < 3; j++){
      dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
      for(int h = 0; h <= min(i, k); h++){
        if()
        for(int t = 0; t < 3; t++){

        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j <= k; j++){
      ans = max(ans, dp[n-1][i][j]);
    }
  }

  cout << ans << endl;
  for(int i = 0; i <= k; i++){
    for(int j = 0; j < 3; j++){
      for(int h = 0; h < n; h++) cout << dp[h][j][i] << ' ';
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}