#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
/*
Bessie:
folder1/file1
folder1/folder2/file2
folder3/file3
file4

Folder 1:
file1
folder2/file2
../folder3/file3
../file4

folder 2:
../file1
file2
../../folder3/file3
../../file4
*/

int n;
vector<int> dir[100000];
int len[100000];
int sum = 0;
int nf[100000];
int ans = 0x7fffffff;

void fsum(int d, int l){
    int s = dir[d].size();
    int nl = l + len[d] + 1;
    if(s == 0){
        sum += nl - 1;
    }
    else{
        for(int i = 0; i < s; i++){
            fsum(dir[d][i], nl);
        }
    }
}

int cfile(int d)
{
    int cnt = 0;
    if(dir[d].size() == 0){
        nf[d] = cnt;
        return 1;
    }
    for(auto e: dir[d]){
        cnt += cfile(e);
    }
    nf[d] = cnt;
    return cnt;
}

void fa(int d, int s){
    s -= nf[d] * (len[d]+1);
    s += 3 * (nf[0] - nf[d]);
    ans = min(ans, s);
    //cout << imie(d) imie(s) << endl;    
    for(auto e: dir[d]){
        if(nf[e] == 0) continue;
        fa(e, s);
    }
}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        int c;
        cin >> temp >> c;
        len[i] = temp.length();
        for(int j = 0; j < c; j++){
            int t;
            cin >> t;
            dir[i].push_back(t-1);
        }
    }

    fsum(0, 0);
    //cout << sum << endl;
    cfile(0);
    fa(0, sum);

    cout << ans << endl;

    return 0;
}