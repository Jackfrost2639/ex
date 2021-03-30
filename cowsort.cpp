#include <bits/stdc++.h>

using namespace std;

int n;
int seq[100000];
vector<int> sorted;

int main()
{
    ifstream in("sleepy.in");
    ofstream out("sleepy.out");
    
    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> seq[i];
    }

    int i = n-2;
    sorted.push_back(seq[n-1]);
    while(i > 0 && seq[i] < seq[i+1])
    {
        sorted.push_back(seq[i--]);
    }

    out << i+1 << endl;

    for(int j = 0; j <= i; j++)
    {
        int cnt = 0;
        for(int h = 0; h < sorted.size(); h++)
        {
            if(sorted[h] > seq[j])
            cnt++;
        }
        sorted.push_back(seq[j]);
        if(j == 0) out << n-cnt-1;
        else out << ' ' << n-cnt-1;
    }
}