#include <bits/stdc++.h>

using namespace std;

int n, m;
int lad[100001];
int incr[100001];
int decr[100001];

int main()
{
    cin >> n >> m;
    lad[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> lad[i];
        incr[i] = i;
        decr[i] = i;
    }

    for(int i = n; i >= 1; i--)
    {
        if(lad[i] >= lad[i-1]) incr[i-1] = incr[i];
        if(lad[i] <= lad[i-1]) decr[i-1] = decr[i];
    }

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        if(decr[incr[l]] >= r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}