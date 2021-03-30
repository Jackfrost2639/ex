#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pa;

#define NUM 100100
#define MOD 1000000007
#define INF 1000000000
typedef long long LL;
typedef pair<int,int> pi;

using namespace std;

#define NUM 100100
#define MOD 1000000007
#define INF 1000000000
typedef long long LL;
typedef pair<int,int> pi;

using namespace std;

int ans[100100];
vector<map<int, set<int>>> rule[100100];
int dp[100100][30];
string hear;
vector<char> curr;
vector<int> last;

bool check(string s, int prev){
    bool exist[26] = {false,};
    for(int i=0;i<s.length();++i){
        if(!exist[s[i]-'a']) exist[s[i]-'a'] = true;
        else {
            return false;
        }
    }

    if(prev == -1) return true;

    for(int t=0;t<rule[prev].size();++t){
        bool flag = false;

        for(int i=0;i<s.length();++i){
            for(int j=i+1;j<s.length();++j){
                if(rule[prev][t][s[j]-'a'].count(s[i]-'a')){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag) last.push_back(t);
    }

    return true;
}

int main(){
    cin >> hear;

    memset(ans,0x7F,sizeof(ans));
    ans[0] = 0;

    for(int i=0;i<hear.length();++i){
        for(int j=1;j<=26;++j){
            if(i+1 < j) break;

            string sub = hear.substr(i-j+1, j);

            last.clear();
            if(check(sub, i-j)){
                dp[i][j] = ans[i-j+1] + 1;
            }
            else continue;

            if(ans[i+1] >= dp[i][j]){
                if(ans[i+1] > dp[i][j]){
                    rule[i].clear();
                    ans[i+1] = dp[i][j];
                }

                vector<map<int, set<int>>> temp;
                if(i-j >= 0){
                    for(int t=0;t<last.size();++t) {
                        temp.push_back(rule[i-j][last[t]]);
                    }
                }

                for(int t=0;t<temp.size();++t){
                    for (int a = 0; a < sub.length(); ++a) {
                        for (int b = a + 1; b < sub.length(); ++b) {
                            int ta = sub[a] - 'a';
                            int tb = sub[b] - 'a';

                            temp[t][ta].insert(tb);
                        }
                    }
                }

                rule[i] = temp;
            }
        }
    }

    cout << ans[hear.length()] << endl;

    return 0;
}