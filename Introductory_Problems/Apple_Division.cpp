#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
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
 
 
 int power(int a,int b)
 {
  if(b==0)return 1LL;
  if(b==1)return a;
  int t=power(a,b/2);
  t*=t;
  t%=hell;
  if(b&1)return (t*a)%hell;
  else return t;
 }
 
 int inverse(int a)
 {
    return power(a,hell-2);
 }
 
int pw(int a,int b)
{
  int x=a;
  rep(i,1,b){a=a*x;
    a%=10000000000LL;}
  return a;
}
 
int gcd(int a,int b)
{   
  
  if(b==0)return a;
  return gcd(b-a%b,a%b);
}
 
bool cmp(pii a,pii b)
{
  return a.SS<b.SS;
}
 
 int sum=0;
 vi a;
 int n;
 int mn=hell*10LL;
 
 int dfs(int pos, int val, int num)
 {   
  //cout<<num<<endl;
 
 //  if(num==n)return 0;
  for(int i=pos;i<n;i++)
  { 
    //cout<<val+a[i]<<endl;
    dfs(i+1,val+a[i],num+1);
    mn=min(mn,abs(sum-val-a[i]-val-a[i]));
  }
  return 0;
 }
 
int solve()
{  
  
//int n;
cin>>n;
//vi a;
rep(i,0,n)
{
  int x;
  cin>>x;
  a.pb(x);
  sum+=x;
}
//sort(all(a));
//reverse(all(a));
for(int i=0;i<n;i++)
dfs(i,0,1);
 
cout<<mn;
 
return 0;
 
}
 
 
signed main()
{  int t=1;
//pri();
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
 
 
    // freopen("input.txt", "r" , stdin);
   // freopen("output.txt", "w", stdout);                                   
 
 
  clock_t time_req;
 
    // Without ung pow function
                                                                                                                   
// cin>>t;
 
    int k=1;
     
   while(t--)
     {
      //cout<<"Case #"<<k<<":"<<" ";k++;
      solve();
     }
        exit(0);
 
         time_req = clock() - time_req;
    cout <<endl<< "Processor time taken is "
      << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
 
 
    return 0;
} 
