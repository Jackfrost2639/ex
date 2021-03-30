#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, m;
char str[101][101];
bool chk[101];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> str[i][j];
      }
    }
    
    int cnt = 0;
    for(int i = 0; i < m; i++){
      bool flag = false;
      for(int j = 0; j < n-1; j++){
        if(!chk[j] && str[j][i] > str[j+1][i]){
          cnt++;
          flag = true;
          break;
        }
      }

      if(flag) continue;
      
      for(int j = 0; j < n-1; j++){
        if(str[j][i] < str[j+1][i]){
          chk[j] = true;
        }
      }
    }

    cout << cnt << endl;
    return 0;
}