#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

int n;
pa cow[1001];
bool visited[1001];
int mx = 0;


void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {  
  setup("moocast");
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x, y;
    cin >> x >> y;
    cow[i] = pa(x, y);
  }

  priority_queue <pa, vector<pa>, greater<pa>> q;
  q.push(pa(0, 1));

  while(!q.empty()){
    pa t = q.top();
    q.pop();

    if(visited[t.second]) continue;
    else visited[t.second] = true;

    mx = max(mx, t.first);
    for(int i = 1; i <= n; i++){
      if(t.second == i) continue;
      int xdif = cow[t.second].first - cow[i].first;
      int ydif = cow[t.second].second - cow[i].second;
      q.push(pa(xdif * xdif + ydif * ydif, i));
    }
  }

  cout << mx << endl;

  return 0;
}