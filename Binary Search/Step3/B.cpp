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
        int n, k;
        cin>>n>>k;
        int arr[n], mx = 0, tot = 0;
        for(int i1=0;i1<n;i1++) 
        {
            cin>>arr[i1];
            mx = max(mx, arr[i1]);
            tot += arr[i1];
        }
        int low = mx, high = tot, ans = -1, mid;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            int s = mid;
            int segments = 0, sum = 0, mx = 0;
            bool g = true;
            for(int i=0;i<n;i++)
            {
                if(max(mx, sum + arr[i]) <= s)
                {
                    sum += arr[i];
                    mx = max(mx, sum);
                }
                else
                {
                    if(arr[i] > s)
                    {
                        g = false;
                        break;
                    }
                    ++segments;
                    sum = arr[i];
                    mx = arr[i];
                }
            }
            if(sum > 0)
            {
                if(mx > s)
                {
                    g = false;
                    break;
                }
                ++segments;
            }

            if(segments > k) g = false;
            if(g)
            {
                ans = mid;
                high = mid - 1;
            }   
            else
            {
                
                low = mid + 1;
            }
        }
        cout<<ans<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}