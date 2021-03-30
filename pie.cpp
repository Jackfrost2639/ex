#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

int n, d;
pa pie[200000];
pa bes[100000];
pa els[100000];
bool visited[200000];
int ans[200000];
int q[200000];
int front = 0, back = 0;

int bsearch(pa cow[], int x)
{
    int l = 0, r = n-1;
    int mid;
    while(r > l)
    {
        mid = (l+r+1)/2;
        if(cow[mid].first <= x)
        {
            l = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    return l;
}

int main()
{
    ifstream in("piepie.in");
    ofstream out("piepie.out");
    
    in >> n >> d;
    for(int i = 0; i < 2*n; i++)
    {
        int a, b;
        in >> a >> b;
        pie[i] = pa(a, b);

        if(a == 0 || b == 0)
        {
            q[back++] = i;
            ans[i] = 1;
            visited[i] = true;
        }

        if(i < n)
        {
            bes[i] = pa(b, i);
        }
        else
        {
            els[i%n] = pa(a, i%n);
        }
    }

    sort(bes, bes+n);
    sort(els, els+n);

    while(front != back)
    {
        int ind = q[front++];
        int s;
        if(ind < n)
        {
            s = bsearch(els, pie[ind].first);
            while(s >= 0 && els[s].first >= pie[ind].first - d)
            {
                if(!visited[els[s].second + n])
                {
                    q[back++] = els[s].second + n;
                    ans[els[s].second + n] = ans[ind] + 1;
                    visited[els[s].second + n] = true;
                }
                s--;
            }
        }
        else
        {
            s = bsearch(bes, pie[ind].second);
            while(s >= 0 && bes[s].first >= pie[ind].second - d)
            {
                if(!visited[bes[s].second])
                {
                    q[back++] = bes[s].second;
                    ans[bes[s].second] = ans[ind] + 1;
                    visited[bes[s].second] = true;
                }
                s--;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(ans[i] == 0)
        {
            out << -1 << endl;
        }
        else
        {
            out << ans[i] << endl;
        }
    }
}