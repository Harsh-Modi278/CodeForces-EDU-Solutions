#include <iostream>
#include <limits.h>
#include <cstdint>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <cstring>
#include <deque>
#include <stack>
#include <queue>
#include <utility> 
#include <iomanip>      // std::setprecision
#include <sstream>      // std::stringstream
using namespace std;
typedef long long l1;
typedef long long unsigned lu1;
typedef long double ld;
#define FIO std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1.0)
#define pb push_back
// #define SORT(A) sort(A.begin(), A.end());
// #define REVERSE(A) reverse(A.begin(), A.end());
#define deb(x) cout << #x << ": " << x << "\n"
#define PrintArray(arr) for(int i=0;i<(int)arr.size();i++)cout<<arr[i]<<" ";cout<<"\n";
#define pii pair<int,int>
#define pll pair<long long int , long long int>
#define puu pair<long long unsigned , long long unsigned>
#define int long long
const int MOD = 1e9+7;

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    FIO;
    int t;
    t = 1;
    // cin>>t; 
    for (int tc=0;tc<t;tc++) 
    { 
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F
        int n, m;
        cin>>n>>m;
        string str, ss;
        cin>>str;
        cin>>ss;
        int freq[30];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<m;i++) freq[ss[i]-'a']++;
        int l = 0, r = 0, ans = 0;
        while(r<n)
        {
            if(freq[str[r]-'a'] > 0)
            {
                freq[str[r]-'a']--;
                // [l,r] is good => [l1, r1] is good, where l1>=l && r1<=r
                ans += (int)(r-l+1);
                // cout<<l<<" "<<r<<"\n";
            }
            else
            {
                while(freq[str[r]-'a'] <= 0)
                {
                    freq[str[l]-'a']++;
                    l++;
                }
                if(freq[str[r]-'a'] > 0)
                {
                    freq[str[r]-'a']--;
                    // [l,r] is good => [l1, r1] is good, where l1>=l && r1<=r
                    ans += (r-l+1);
                }
            }
            r++;
        }
        cout<<ans<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}