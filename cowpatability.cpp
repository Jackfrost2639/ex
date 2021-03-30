#include <bits/stdc++.h>

using namespace std;

typedef struct flav
{
    int size;
    int over[5];
}flav;

bool operator<(const flav a, const flav b)
{
    for(int i=0; i<5; i++)
   {
    if(a.over[i] > b.over[i]) return true;
    if(a.over[i] < b.over[i]) return false;

   } 
}

int n;

flav sbset(int f[], int num)
{
    flav temp = {0, {0,0,0,0,0}};

    for(int i = 0; i < 5; i++)
    {
        if(num & (1 << i))
        {
            temp.over[temp.size++] = f[i];
        }
    }
    
    
    //printf("%d \\\\ %d %d %d %d %d \n", temp.size, temp.over[0], temp.over[1],temp.over[2],temp.over[3],temp.over[4]);
    
    return temp;
}   

long long ans;
map<flav, int> pa;

int main()
{
    ifstream in("cowpatibility.in");
    ofstream out("cowpatibility.out");
    
    in >> n;
    for(int i = 0; i < n; i++)
    {
        int f[5];
        in >> f[0] >> f[1] >> f[2] >> f[3] >> f[4];
        sort(f, f+5);
        for(int j = 1; j < 32; j++)
        {
            pa[sbset(f, j)]+=1;
        }
    }

    ans = n * (n-1)/2;

    for(auto &x : pa)
    {
        //printf("%d %d %d\n", ans, x.first.size, x.second);
        if(x.first.size%2 == 1)
        {
            ans -= (x.second)*(x.second-1)/2;
        }
        else
        {
            ans += (x.second)*(x.second-1)/2;
        }
        
    }

    out << ans << endl;
}