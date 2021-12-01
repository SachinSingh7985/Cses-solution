#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
 
 
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
 
const int hell= 1000000007;
 
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
 
 
 int n;
 int f[1001][1001];
 
   int res(int i, int j)
   {
    int ans=0;
    for(int x=i;x>0;x=x-(x&(-x)))
      for(int y=j;y>0;y=y-(y&(-y)))
         ans+=f[x][y];
    return ans;
   }
   
   int result(int x1, int y1 ,int x2 ,int y2)
   {  
    
     int a_0=res(x2,y2);
     int a_1=res(x1-1,y1-1);
     int a_2=res(x2,y1-1);
     int a_3=res(x1-1,y2);
     int ans=a_0 + a_1 - a_2 -a_3;
     return ans;
   }
 
   void add(int i,int j ,int val)
   {
      for(int x=i;x<=n;x=x+(x&(-x)))
        for(int y=j;y<=n;y=y+(y&(-y)))
            f[x][y]+=val;
   }
 
int solve()
{
 
 int q;
 cin>>n>>q;
 
rep(i,0,n+1)
rep(j,0,n+1)f[i][j]=0;
int a[n+1][n+1];
 
 rep(i,1,n+1){
  rep(j,1,n+1)
  {
     char ch;
     cin>>ch;
     if(ch=='*')a[i][j]=1;
     else
      a[i][j]=0;
    if(a[i][j])
    add(i,j,a[i][j]);
  }
 
}
 
 
 rep(i,0,q)
 {
  int a_1;
  cin>>a_1;
 
  if(a_1==2)
  {
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  cout<<result(x1,y1,x2,y2)<<endl;
  }
  else
  {
   int x,y;
   cin>>x>>y;
   if(a[x][y])add(x,y,-1);
   else add(x,y,1);
   a[x][y]^=1;
  }
 
 }
 
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
  //  freopen("output.txt", "w", stdout);                                   
   
 
  clock_t time_req;
 
    // Without ung pow function
                                                                                                                   
 //cin>>t;
 
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
