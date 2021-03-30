#include <bits/stdc++.h>

using namespace std;

int a, b, n, grd;
vector <int> fact;

bool cmp(int i,int j)
{
    return i > j;
}

int bsearch(int i)
{
    int t = 0;
    int b = fact.size()-1;
    int tem = 0;

    while(t <= b)
    {
        int m = (t+b)/2;
        if(fact[m] <= i)
        {
            b = m - 1;
            tem = max(tem, fact[m]);
        }
        if(fact[m] > i)
        {
            t = m + 1;
        }
    }

    return tem;
}

int main()
{
    cin >> a >> b >> n;
    grd = __gcd(a, b);
    fact.push_back(grd);

    for(int i = 1; i <= sqrt(grd); i++)
    {
        if(grd%i == 0)
        {
            fact.push_back(i);
            fact.push_back(grd/i);
        }
    }

    sort(fact.begin(), fact.end(), cmp);

    for(int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;

        int ans = bsearch(f);

        if(ans < s)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
        
    }
}