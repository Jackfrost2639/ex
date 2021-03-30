#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n, k;
pa desc[51];
int r[51];

bool cmp(pa a, pa b)
{
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        desc[i] = pa(a, b);
    }

    sort(desc, desc+n, cmp);

    /*
    for(int i = 0; i < n; i++)
    {
        r[i]++;
        int cp = desc[i].first;
        int ct = desc[i].second;
        int ind = i;

        while(cp == desc[ind+1].first && ct == desc[ind+1].second)
        {
            r[i]++;
            ind++;
        }

        for(int j = 0; j <= ind-i; j++)
        {
            r[i + j] = r[i];
        }

        i = ind;
    }*/

    cout << r[k-1] << endl;
}