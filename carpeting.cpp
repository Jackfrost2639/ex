#include <bits/stdc++.h>

using namespace std;

int n, k, p;

int main()
{
    cin >> n >> k >> p;
    if(n*n > p*p*k)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}