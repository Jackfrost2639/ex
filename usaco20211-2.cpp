#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 1 << 20;
string let;
int pattern[20][20];
int dp[MAX];
int chti[26];
int c = 0;

int cti(char a){
  return chti[a - 'a'];
}

int main() {  
  cin >> let;

  for(int i = 0; i < 26; i++) chti[i] = -1;

  for(int i = 0; i < let.length() - 1; i++){
    if(chti[let[i] - 'a'] == -1) chti[let[i] - 'a'] = c++;
  }

  for(int i = 0; i < let.length() - 1; i++){
    pattern[cti(let[i])][cti(let[i+1])]++;
  }

  for(int i = 0; i < (1<<c); i++) dp[i] = 1e9;
  dp[0] = 0;

  for(int msk = 0; msk < (1<<c); msk++){
    int cnt = 0;
    for(int i = 0; i < c; i++) if(msk & (1 << i)) cnt++;

    for(int i = 0; i < c; i++){
      if(msk & (1 << i)) continue;

      int nmsk = msk + (1 << i);

      int val = 0;
      for(int j = 0; j < c; j++){
        if(i == j){
          val += pattern[i][j] * 26;
          continue;
        }

        if(msk & (1 << j)){
          val += pattern[j][i] * (cnt);
          val -= pattern[i][j] * (cnt - 26);
        }
        else{
          val += pattern[j][i] * (cnt);
          val -= pattern[i][j] * (cnt);
        }
      }

      dp[nmsk] = min(dp[nmsk], dp[msk] + val);
    }
  }

  //for(int i = 0; i < (1<<c); i++) cout << i << ' ' << dp[i] << endl;

  //cout << dp[(1<<c)-1] << endl;
  cout << dp[(1<<c)-1]/26 + (dp[(1<<c)-1]%26 == 0 ? 0 : 1) << endl;

  return 0;
}