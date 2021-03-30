#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[101];
bool dp[100001];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    //false is lose for person going next: true is win for perso going next
    dp[0] = false;

    for(int i = 1; i <= k; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(i - a[j] >= 0 && !dp[i-a[j]]) cnt ++;
        }
        if(cnt != 0) dp[i] = true;
        else dp[i] = false;
    }

    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}