#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;
string pw;
int MAX = 1;
int pattern[20][20];

int main() {  
  cin >> n >> m;
  cin >> pw;

  MAX = 1 << m;
  int dp[MAX];

  for(int i = 0; i < MAX; i++) dp[i] = 1e9;
  dp[0] = 0;

  for(int i = 0; i < pw.length()-1; i++){
    pattern[pw[i]-'a'][pw[i+1]-'a']++;
  }

  for(int msk = 0; msk < MAX; msk++){
    int cnt = 0;
    for(int i = 0; i < m; i++){
      if(msk & (1 << i)) cnt++;
    }

    for(int i = 0; i < m; i++){
      if(msk & (1 << i)) continue;

      int nmsk = msk + (1 << i);

      int val = 0;
      for(int j = 0; j < m; j++){
        if (j == i) continue;
        if(msk & (1 << j)){
          val += pattern[j][i] * (cnt);
          val += pattern[i][j] * (cnt);
        }
        else{
          val -= pattern[j][i] * (cnt);
          val -= pattern[i][j] * (cnt);
        }
      }

      dp[nmsk] = min(dp[nmsk], dp[msk] + val);
      //printf("%d, %d, %d, %d, %d\n", nmsk, dp[nmsk], msk, dp[msk], val);
    }
    
  }

  //for(int i = 0; i < MAX; i++) cout << dp[i] << ' ';
  //cout << endl;
  cout << dp[MAX-1] << endl;

  return 0;
}