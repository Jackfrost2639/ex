#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;
typedef pair<pa, int> desc;

int n;
desc cow[100];
int mx = -1;

int main()
{
    ifstream in("blist.in");
    ofstream out("blist.out");
    
    in >> n;
    for(int i = 0; i < n; i++)
    {
        int s, e, b;
        in >> s >> e >> b;
        cow[i] = desc(pa(e, s), b);
    }

    int cnt = 0;
    int h = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cow[i].first.first <= cow[j].first.first && cow[i].first.first > cow[j].first.second)
            {
                cnt += cow[j].second;
            }
        }
        mx = max(mx, cnt);
        cnt = 0;
    }

    out << mx << endl;
}