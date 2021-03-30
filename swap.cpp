#include <bits/stdc++.h>

using namespace std;

int n;
int seq[100001];
int sseq[100001];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> seq[i];
        sseq[i] = seq[i];
    }

    sort(sseq, sseq+n);
    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(seq[i] != sseq[i]) cnt++;
    }

    if(cnt > 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}