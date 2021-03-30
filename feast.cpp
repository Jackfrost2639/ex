#include <bits/stdc++.h>

using namespace std;

int t, a, b;
bool w[5000001];

int main()
{
    cin >> t >> a >> b;

    w[0] = true;

    for(int i = 0; i <= t; i++)
    {
        if(w[i])
        {
            if(i+a <= t) w[i+a] = true;
            if(i+b <= t) w[i+b] = true;
            w[i/2] = true;
        }
    }
    for(int i = 0; i <= t; i++)
    {
        if(w[i])
        {
            if(i+a <= t) w[i+a] = true;
            if(i+b <= t) w[i+b] = true;
        }
    }

    int mx = 0;
    for(int i = t; i >= 0; i--)
    {
        if(w[i])
        {
            cout << i << endl;
            return 0;
        }
    }
}