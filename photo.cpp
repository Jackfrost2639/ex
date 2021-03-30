#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n;
int s[100000];
pa h[100000];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s[i] = x;
        h[i] = pa(x, i);
    }

    sort(h, h+n);
    int l = h[0].second;
    int r = n-1-h[0].second;
    int cnt = 0;
    
    if(l-r > 2 || r-l > 2) cnt++;

    for(int i = 1; i < n; i++)
    {
        int bi = h[i-1].second;
        int ci = h[i].second;
        if(ci > bi)
        {
            l += ci-bi-1;
            r -= ci-bi;
            if(l-r > 2 || r-l > 2) cnt++;
        }
        else
        {
            l -= ci-bi;
            r += ci-bi-1;
            if(l-r > 2 || r-l > 2) cnt++;
        }
    }
    cout << cnt << endl;
}