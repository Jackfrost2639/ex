#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;
typedef pair<int, pa> tri;

int n;
pa cow[25000];
vector <tri> ew;
int par[25000];
int cnt[25000];

int find(int i)
{
    if(par[i] == i) return i;
    else return find(par[i]);
}

void comb(int a, int b)
{
    int para = find(a);
    int parb = find(b);
    par[b] = para;
    cnt[para] += cnt[parb];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cow[i] = pa(a, b);
        par[i] = i;
        cnt[i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int dx = cow[i].first - cow[j].first;
            int dy = cow[i].second - cow[j].second;
            int dis = dx*dx + dy*dy;
            ew.push_back(tri(dis, pa(i, j)));
        }
    }

    sort(ew.begin(), ew.end());

    for(int i = 0; i < ew.size(); i++)
    {
        int a = ew[i].second.first;
        int b = ew[i].second.second;
        int d = ew[i].first;

        if(find(a) != find(b))
        {
            comb(a, b);
            if(cnt[find(a)] >= n)
            {
                cout << d << endl;
                break;
            }
        }
    }
}