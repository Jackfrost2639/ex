#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
ll t;

int main() {
    cin >> t;
    ll x1, y1, x2, y2;
    for(int i = 0; i < t; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = ((x2-x1) * (y2-y1)) + 1;
        cout << ans << endl;
    }
    return 0;
}