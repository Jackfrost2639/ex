#include <bits/stdc++.h>

using namespace std;

int ans[1001];

int main()
{
    int n;
    cin >> n;

    ans[0] = 1;
    ans[1] = 2;
    for(int i = 2; i < n; i++)
    {
        ans[i] = (ans[i-1] + ans[i-2])%10007;
    }

    cout << ans[n-1] << endl;
}