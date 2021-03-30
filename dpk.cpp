#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, k;
int rem[100];
bool dp[1000001];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> rem[i];
    }

    sort(rem, rem+n);

    for(int i = rem[0]-1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i - rem[j]) < 0) continue;

            //false = that person wins
            //true = that persno loses

            if(!dp[i - rem[j]])
            {
                dp[i] = true;
                break;
            }

            if(j == n-1)
            {
                dp[i] = false;
            }
        }
    }

    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}