#include <bits/stdc++.h>

using namespace std;

int n, c, m;
int t[100005];


bool isPos(int mt)
{
    int cnt = 0;
    int wt = 0;
    int bcnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt++;
        if(t[i] - t[wt] > mt || cnt > c)
        {
            bcnt++;
            cnt = 1;
            wt = i;
        }

        if(bcnt >= m)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    sort(t, t + n);

    int l = 0, r = t[n-1] - t[0];
    while(l < r)
    {
        int mid = (r+l)/2;
        if(isPos(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;
}