#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main()
{
    cin >> n >> m >> k;

    if(m == 1) cout << 1 << endl;
    else if(k == 1 || k > n) cout << pow(m, n) << endl;
    else if(k == n) cout << pow(m, (n+1)/2) << endl;
    
}