#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, b;
    bool traf[100000] = {0,};
    
    
    cin >> n >> k >> b;

    for(int i = 0; i < b; i++)
    {
        int h;
        cin >> h;
        traf[h] = true;
    }

    int ind = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++)
    {
        if(traf[i])
        {
            cnt++;
        }
    }

    int mn = cnt;

    for(int i = 1; i+k <= n; i++)
    {
        if(traf[i-1])
        {
            cnt--;
        }
        if(traf[i+k-1])
        {
            cnt++;
        }

        mn = min(mn, cnt);
    }
    
    cout << mn << endl;
}