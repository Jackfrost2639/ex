#include <bits/stdc++.h>

using namespace std;

long long n, a, b;
long long cnt[100001];

int bsearch(double x)
{
    int l = 0;
    int r = 1e9;
    int ans = 0x7fffffff;
    
    while(l <= r)
    {
        int m = (l+r)/2;
        double temp = (m*a)/b;
        if(temp >= x)
        {
            r = m - 1;
            ans = min(ans, m);
        }
        if(temp < x)
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> a >> b;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> cnt[i];
    }

    for(int i = 0; i < n; i++)
    {
        long long c = (cnt[i]*a)/b;
        int temp = bsearch(c);
        cout << cnt[i] - temp << ' ';
    }
    cout << endl;
}