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
        // problem link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
        int n, s;
        cin>>n>>s;
        int arr[n];
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        int l = 0, r = 0, sum = 0, mn = 1e6;
        while(r<n)
        {
            sum += (int)arr[r];
            if(sum >= s)
            {
                // cout<<l<<" "<<r<<" "<<sum<<"\n";
                mn = min(mn,r-l+1);
                while(l<r && sum >= s)
                {
                    sum -= (int)arr[l];
                    l++;
                    if(sum >= s) mn = min(mn,r-l+1);
                }
                // cout<<l<<" "<<r<<" "<<sum<<"\n";
            }
            r++;
            // cout<<"\n";
        }
        while(l<r && sum >= s)
        {
            sum -= (int)arr[l];
            l++;
            if(sum >= s) mn = min(mn,r-l+1);
        }
        if(mn == 1e6) mn = -1;
        cout<<mn<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}