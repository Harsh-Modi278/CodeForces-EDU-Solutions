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

int bs(vector<int> &arr,int key)
{
    int low = 0, high = arr.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
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
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i1=0;i1<n;i1++) cin>>arr[i1];
        for(int q=0;q<k;q++)
        {
            int x;
            cin>>x;
            int indx = bs(arr,x);
            cout<<(indx!=-1?"YES":"NO")<<"\n";
        }
    }
    return 0;
}