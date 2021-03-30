#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n;
int teach[200001];
int stud[200001];
int diff[200001];
ll cnt = 0;

int bsearch(int val)
{
    int l = 0;
    int r = n-1;
    int ans = n;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(diff[m] >= val)
        {
            r = m-1;
            ans = min(ans, m);
        }
        else if(diff[m] < val)
        {
            l = m+1;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> teach[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> stud[i];
    }
    for(int i = 0; i < n; i++)
    {
        diff[i] = teach[i] - stud[i];
    }

    sort(diff, diff+n);

    for(int j = 0; j < n; j++)
    {
        if(diff[j] <= 0)
        {
            int t = bsearch(-1 * diff[j] + 1);
            cnt += n - t;
        }
        else
        {
            cnt += (n-1) - j;
        }
    }

    cout << cnt << endl;
    return 0;
}