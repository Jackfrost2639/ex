#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7+1;
long long n;
long long dp[MAX];

int main()
{
    cin >> n;

    dp[1] = 0;

    for(long long i = 2; i <= n; i++)
    {
        if(i%2 == 0)
        {
            dp[i] = ((dp[i-1] * 3) + 3) % 1000000007;
        }
        else
        {
            dp[i] = ((dp[i-1] * 3) - 3) % 1000000007;
        }
    }

    cout << dp[n] << endl;
}