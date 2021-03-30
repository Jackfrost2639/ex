#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n;
int cow[100000];
queue <int> calc;
ll sum = 0;



int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> cow[i];
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < cow[i]; j++) calc.push(i);

      if(!calc.empty()) calc.pop();
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < cow[i]; j++) calc.push(i);
      int t = calc.front();
      calc.pop();

      ll a = (i-t+n)%n;
      sum += a * a;
    }

    cout << sum << endl;
    return 0;
}