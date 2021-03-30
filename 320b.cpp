#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int ind = 0;
int intv[100][2];
vector <int> g[100];
bool visited[100];

bool dfs(int a, int d)
{
  if(visited[a]) return 0;
  visited[a] = true;
  
  for(auto e: g[a])
  {
    if(e == d || dfs(e, d)){
      return 1;
    }
  }

  return 0;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
      int t;
      cin >> t;
      if(t == 1){
        cin >> intv[ind][0] >> intv[ind][1];
        
        for(int j = 0; j < ind; j++){
          int a = intv[ind][0];
          int b = intv[ind][1];
          int c = intv[j][0];
          int d = intv[j][1];
          
          if((c < a && a < d) || (c < b && b < d)){
            g[ind].push_back(j);
          }
          if((a < c && c < b) || (a < d && d < b)){
            g[j].push_back(ind);
          }
        }

        ind++;
      }      
      else{
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if(dfs(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;

        for(int j = 0; j < ind; j++){
          visited[j] = false;
        }
      }
    }
    return 0;
}