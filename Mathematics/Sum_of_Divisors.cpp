
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
 
const int  hell=1e9+7;
 
 
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
 
 
int get(int r,int l)
{
  l--;
  r%=hell;
  l%=hell;
  int x=r*(r+1)/2-l*(l+1)/2;
  x+=hell*hell;
  return x%hell;
}
 
 
int solve()
{
   int n;
   cin>>n;
   vii a;
  for(int i=1;i*i<=n;i++)
  {
    a.pb({i,n/i});
    if(i==n/i)continue;
    a.pb({n/i,i});
  }
  sort(all(a));
 
int ans=n;
 
rep(i,1,a.size())
{
  int x=get(a[i].FF,a[i-1].FF+1);
  x*=a[i].SS;
  ans+=x;
  ans%=hell;
}
 
cout<<ans<<endl;
  
 return 0;
}
 
 
signed main()
{  int t=1;
 
 
 
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
 
 
  
    //freopen("input.txt", "r" , stdin);
   // freopen("output.txt", "w", stdout);                                   
   
  
 
  clock_t time_req;
 
    // Without ung pow function
          
 
                                                                                                                   
 //cin>>t;
 
     
   while(t--)
     {
      // cout<<"Case #"<<k<<":"<<endl;k++;
     //cout<<endl;
      solve();
       
     }
        exit(0);
 
         time_req = clock() - time_req;
    cout <<endl<< "Processor time taken is "
      << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
 
 
    return 0;
}
