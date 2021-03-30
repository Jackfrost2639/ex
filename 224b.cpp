#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100001];
int exist[100001];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;
    int ind  = 1;
    while(cnt < k)
    {
        if(exist[a[ind]] == 0)
        {
            cnt++;
            exist[a[ind++]]++;
        }
        else
        {
            exist[a[ind++]]++;
        }

        if(ind > n && cnt < k)
        {
            cout << -1 << ' ' << -1 << endl;
            return 0;
        }
    }

    int l = 1;
    int r = ind - 1;

    for(; l <= r; l++)
    {
        if(exist[a[l]] >= 2)
        {
            exist[a[l]]--;
        }
        else
        {
            break;
        }
    }

    cout << l << ' ' << r << endl;
}