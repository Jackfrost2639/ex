#include <bits/stdc++.h>

using namespace std;

int n;
double l;
double road[1001];

int main()
{
    cin >> n >> l;
    double mx = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> road[i];
    }

    sort(road, road+n);

    for(int i = 1; i < n; i++)
    {
        mx = max(mx, road[i] - road[i-1]);
    }

    double ans = mx/2;

    ans = fmax(mx/2, fmax(l-road[n-1], road[0]));

    printf("%9lf", ans);
}