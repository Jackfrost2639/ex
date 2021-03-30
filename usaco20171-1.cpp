#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

int n;
int cow[100001];
pa order[100001];
int stree[400001];
int ans = 0;
int st = 1;

int calc(int l, int r){
  int sum = 0;

  for(l += st, r += st; l < r; l >>= 1, r >>= 1){
    if(l&1) sum += stree[l++];
    if(r&1) sum += stree[--r];
  }
  
  return sum;
}

int main() {
    freopen ("bphoto.in", "r", stdin);
    freopen ("bphoto.out", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> cow[i];
      order[i] = pa(cow[i], i);
    }

    sort(order, order+n, greater<pa>());
    while(st < n) st <<= 1;

    for(int i = 0; i < n; i++){
      int l = calc(0, order[i].second);
      int r = calc(order[i].second + 1, n);

      if(l > 2*r || r > 2*l) ans++;

      int t = st + order[i].second;
      while(t >= 1){
        stree[t] += 1;
        t /= 2;
      }
    }

    cout << ans << endl;
    return 0;
}