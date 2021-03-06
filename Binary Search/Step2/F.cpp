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

bool check(string& A, string& B) 
{
    // A = pat, B = text
    // A (- B
    int n = B.size(), m = A.size();
    int i = 0, j = 0;
    while(i<n && j<m)
    {
        if(B[i] == A[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return j>=m;
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
        string s1, s2, str;
        cin>>s1;
        cin>>s2;
        str = s1;
        int n = s1.size(), m = s2.size();
        int arr[n];
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        int low = 0, high = n, mid, ans = 0;// no.of character that can be deleted
        while(low<=high)
        {
            mid = (low+high)>>1;
            // deb(mid);
            str = s1;
            for(int i=0;i<mid;i++) str[arr[i]-1] = '-';
            string ss = "";
            // deb(str);
            for(int i=0;i<n;i++) 
            {
                if(str[i] != '-') ss += str[i];
            }
            // deb(ss);
            if(check(s2,ss))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            // cout<<"\n";
        }
        cout<<(ans)<<"\n";
    } 
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}