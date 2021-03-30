#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

int n, m, k;
pa word[5000];
int seq[26];
int dp[5001];
int endr[5001];

int exp(int base, int exponent)
{
    int ans = 1;
    for(int i = 0; i < exponent; i++)
    {
        ans *= base;
    }
    return ans;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        word[i] = pa(a,b);
        dp[a]++;
        //(length, rhyme class)
    }
    
    for(int i = 0; i < m; i++)
    {
        char temp;
        cin >> temp;
        seq[temp - 'A']++;
    }

    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(word[j].first > i)
            {
                continue;
            }
            dp[i] = (dp[i] + dp[i-word[j].first]) % 1000000007;
            if(i == k)
            {
                endr[word[j].second] = (endr[word[j].second] + dp[i-word[j].first]) % 1000000007;
            }
        }
    }

    int p = 1;

    for(int i = 0; i < 26; i++)
    {
        if(seq[i] == 0)
        {
            continue;
        }
        int s = 0;
        for(int j = 1; j <= n; j++)
        {
            if(endr[j] == 0)
            {
                continue;
            }

            s = (s + exp(endr[j], seq[i]) % 1000000007);
        }
        p = (p * s) % 1000000007;
    }

    cout << p << endl;
}