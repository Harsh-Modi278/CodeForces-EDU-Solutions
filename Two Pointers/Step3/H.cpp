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

int solve(int costs_a[], int n, int costs_b[], int m, int capacity, int a, int b)
{
    sort(costs_a,costs_a+n);reverse(costs_a,costs_a+n);
    sort(costs_b,costs_b+m);reverse(costs_b,costs_b+m);

    int i = 0, j = 0, wsum = 0, ans = 0, mx = 0;
    while(i<n)
    {
        wsum += a;
        ans += costs_a[i];
        if(wsum <= capacity)
        {
            mx = max(mx, ans);
        }
        else
        {
            break;
        }
        
        i++;
    }
    if(i >= n) i = n-1;
    while(j<m)
    {
        // cout<<"\n";
        // cout<<"\n";
        // deb(j);
        wsum += b;
        ans += costs_b[j];
        // deb(wsum);deb(ans); 
        if(wsum <= capacity)
        {
            mx = max(mx, ans);
        }
        else
        {
            int k = i;
            while(k>=0 && wsum > capacity)
            {
                ans -= costs_a[k];
                wsum -= a;
                k--;
                // deb(k);
                // deb(wsum);deb(ans);
                if(wsum <= capacity)
                {
                    // cout<<"hello"<<"\n";
                    mx = max(mx, ans);
                }
            }
            i = k;
        }
        j++;
    }
    return mx;
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
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H
        int n, m, capacity, a, b;
        cin>>n>>m>>capacity>>a>>b;
        int costs_a[n], costs_b[m];
        for(int i1=0;i1<n;i1++) cin>>costs_a[i1];
        for(int i1=0;i1<m;i1++) cin>>costs_b[i1];
        int ans1 = solve(costs_a, n, costs_b, m, capacity, a, b);
        int ans2 = solve(costs_b, m, costs_a, n, capacity, b, a);
        int ans = max(ans1,ans2);
        // cout<<ans1<<" "<<ans2<<"\n";
        cout<<ans<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}