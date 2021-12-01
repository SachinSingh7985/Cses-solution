#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
//#define int         long long
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
 
 
int sum(int a,int b )
{
   int ans=a-a/b; 
   return ans;
}
 
int n,m;
int N=2*100010;
vii a(N);
vi seg(4*N),lazy(4*N);
void build(ll cur,ll st,ll end)
{
  if(st==end)
  {
    seg[cur]=a[st].FF;
    return;
  }
  ll mid=(st+end)>>1;
  build(2*cur,st,mid);
  build(2*cur+1,mid+1,end);
  seg[cur]=max(seg[2*cur],seg[2*cur+1]);          /* 1-change */
}
 
void updaterange(ll cur,ll st,ll end,ll l,ll r,ll val)
{
  if(lazy[cur]!=0)                                    /* 2-change */
  {
    seg[cur]+=lazy[cur];          /* 3-change */
    if(st!=end)
    {
      lazy[2*cur]+=lazy[cur];            /* 4-change */
      lazy[2*cur+1]+=lazy[cur];                   /* 5-change */
    }
    lazy[cur]=0;                                    /* 6-change */
  }
  if(st>end||st>r||end<l) return;
  if(l<=st&&end<=r)
  {
    seg[cur]+=val;              /* 7-change */
    if(st!=end)
    {
      lazy[2*cur]+=val;                           /* 8-change */
      lazy[2*cur+1]+=val;                         /* 9-change */
    }
    return;
  }
  ll mid=(st+end)>>1;
  updaterange(2*cur,st,mid,l,r,val);
  updaterange(2*cur+1,mid+1,end,l,r,val);
  seg[cur]=max(seg[2*cur],seg[2*cur+1]);                  /* 10-change */
}
ll query(ll cur,ll st,ll end,ll l,ll r)
{
  if(st>end||st>r||end<l) return -hell;
  if(lazy[cur]!=0)
  {
    seg[cur]+=lazy[cur];                /* 11-change */
    if(st!=end)
    {
      lazy[2*cur]+=lazy[cur];                    /* 12-change */
      lazy[2*cur+1]+=lazy[cur];                  /* 13-change */
    }
    lazy[cur]=0;
  }
  if(st>=l&&end<=r) return seg[cur];
  ll mid=(st+end)>>1;
  ll ans1=query(2*cur,st,mid,l,r);
  ll ans2=query(2*cur+1,mid+1,end,l,r);
  return max(ans1,ans2);                                 /* 14-change */
}
 
 
int solve()
{  
    
 
    cin>>n;
 
    a.resize(n);
    vi aa(n);
    rep(i,0,n)
    {
      cin>>aa[i];
      a[i].SS=i;
      a[i].FF=i;
    }
    sort(all(a));
      
    build(1,0,n-1);
 
    rep(i,0,n)
    {
      int x;
      cin>>x;
      x--;
      int l=0,r=n-1,mid;
       bool bl=true;
      while(r-l>1)
      {
          mid=(l+r)>>1;
          int ans=query(1,0,n-1,l,mid);
          int ans1=query(1,0,n-1,mid+1,r);
         // cout<<i<<" "<<ans<<" "<<ans1<<endl;
          if(ans>=x)
          {
            r=mid;
          }
          else if(ans1>=x)
          {
            l=mid+1;
          }
          else
            break;
          
      }
            if(query(1,0,n-1,l,l)<x)l=r;
            
 
 
         
      cout<<aa[l]<<" ";
      if(bl)
      {
      //cout<<aa[l]<<" ";
      updaterange(1,0,n-1,l,n-1,-1);
      updaterange(1,0,n-1,l,l,-1000);
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
 
 
   
   //  freopen("input.txt", "r" , stdin);
    //freopen("output.txt", "w", stdout);                                   
    
 
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
