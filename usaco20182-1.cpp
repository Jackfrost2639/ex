#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair<int, int> pa;

struct tri{
  int s;
  int d;
  int idx;
};

int n, b;
int road[100001];
pa path[100001];
tri boot[100001];
bool ans[100001];

int llp[100001];
int lln[100001];

bool cmp(pa a, pa b){
  if(a.first != b.first) return a.first > b.first;
  else return a.second > b.second;
}

bool b_cmp(tri a, tri b){
  if(a.s != b.s) return a.s > b.s;
  else if(a.d != b.d) return a.d > b.d;
  else return a.idx > b.idx;
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    for(int i = 0; i < n; i++){
      cin >> road[i];
      path[i] = pa(road[i], i);
    }
    for(int i = 0; i < b; i++){
      cin >> boot[i].s >> boot[i].d;
      boot[i].idx = i;
    }

    sort(path, path+n, cmp);
    sort(boot, boot+b, b_cmp);

    int dist = 0;
    int ind = 0;
    for(int i = 0; i < n; i++){
      llp[i] = 1;
      lln[i] = 1;
    }

    for(int i = 0; i < b; i++) {
      while (boot[i].s < path[ind].first) {
        int t = path[ind].second;
        llp[t + lln[t]] = lln[t] + llp[t];
        lln[t - llp[t]] = lln[t] + llp[t];
        dist = max(dist, lln[t] + llp[t]);
        ind++;
      }

      //cout << dist << endl;

      if(boot[i].d >= dist) ans[boot[i].idx] = true;
      else ans[boot[i].idx] = false;
    }

    for(int i = 0; i < b; i++) cout << ans[i] << endl;
    return 0;
}