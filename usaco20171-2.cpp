#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, k;
int ord[100001];
int dp[100001][21][3];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setup("hps");
    cin >> n >> k;
    for(int i = 0; i < n; i++){
      char t;
      cin >> t;
      if(t == 'H') ord[i] = 0;
      if(t == 'P') ord[i] = 1;
      if(t == 'S') ord[i] = 2;
    }

    for(int i = 0; i < 3; i++){
      dp[0][0][i] = i == ord[0];
    }

    for(int i = 1; i < n; i++){
      for(int j = 0; j <= k; j++){
        if(i < j) break;
        
        for(int h = 0; h < 3; h++){
          int mx = 0;
          for(int p = 0; p < 3; p++){
            if(h == p) continue;
            if(!j) continue;
            mx = max(mx, dp[i-1][j-1][p] + (h == ord[i]));
          }

          dp[i][j][h] = max(mx, dp[i-1][j][h] + (h == ord[i]));
        }
      }
    }

    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j <= k; j++){
    //     cout << dp[i][j][0] << dp[i][j][1] << dp[i][j][2] << ' ';
    //   }
    //   cout << endl;
    // }
    int ans = 0;
    for(int i = 0; i <= k; i++){
      for(int j = 0; j < 3; j++){
        ans = max(ans, dp[n-1][i][j]);
      }
    }

    cout << ans << endl;

    return 0;
    
}