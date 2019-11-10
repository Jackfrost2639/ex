#include <bits/stdc++.h>

using namespace std;

int cow[10000];
int pos[10000];

int ftime(int k, int n)
{
    int mn = 0;
    memset(pos, 0, k*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        pos[mn] += cow[i];
        for(int j = 0; j < k; j++)
        {
            if(pos[mn] > pos[j])
            {
                mn = j;
            }
        }
    }

    int mx = -1;

    for(int i = 0; i < k; i++)
    {
        mx = max(mx, pos[i]);
    }

   // cout << mx << endl;

    return mx;
}

int main()
{
    ifstream in("cowdance.in");
    ofstream out("cowdance.out");
    
    int n, tmax;
    in >> n >> tmax;

    int left = 1, right = n;

    for(int i = 0; i < n; i++)
    {
        in >> cow[i];
    }

    while(left < right)
    {
        int mid = (right+left)/2;
        int time = ftime(mid, n);

        if(time > tmax)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }

    out << left;
}