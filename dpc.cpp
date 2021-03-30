#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int dp[100000][3];
int arr[100000][3];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int h = 0; h < 3; h++)
            {
                if(j != h)
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][h] + arr[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}