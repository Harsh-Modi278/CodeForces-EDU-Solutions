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
    // FIO;
    int t;
    t = 1;
    // cin>>t; 
    for (int tc=0;tc<t;tc++) 
    { 
        int n, d;
        cin>>n>>d;
        int arr[n+1], pre[n+1];
        ld v[n+1];
        pair<ld,int> suffmx[n+1];
        for(int i1=1;i1<=n;i1++) cin>>arr[i1];
        arr[0] = 0;
        pre[0] = arr[0];
        pre[1] = arr[1];
        for(int i=2;i<=n;i++) pre[i] = pre[i-1] + arr[i];
        
        ld low = (ld)0, high = (ld)1e9, ans = -1, mid; //max(sum[l:r]/(r-l+1))
        int s = -1, e = -1;
        for(int c=1;c<=200;c++)
        {
            mid = (ld)low + (ld)(high - low)/(ld)2.00;
            ld x = mid;//avg
            // deb(x);
            // check if this avg is possible?
            for(int i=0;i<=n;i++) v[i] = pre[i] - x*(ld)i;
            suffmx[n] = {(ld)v[n], n};
            for(int i=n-1;i>=0;i--)
            {
                if(suffmx[i+1].first > v[i])
                {
                    suffmx[i] = suffmx[i+1];
                }
                else
                {
                    suffmx[i].first = v[i];
                    suffmx[i].second = i;
                }
                
            }

            // if(x == 6)
            // {
            //     for(int i=0;i<=n;i++) cout<<v[i]<<" ";
            //     cout<<"\n";

            //     for(int i=0;i<=n;i++) cout<<suffmx[i]<<" ";
            //     cout<<"\n";
            // }

            bool g = false;
            for(int i=1;i<=n;i++)
            {
                if(d+i-1<=n && (ld)v[i-1] <= (ld)suffmx[d+i-1].first)
                {
                    g = true;
                    s = i;
                    e = suffmx[d+i-1].second;
                    break;
                }
            }
            // deb(g);
            // cout<<s<<" "<<e<<"\n";
            if(g)
            {
                ans = mid;
                low = mid;
            }
            else
            {
                high = mid;
            }
            
        }
        cout<<(s)<<" "<<(e)<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}