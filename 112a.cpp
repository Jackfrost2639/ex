#include <bits/stdc++.h>

using namespace std;

string a;
string b;

int main()
{
    cin >> a >> b;
    int len = a.length();
    int d = 'a' - 'A';

    for(int i = 0; i < len; i++)
    {
        if(a[i] < 'a') a[i] += d;
        if(b[i] < 'a') b[i] += d;
    }

    //cout << a << endl << b << endl;

    for(int i = 0; i < len; i++)
    {
        if(a[i] == b[i])
        {
            if(i == len-1)
            {
                cout << 0 << endl;
                return 0;
            }
            else
            {
                continue;
            }
        }
        else
        {
            int t = a[i]- b[i];
            if(t > 0) cout << 1 << endl;
            else cout << -1 << endl;
            return 0;
        }
    }
}