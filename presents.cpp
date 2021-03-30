#include <bits/stdc++.h>

using namespace std;

int n;
int ans[101];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        ans[a] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}