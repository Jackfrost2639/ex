#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

const ll INF = 1e18;
int h, g;
int hx[1001];
int hy[1001];
int gx[1001];
int gy[1001];
ll dp[1001][1001][2];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll dif(bool x, int i, bool y, int j) {
  ll a = (x ? hx : gx)[i] - (y ? hx : gx)[j];
  ll b = (x ? hy : gy)[i] - (y ? hy : gy)[j];
  return a*a + b*b;
}

void _(ll v) {
  if (v == INF) cout << ".";
  else cout << v;
} 

int main() {
  setup("checklist");
  cin >> h >> g;
  for(int i = 1; i <= h; i++){
    cin >> hx[i] >> hy[i];
  }
  for(int i = 1; i <= g; i++){
    cin >> gx[i] >> gy[i];
  } 

  for (int i=0; i<=h; i++) 
    dp[i][0][1] = INF;
  for (int j=1; j<=g; j++) {
    dp[0][j][0] = dp[0][j][1] = INF;
  }

  hx[0] = hx[1];
  hy[0] = hy[1];

  for(int i = 1; i <= h; i++){
    for(int j = 0; j <= g; j++){    
      ll l2 = dp[i-1][j][1] + dif(true, i, false, j);
      ll l3 = dp[i-1][j][0] + dif(true, i, true, i-1);
      dp[i][j][0] = min(l2, l3);
      
      if(j){
        ll l1 = dp[i][j-1][1] + dif(false, j, false, j-1);
        ll l4 = dp[i][j-1][0] + dif(false, j, true, i);
        dp[i][j][1] = min(l1, l4);
      }
    }
  }

  // for(int i = 0; i <= h; i++){
  //   for(int j = 0; j <= g; j++){
  //     _(dp[i][j][0]);
  //     cout << ":";
  //     _(dp[i][j][1]);
  //     cout << ' ';
  //   }
  //   cout << endl;
  // }
  cout << dp[h][g][0] << endl;
  return 0;
}