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
using namespace std;
typedef long long l1;
typedef long long unsigned int lu1;
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

int bs2(vector<int> &arr,int key)
{
    int low = 0, high = arr.size()-1, ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]<=key)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    return ans;
}

int bs1(vector<int> &arr,int key)
{
    int low = 0, high = arr.size()-1, ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>=key)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    return ans;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("timber_validation_input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    FIO;
    int t;
    t = 1;
    // cin>>t; 
    for(int tc=0;tc<t;tc++)
    {          
        int n,k;
        cin>>n;
        vector<int> arr(n);
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        sort(arr.begin(),arr.end());
        cin>>k;
        for(int q=0;q<k;q++)
        {
            int l, r;
            cin>>l>>r;
            int indx1 = bs1(arr,l);
            int indx2 = bs2(arr,r);
            if(indx1==-1 || indx2==-1) cout<<0<<" ";
            else
            {
                cout<<(indx2-indx1+1)<<" ";
            }
            
        }
        cout<<"\n";
    }
    return 0;
}