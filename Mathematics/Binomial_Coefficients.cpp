#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
 typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define ll          long long
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define mp          make_pair
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
//#define hell          1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
// mp::cpp_int
 
const int hell=1000000007;
 
int a[1000010]={0};
 
int power(int a,int b)
{
  if(b==0)return 1;
   int t=power(a,b/2);
   t*=t;
   t%=hell;
   if(b&1)t*=a;
   t%=hell;
   return t;
}
 
int inverse(int a)
{
  return power(a,hell-2);
}
 
void pri()
{
   a[0]=1;
   rep(i,1,1000010)
   {
    a[i]=(i*a[i-1])%hell;
   }
}
 
 
int solve()
{
  
int n,r;
cin>>n>>r;
 
int ans=a[n];
int y=a[n-r]*a[r];
y%=hell;
y=inverse(y);
ans*=y;
ans%=hell;
cout<<ans<<endl;
 
 
 return 0;
 
}
 
 
signed main()
{  int t=1;
 
pri();
  
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
 
 
  /*  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);                                   
    #endif
  */
 
  clock_t time_req;
 
    // Without ung pow function
                                                                                                                   
 cin>>t;
 
    int k=1;
     
   while(t--)
     {
      // cout<<"Case #"<<k<<":"<<endl;k++;
     // cout<<endl;
      solve();
     }
        exit(0);
 
         time_req = clock() - time_req;
    cout <<endl<< "Processor time taken is "
      << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
 
 
    return 0;
}
