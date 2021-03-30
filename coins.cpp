#include <bits/stdc++.h>

using namespace std;

int n;
int c[101];
int s = 0;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        s += c[i];
    }

    sort(c, c+n);
    int m = c[n-1];
    int cnt = 1;
    int i = n-2;

    while(m <= (s - m))
    {
        cnt++;
        m += c[i--];
    }
    
    cout << cnt << endl;
}