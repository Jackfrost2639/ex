#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair<int, int> pa;

int n, w;
pa cow[250];
int dp[1000];
int ans = 0;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {  
  setup("talent");
  
  cin >> n >> w;
  for(int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;

  sort(cow, cow+n);

  for(int i = 1; i < w; i++) dp[i] = -1;
  for(int i = 0; i < n; i++){
    for(int j = w-1; j >= 0; j--){
      int idx = j + cow[i].first;
      if(dp[j] != -1 && idx < w) dp[idx] = max(dp[j] + cow[i].second, dp[idx]);
      if(dp[j] != -1 && idx >= w) ans = max(ans, 1000*(dp[j] + cow[i].second)/(idx));
    }
  }

  cout << ans << endl;
  return 0;
}