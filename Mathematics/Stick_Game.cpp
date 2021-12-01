
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
 typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define int         long long
#define ll          long long
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
 
 
int sum(int l,int r)
{
  r%=hell;
  l%=hell;
  int ans=(r*(r+1))/2;
  ans-=(l*(l+1))/2;
  ans+=hell*hell;
  ans%=hell;
  return ans;
}
 
 
int solve()
{
  
int n,k;
cin>>n>>k;
int a[n+1]={0};
vi aa(k);
rep(i,0,k)cin>>aa[i];
sort(all(aa));
 
rep(i,1,n+1)
{ 
  int x=0;
  for(int l=0;l<k;l++)
  {
     if(i-aa[l]>=0)
     {
       if(a[i-aa[l]]==0)x=1;
     }
      else
        break;
  }
  a[i]=x;
}
 
rep(i,1,n+1)if(a[i])cout<<"W";else cout<<"L";
 
 return 0;
 
}
 
 
signed main()
{  int t=1;
 
//pri();
  
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
                                                                                                                   
 //cin>>t;
 
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
