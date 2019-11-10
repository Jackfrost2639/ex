#include <bits/stdc++.h>

using namespace std;

int main()
{
    string code;
    long long N;

    cin >> code >> N;

    int len = code.length();
    long long n = len;

    while(len < N)
    {
        long long n = len;
        while(2*n < N)
        {
            n *= 2;
        }

        if(N == n+1)
        {
            N = n;
        }
        else
        {
            N = N-n-1;
        }
    }

    cout << code[N-1] << endl;
}