#include <bits/stdc++.h>

using namespace std;

int n = 8;
int arr[100001] = {9, 1, 2, 3, 7, 4, 2, 1};
int tree[100001];
int ind = 1;

void upd(int i, int p)
{
    int t = tree[ind + i - 1];
    int d = t - p;
    int id = ind + i - 1;

    while(id > 0)
    {
        tree[id] += d;
        id /= 2;
    }
}

int sm(int s, int f)
{
    int sum = 0;
    int st = s + ind - 1;
    int fi = f + ind - 1;

    while(st < fi)
    {
        if(st%2 == 1)
        {
            sum += tree[st];
            st++;
        }
        if(fi%2 == 0)
        {
            sum += tree[fi];
            fi--;
        }

        st /= 2;
        fi /= 2;        
    }

    if(st == fi)
    {
        sum += tree[st];
    }

    return sum;
}

int main()
{
    while(ind < n) ind *= 2;
    for(int i = 0; i < n; i++)
    {
        tree[ind + i] = arr[i];
    }

    for(int i = ind-1; i >= 0; i--)
    {
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }


}