#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pa;

int n;
long long a[100001];
long long tree[400001];
long long g[100001];
int ins[100001];
pa order[100001];
vector <pa> v;
long long s[100001];
int ind = 1;

bool cmp(pa x, pa y)
{
    if(x.first != y.first) return x.first > y.first;
    else return x.second > y.second;
}

void upd(int i)
{
    int id = ind + i;

    while(id > 0)
    {
        tree[id]++;
        id /= 2;
    }
}

int sm(int s, int f)
{
    long long sum = 0;
    int st = s + ind;
    int fi = f + ind;

    while(st < fi)
    {
        if(st%2 == 1)
        {
            sum += tree[st];
            st++;
        }
        if(fi%2 == 0)
        {
            sum += tree[fi];
            fi--;
        }

        st /= 2;
        fi /= 2;        
    }

    if(st == fi)
    {
        sum += tree[st];
    }

    return sum;
}

int main()
{
     freopen("haircut.in", "r", stdin);
     freopen("haircut.out", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        order[i] = pa(a[i], i);
    }
    sort(order, order+n, cmp);

    for(int i = 0; i < n; i++)
    {
        ins[i] = order[i].second;
    }
    while(ind < n) ind *= 2;

    long long tl = 0;
    for(int i = 0; i < n; i++)
    {
        upd(ins[i]);
        g[ins[i]] = sm(0, ins[i]-1);
        //cout << ins[i] << " " << g[ins[i]] << endl;
        tl += g[ins[i]];
    }

    for(int i = 0; i < n; i++)
    {
        v.push_back(pa(a[i], g[i]));
    }
    sort(v.begin(), v.end());

    int it = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        while(v[it].first < i && it < n)
        {
            sum += v[it].second;
            it++;
        }
        cout << sum << endl;
    }
}