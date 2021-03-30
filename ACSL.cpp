#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int s, d, r;
int a[10];

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int osum(int a, int b){
  int sum = 0, digit = 0, carry = 0, digit_rank = 1;
  while(a > 0 || b > 0 || carry){
    digit = a%10 + b%10 + carry;

    if(digit > 7){
      carry = 1;
      digit %= 8;
    }
    else{
      carry = 0;
    }
    
    sum += digit*digit_rank;
    digit_rank *= 10;

    a /= 10;
    b /= 10;
  }
  return sum;
}

int main() {  
  cin >> s >> d >> r;
  int add = 1;
  
  for(int i = 1; i <= r-1; i++){
    for(int j = 0; j < add; j++){
      s = osum(s, d);
    }
    add++;
  }

  int ans = 0;
  for(int i = 0; i < r; i++){
    int t = s;
    while(t > 0){
      ans += t%10;
      t /= 10;
    }

    s = osum(s, d);
  }
  cout << ans << endl;
  return 0;
}