#include <bits/stdc++.h>

using namespace std;

int n, m;
int th[1000000];

bool check(int h)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if((th[i]-h) >= 0)
        {
            sum += (th[i]-h);
        }
    }

    if(sum >= m)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> th[i];
        mx = max(mx, th[i]);
    }

    int s = 0, e = mx;
    while(s < e)
    {
        int m = (s+e+1)/2;
        if(check(m))
        {
            s = m;
        }
        else
        {
            e = m-1;
        }
    }
    
    cout << e << endl;
}