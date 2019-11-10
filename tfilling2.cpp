#include <bits/stdc++.h>

using namespace std;

int ans[1001];
int s[1001];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    ans[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(s[j] < s[i])
            {
                ans[i] = max(ans[i], ans[j]);
            }
        }
        ans[i]++;
    }

    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, ans[i]);
    }

    cout << mx << endl;
}