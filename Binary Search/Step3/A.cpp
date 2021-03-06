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
        int n;
        cin>>n;
        int x[n], v[n];
        for(int i1=0;i1<n;i1++) cin>>x[i1]>>v[i1];
        // for(int a = -20;a<=20;a++)
        // {
            // ld tt = 0;
            // for(int i=0;i<n;i++)
            // {
            //     tt = max(tt, (ld)abs(x[i]-a)/(ld)v[i]);
            // }
        //     cout<<a<<" "<<tt<<"\n";
        // }
        ld low = -1e9, high = 1e9, ans = (ld)1e9, mid;
        for(int i1=1;i1<=200;i1++)
        {
            mid = (ld)(low+high)/(ld)2.00;
            ld a = mid, a1 = mid + 1e-6;
            ld tt = 0, tt1 = 0;
            for(int i=0;i<n;i++)
            {
                tt = max(tt, (ld)abs(x[i]-a)/(ld)v[i]);
            }
            for(int i=0;i<n;i++)
            {
                tt1 = max(tt1, (ld)abs(x[i]-a1)/(ld)v[i]);
            }

            if( tt > tt1)
            {
                ans = min(ans, tt1);
                low = mid;
            }
            else
            {
                ans = min(ans, tt);
                high = mid;
            }
        }
        cout<<fixed<<setprecision(12)<<ans<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}