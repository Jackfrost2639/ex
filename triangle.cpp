#include <bits/stdc++.h>

using namespace std;

int n;
long len[100001];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> len[i];
    }

    sort(len, len+n);

    int flag = false;
    for(int i = 2; i < n; i++)
    {
        if(len[i] < len[i-1] + len[i-2]) flag = true;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}