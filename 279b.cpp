#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, t;
int ft[100001];

int main() {
    cin >> n >> t;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> ft[i];
    }
    int l, r = 0;
    
    int best=0;
    for (l=0; l<n; sum -= ft[l++]) {
        while(sum + ft[r] <= t && r < n) {
            sum += ft[r++];
        }
        best = max(best, r-l);
    }

    cout << best;

    return 0;
}