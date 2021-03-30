#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n;
multiset <string> s;

int main() {
    setup("cowpatibility");

    cin >> n;

    map<string, long long> subsets;

    for(int i = 0; i < n; i++){
        int flavors[5];
        for(int j = 0; j < 5; j++){
            cin >> flavors[j];
        }

        sort(flavors, flavors + 5);

        for(int j = 1; j < 31; j++){
            string subsetString = "";

            int t = j;
            int len = 0;
            int cnt = 0;

            while(t > 0){
                if(t%2){
                    subsetString += to_string(flavors[cnt]) + ",";
                    len++;
                }

                cnt++;
                t/=2;
            }
            subsetString += to_string(len);
            subsets[subsetString]++;
        }
    }

    long long ans = n*(n-1)/2;
    for(auto curr:subsets) {
        string str = curr.first;
        long long num = curr.second;

        if(num == 1) continue;

        if((str[str.length()-1] - '0')%2 == 1) ans -= num * (num-1)/2;
        else ans += num * (num-1)/2;
    }

    cout << ans << endl;

    return 0;
}