#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;
typedef pair<int, pa> tri;

int n, b;
pa fb[100000];
pa a[100000];
tri boots[100000];
bool ans[100000];

int main()
{
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        fb[i] = pa(i-1, i+1);
        a[i] = pa(t, i);
    }
    for(int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        boots[i] = tri(x, pa(y, i));
    }

    sort(a, a+n);
    sort(boots, boots+b);

    int mx = 0;
    int j = n-1;
    for(int i = b-1; i >= 0; i--)
    {
        int depth = boots[i].first;
        int skip = boots[i].second.first;
        int ind = boots[i].second.second;

        while(j >= 0 && depth < a[j].first)
        {
            int tind = a[j].second;
            int f = fb[tind].second;
            int b = fb[tind].first;

            fb[b].second = f;
            fb[f].first = b;
            mx = max(mx, f - b);
            j--;
        }

        if(mx <= skip)
        {
            ans[ind] = true;
        }
        else
        {
            ans[ind] = false;
        }
    }

    for(int i = 0; i < b; i++)
    {
        cout << ans[i] << endl;
    }
}
