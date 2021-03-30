#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef pair <int, int> pa;

int n;
const int MAX = 1 << 16;
int d[MAX];
int s[MAX];
stack <int> leaf;
vector <pa> ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> d[i] >> s[i];
      if(d[i] == 1) {
        leaf.push(i);
      }
    }

    while(!leaf.empty()){
      int t = leaf.top();
      leaf.pop();
      if (d[t] == 0) continue;
      int nxt = s[t];

      d[nxt]--;
      s[nxt] ^= t;
      ans.push_back(pa(t,nxt));
      if(d[nxt] == 1) leaf.push(nxt);
    }

    cout << ans.size() << endl;
    for(auto e: ans){
      cout << e.first << ' ' << e.second << endl;
    }
    return 0;
}