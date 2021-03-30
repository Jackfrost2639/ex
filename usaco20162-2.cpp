#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n, k;
int r[100];
ll dp[100][100][8];
ll ans = 1e18;

ll solve(int l, int r, int s){
  ll a = 1e18;
  if(l == r) return 0;
  if(dp[l][r][s] != 0) return dp[l][r][s];
  
  for(int i = l; i != r; i ++, i %= n) {
    a = min(a, solve(l, i, 1) + solve((i+1)%n, r, s-1));
  }

  return dp[l][r][s] = a;
}

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
      cin >> r[i];
    }
  
    for(int i = 0; i < n; i++){
      ll sum = 0;
      for(int j = 0; j < n; j++){
        int end = (i+j) % n;
        sum += j * r[end];
        dp[i][end][1] = sum;
      }    
    }

    for(int i = 0; i < n; i++){
      ans = min(ans, solve(i, (i+n-1)%n, k));
    }
    cout << ans << endl;
    return 0;
}