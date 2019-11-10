#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int edge[100001] = {0,};
    int mx = 0;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a]++;
        edge[b]++;
        mx = max(mx, edge[a]);
        mx = max(mx, edge[b]);
    }

    cout << mx+1 << endl;
}