#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

const ll INF = 1e18;
int n;
int a[101];
ll dp[101][101];

ll cnt(int s, int e){
  int ans = 0;
  for(int i = 0; i < e-s+1; i++){
    if(a[s+i] != i) ans++;
  }

  return ans;
}

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setup("taming");
  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < n; i++) dp[1][i] = cnt(0, i);

  for(int i = 2; i <= n; i++){
    for(int j = 0; j < n; j++){
      ll mn = INF;   

      for(int k = 0; k < j; k++){
        mn = min(mn, dp[i-1][k] + cnt(k+1,j));
      }

      dp[i][j] = mn;
    }
  }

  // for(int i = 1; i <= n; i++){
  //   for(int j = 0; j < n; j++){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  for(int i = 1; i <= n; i++){
    cout << dp[i][n-1] << endl;
  }
  return 0;
}