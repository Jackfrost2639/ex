#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

const int MOD = 1e9+7;

string in;
int a[100005];
int dp[100005][5][5][5];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main() {  
  cin >> in;
  int len = in.length();
  
  for(int i = 0; i < len; i++){
    if(in[i] == 'A') a[i] = 0;
    else if(in[i] == 'T') a[i] = 1;
    else if(in[i] == 'C') a[i] = 2;
    else if(in[i] == 'G') a[i] = 3;
    else a[i] = 4;
  }

  for(int i = 0; i < 4; i++){
    if(a[0] != 4) dp[0][i][a[0]][a[0]] = 1;
    else{
      for(int j = 0; j < 4; j++){
        dp[0][i][j][j] = 1;
      }
    }
  }

  for(int i = 0; i < len; i++){
    for(int h = 0; h < 4; h++){
      if(a[i] == 4 || a[i] == h){
        for(int s = 0; s < 4; s++){
          if((a[i+1] == 4 || a[i+1] == s) && s != h){
            for(int k = 0; k < 4; k++){
              for(int j = 0; j < 4; j++){
                dp[i+1][j][k][s] += dp[i][j][k][h];
                dp[i+1][j][k][s] %= MOD;
              }
            }
          }
        }
      }
    }

    for(int h = 0; h < 4; h++){
      if (a[i] == 4 || a[i] == h) {
        for(int s = 0; s < 4; s++){
          if (a[i+1] == 4 || a[i+1] == s) {
            for(int j = 0; j < 4; j++){
              dp[i+1][j][s][s] += dp[i][h][j][h];
              dp[i+1][j][s][s] %= MOD;
            }
          }
        }
      }
    }
  }

  long long ans = 0;
  if(a[len-1] == 4){
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++) ans += dp[len-1][i][j][i];
    }
  }
  else{
    for(int i = 0; i < 4; i++) ans += dp[len-1][a[len-1]][i][a[len-1]];
  }

  cout << ans%MOD << endl;
  return 0;
}