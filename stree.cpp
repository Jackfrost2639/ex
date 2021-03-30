#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n = 16;
const int MAX = 2 << 4;
int st = 1;
int tree[MAX*4];
int arr[MAX] = { 4, 2, 3, 1, 5, 2, 3, 4, 6, 7, 3, 2, 1, 3, 6,3 };

void build() {
  while(st < n) st <<= 1;

  for(int i = 0; i < n; i++) tree[st + i] = arr[i];

  for(int i = st-1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void modify(int d, int v){
  d += st;
  tree[d] = v;
  while(d > 1){
    tree[d/2] += tree[d] + tree[d+1];
    d /= 2;
  }
}

int query(int l, int r){
  int ans = 0;
  for(l += st, r += st; l < r; l >>= 1, r >>= 1){
    if(l&1) ans += tree[l++];
    if(r&1) ans += tree[--r];
  }
  
  return ans;
}

int main() {

  return 0;
}