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

void print(deque<pair<int,pii> > & v)
{
    for(auto w:v)
    {
        cout<<w.first<<" "<<w.second.first<<" "<<w.second.second<<"\n";
    }
}

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
        // problem link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        int l = 0, r = 0, sum = 0, ans = 0;
        deque<pair<int,pii> > v, v1;
        v.push_back({1LL, {LLONG_MAX, LLONG_MIN}});
        v1.push_back({1LL, {LLONG_MAX, LLONG_MIN}});
        // ::cout<<"here"<<"\n";
        while(r<n)
        {
            // cout<<"\n";
            // ::cout<<l<<" "<<r<<"\n";
            // deb(l);deb(r);
            // deb(arr[r]);
            int sz = v.size();
            if(sz == 0)
            {
                v.push_back({arr[r], {arr[r], arr[r]}});
            }
            else
            {
                v.push_back({arr[r], { min(v.back().second.first, arr[r]) , max(v.back().second.second, arr[r])} });
            }

            // cout<<"v:"<<"\n";print(v);
            // cout<<"v1:"<<"\n";print(v1);

            sz = v.size();
            if(max(v1.back().second.second,v.back().second.second) - 
            min(v1.back().second.first, v.back().second.first) <= k)
            {
                // how many l for this r?
                // ::cout<<l<<" "<<r<<"\n";
                ans += (r-l+1);
            }
            else
            {
                // cout<<"here1"<<"\n";
                // cout<<"v:"<<"\n";print(v);
                
        
                // cout<<"v1:"<<"\n";print(v1);

                if(v1.size() == 1)
                {
                    // deb(v.size());
                    while(v.size() > 1)
                    {

                        v1.push_back({v.back().first, { min(v1.back().second.first,v.back().first),
                        max(v1.back().second.second,v.back().first) }});
                        
                        v.pop_back();
                    }
                }
                if(v1.size()>1 && max(v1.back().second.second,v.back().second.second) - 
            min(v1.back().second.first, v.back().second.first) <= k)
                    {
                        // ::cout<<l<<" "<<r<<"\n";
                        ans += (r-l+1);
                    }

                while(v1.size()>1 && max(v1.back().second.second,v.back().second.second) - 
        min(v1.back().second.first, v.back().second.first) > k)
                {
                    v1.pop_back();
                    l++;
                    // cout<<"v1:"<<"\n";print(v1);
                    if(v1.size() == 1)
                    {
                        // deb(v.size());
                        while(v.size() > 1)
                        {

                            v1.push_back({v.back().first, { min(v1.back().second.first,v.back().first),
                            max(v1.back().second.second,v.back().first) }});
                            
                            v.pop_back();
                        }
                    }
                    if(v1.size()>1 && max(v1.back().second.second,v.back().second.second) - 
            min(v1.back().second.first, v.back().second.first) <= k)
                    {
                        // ::cout<<l<<" "<<r<<"\n";
                        ans += (r-l+1);
                    }
                }
                
            }
            r++;
        }
        ::cout<<ans<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}