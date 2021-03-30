#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

ll n;
ll arr[200005];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> arr[j];
        }

        ll sum = 0;
        ll prev = arr[0];
        
        for(int j = 0; j < k; j++)
        {
            ll t = arr[j];
            if(prev > 0 != t > 0)
            {
                sum += prev;
                prev = t;
            }
            else
            {
                prev = max(prev, t);
            }
        }
        sum += prev;
        cout << imie(sum) << endl;
    }
    return 0;
}