#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;
typedef pair<int, pa> tri;

int n, q;
tri edge[100001];
tri query[100001];
int par[100001];
int siz[100001];
int ans[100001];

int fpar(int ind)
{
    if(par[ind] == ind)
    {
        return ind;
    }
    else
    {
        return fpar(par[ind]);
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = tri(c, pa(a, b));
    }
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        query[i] = tri(a, pa(b, i));
    }
    sort(edge, edge+n);
    sort(query, query+n);

    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }

    int ein = n-1;
    for(int i = q; i > 0; i--)
    {
        int k = query[i].first;
        while(ein > 0 && edge[ein].first >= k)
        {
            int npar = fpar(edge[ein].second.first);
            int comb = fpar(edge[ein].second.second);

            par[comb] = npar;
            siz[npar] = siz[npar] + siz[comb];
            ein--;
        }

        ans[query[i].second.second] = siz[fpar(query[i].second.first)];
    }

    for(int i = 1; i <= q; i++)
    {
        cout << ans[i]-1 << endl;
    }
}