#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

int n;
int s;
pa idx[100001];
pa pos[100001];
int stree[400005];
int ans = 0;

void fstart(int a){
  s = 1;
  while(s < a) s <<= 1;
}

void upd(int i, int p){
  int ind = p + s;
  while(ind > 0){
    stree[ind] += i;
    ind /= 2;
  }
}

int query(int l, int r){
  int ans = 0;
  for(l += s, r += s; l < r; l >>= 1, r >>= 1){
    if(l&1) ans += stree[l++];
    if(r&1) ans += stree[--r];
  }
  
  return ans;
}

void setup(string s){
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setup("sort");
  
  cin >> n;
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    idx[i] = pa(t, i);
  }  

  sort(idx, idx+n);

  for(int i = 0; i < n; i++){
    pos[idx[i].second] = pa(i, idx[i].first);
  }

  fstart(n);
  
  for(int i = 0; i < n; i++){
    int t = query(i, n);
    ans = max(ans, t);
    
    upd(1, pos[i].first);
  }

  cout << max(ans, 1) << endl;

  return 0;
}