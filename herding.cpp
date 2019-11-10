#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100001] = {0,};

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int start;
    int end;

    int mx = max(a[n]-a[2], a[n-1]-a[1]) - (n-2);

    int mn;
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        for(int j = i+1; j <= n; j++)
        {
            int ocow = (i-1) + (n-j);
            if(ocow <= a[j] - a[i] - (j-i))
            {
                temp = a[j] - a[i] - (j-i);
                break;
            }
        }
        mn = min(temp, mn);
    }

    cout << mn << endl << mx << endl;
}