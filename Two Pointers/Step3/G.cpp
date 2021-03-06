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
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G
        int n, c;
        cin>>n>>c;
        string str;
        cin>>str;
        deque<int> adj[30];
        int l = 0, r = 0, mx = 0, cnt = 0;
        while(r<n)
        {
            // cout<<"\n";
            // deb(r);
            // add
            if(str[r] == 'a')
            {
                adj[0].push_back(r);
            }
            else if(str[r] == 'b')
            {
                adj[1].push_back(r);
                int idx = std::lower_bound(adj[0].begin(),adj[0].end(),r)-adj[0].begin();--idx;
                // deb(idx);
                if(idx >=0 && idx < adj[0].size())
                {
                    cnt += 1+idx;
                }
            }
            // deb(cnt);
            if(cnt <= c)
            {
                mx = max(mx,r-l+1);
            }
            else
            {
                while(cnt > c)
                {
                    // remove
                    if(str[l] == 'a')
                    {
                        adj[0].pop_front();
                        int indx = std::upper_bound(adj[1].begin(),adj[1].end(),l)-adj[1].begin();
                        if(indx>=0 && indx<adj[1].size()) cnt -= ( (int)adj[1].size()-1 - indx+1);
                    }
                    else if(str[l] == 'b')
                    {
                        adj[1].pop_front();
                        int indx = std::lower_bound(adj[0].begin(),adj[0].end(),l)-adj[0].begin();
                        --indx;
                        if(indx>=0 && indx<adj[1].size()) cnt -= (indx+1);
                    }
                    l++;
                    if(cnt <= c)
                    {
                        mx = max(mx,r-l+1);
                    }
                }
            }
            r++;
        } 
        cout<<mx<<"\n";
    } 
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}