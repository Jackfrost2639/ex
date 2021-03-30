#include <bits/stdc++.h>

using namespace std;

int n;

long long bsearch(long long num)
{
    long long l = 1;
    long long r = 1e6;
    long long m;
    
    while(l < r)
    {
        m = (l+r)/2;
        if(m*m > num)
        {
            r = m;
        }
        else if(m*m < num)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
        
        //cout << l << ' ' << r << endl;
    }

    return -1;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        
        // s = binary search on t to find the best sqrt

        // s * s =
        if(t == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int ans = bsearch(t);

        if(ans == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool flag = true;
            for(int j = 2; j*j <= ans; j++)
            {
                if(ans % j == 0)
                {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "YES" << endl;
        }
    }


}