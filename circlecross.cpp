#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n;
pa cow[50001];
int tree[100000000];

int get(int i)
{
    int s = 0;
    int ind = i-1;
    while (ind > 0)
    {
        s += tree[ind];
        ind -= (ind & -ind);
    }
    return s;
}

void upd(int i)
{
    int ind = i-1;
    while(ind <= n)
    {
        tree[ind]++;
        ind += (ind & -ind);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= 2*n; i++)
    {
        int t;
        cin >> t;
        if(cow[t].first == 0) cow[t].first = i;
        else cow[t].second = i;
    }

    sort(cow+1, cow+n+1);
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        sum += get(cow[i].second) - get(cow[i].first);
        upd(cow[i].second);
    }
}