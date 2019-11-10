#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

bool cmp(pa a, pa b)
{
    if(a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

int main()
{
    int n, total;
    cin >> n;
    total = n;
    pa base[100000];

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        base[i].first = x-y;
        base[i].second = x+y;
    }

    sort(base, base+n, cmp);
    int cnt = 0, mxe = -99999;

    for(int i = 0; i < n; i++)
    {
        if(mxe < base[i].second)
        {
            mxe = base[i].second;
            cnt++;
        }
    }

    cout << cnt << endl;
}