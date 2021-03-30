#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

const int MAX = 1.5e5 + 1;
int n;
int k;
int fence[MAX];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> fence[i];
    }

    int sum = 0;
    int mi = 0x7fffffff;
    int s = 0;
    for(int i = 0; i < k; i++)
    {
        sum += fence[i];
    }
    
    mi = sum;
    
    for(int i = 1; i < n-k+1; i++)
    {
        sum += fence[i+k-1];
        sum -= fence[i-1];

        if(smin(mi, sum))
        {         
            s = i;
        }
    }

    cout << s+1 << endl;
    return 0;
}