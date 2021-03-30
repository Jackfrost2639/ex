#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
bool sh[51][51];
int rdp[51][51];
int cdp[51][51];

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char t;
      cin >> t;
      if(t == '\n') cin >> t;
      if(t == 'B') sh[i][j] = true;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      rdp[i][j] = rdp[i][j-1] + sh[i][j];
      cdp[i][j] = cdp[i-1][j] + sh[i][j];
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(!sh[i][j]) continue;
      
      for(int x = 1; x <= n; x++){
        for(int y = 1; y <= m; y++){
          if(!sh[x][y]) continue;

          bool xy = false, yx = false;
          int a1 = max(x, i);
          int a2 = min(x, i);
          int b1 = max(y, j);
          int b2 = min(y, j);
          if(cdp[a1][j] - cdp[a2-1][j] == a1-a2+1 && rdp[x][b1] - rdp[x][b2-1] == b1-b2+1) xy = true;
          if(cdp[a1][y] - cdp[a2-1][y] == a1-a2+1 && rdp[i][b1] - rdp[i][b2-1] == b1-b2+1) yx = true;

          if(!xy && !yx){
            cout << "NO" << endl;
            //printf("(%d, %d) (%d, %d) \n", i, j, x, y);
            return 0;
          }
          //else printf("(%d, %d) (%d, %d) \n", i, j, x, y);
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}