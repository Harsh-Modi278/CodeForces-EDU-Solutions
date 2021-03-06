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

int give(int p, int q, int r, int s)
{
    int v[] = {p, q, r, s};
    int diff = LLONG_MIN;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i!=j) diff = max(diff,v[i]-v[j]);
        }
    }
    return diff;
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
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
        // similar on IB: https://www.interviewbit.com/problems/array-3-pointers/
        int n1, n2, n3, n4;
        cin>>n1;
        int caps[n1];
        for(int i1=0;i1<n1;i1++) cin>>caps[i1];
        sort(caps,caps+n1);
        
        cin>>n2;
        int shirts[n2];
        for(int i1=0;i1<n2;i1++) cin>>shirts[i1];
        sort(shirts,shirts+n2);

        cin>>n3;
        int pants[n3];
        for(int i1=0;i1<n3;i1++) cin>>pants[i1];
        sort(pants,pants+n3);

        cin>>n4;
        int shoes[n4];
        for(int i1=0;i1<n4;i1++) cin>>shoes[i1];
        sort(shoes,shoes+n4);

        int i1 = 0, i2 = 0, i3 = 0, i4 = 0, mn = LLONG_MAX, a = -1, b = -1, c = -1, d = -1;
        while(i1<n1 && i2<n2 && i3<n3 && i4<n4)
        {
            // cout<<caps[i1]<<" "<<shirts[i2]<<" "<<pants[i3]<<" "<<shoes[i4]<<"\n";
            int diff = give(caps[i1],shirts[i2],pants[i3],shoes[i4]);
            // deb(diff);
            if(diff < mn)
            {
                mn = diff;
                a = i1; b = i2; c = i3; d = i4;
            }

            if(caps[i1]<=shirts[i2] && caps[i1]<=pants[i3] && caps[i1]<=shoes[i4])
            {
                i1++;
            }

            else if(shirts[i2]<=caps[i1] && shirts[i2]<=pants[i3] && shirts[i2]<=shoes[i4])
            {
                i2++;
            }

            else if(pants[i3]<=shirts[i2] && pants[i3]<=caps[i1] && pants[i3]<=shoes[i4])
            {
                i3++;
            }

            else if(shoes[i4]<=caps[i1] && shoes[i4]<=shirts[i2] && shoes[i4]<=pants[i3])
            {
                i4++;
            }
        }
        int diff = LLONG_MIN;
        diff = max(diff, abs(shirts[i2]-caps[i1]));
        diff = max(diff, abs(pants[i3]-shirts[i2]));
        diff = max(diff, abs(shoes[i4]-pants[i3]));
        // deb(diff);
        if(diff < mn)
        {
            mn = diff;
            a = i1; b = i2; c = i3; d = i4;
        }
        cout<<caps[a]<<" "<<shirts[b]<<" "<<pants[c]<<" "<<shoes[d]<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}