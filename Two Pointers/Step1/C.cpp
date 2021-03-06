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
        // https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
        int n, m;
        cin>>n>>m;
        int arr[n], brr[m];
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        for(int i1=0;i1<m;i1++) cin>>brr[i1];
        int cnt = 0, i = 0;
        for(int j=0;j<m;    )
        {
            int cc = 1, cnt1 = 0, k = j+1;
            while(k<m && brr[k] == brr[j])
            {
                k++;
                cc++;
            }
            while(i<n && arr[i]<brr[j])
            {
                i++;
            }
            while(i<n && arr[i] == brr[j])
            {
                i++;
                cnt1++;
            }
            cnt += cc*cnt1;
            j = k;
        }
        cout<<cnt<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}