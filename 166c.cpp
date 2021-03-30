#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, x;
vector <int> arr;
bool pres;

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
        if(t == x) pres = true;
    }
    
    sort(arr.begin(), arr.end());
    int l, r;
    int cnt = 0;

    if(pres)
    {
        l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        r = n - (upper_bound(arr.begin(), arr.end(), x) - arr.begin());

        cout << l << ' ' << r << endl;

        while((n+cnt)/2 < l && (n+cnt)/2 > r)
        {
            if(n/2 < l)
            {
                l++;
                cnt++;
            }
            else
            {
                r++;
                cnt++;
            }
        }
    }
    
    else
    {
        arr.push_back(x);
        sort(arr.begin(), arr.end());
        l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        r = n - (upper_bound(arr.begin(), arr.end(), x) - arr.begin());

        while((n+cnt)/2 < l && (n+cnt)/2 > r)
        {
            if(n/2 < l)
            {
                l++;
                cnt++;
            }
            else
            {
                r++;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}