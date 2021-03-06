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
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
        int n, p, sum = 0;
        cin>>n>>p;
        int arr[2*n];
        for(int i1=0;i1<n;i1++) 
        {
            cin>>arr[i1];
            sum += (int)arr[i1];
        }
        for(int i=n;i<2*n;i++) arr[i] = arr[i-n];
        int rem = p%sum;
        int l = 0, r = 0, sum1 = 0, cnt = LLONG_MAX, indx_start = -1;
   
        while(r<2*n)
        {
            sum1 += (int)arr[r];
            if(sum1 >= rem)
            {   
                if(r-l+1<cnt)
                {
                    cnt = r-l+1;
                    indx_start = l%n;
                }
                while(sum1 >= rem)
                {
                    sum1 -= (int)arr[l];
                    l++;
                    if(sum1 >= rem)
                    {
                        if(r-l+1<cnt)
                        {
                            cnt = r-l+1;
                            indx_start = l%n;
                        }
                    }
                }
            }
            // deb(cnt);
            r++;
        }
        while(l<r && sum1 >= rem)
        {
            sum1 -= (int)arr[l];
            l++;
            if(sum1 >= rem)
            {
                if(r-l+1<cnt)
                {
                    cnt = r-l+1;
                    indx_start = l%n;
                }
            }
        }

        cout<<(1+indx_start)<<" "<<(cnt + n*(int)(p/sum) )<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}