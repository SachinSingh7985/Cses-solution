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
 
 
class matrix
{
  public:
    ll n;
    vector<vi> val;
    matrix(ll n=2);
    matrix operator+(const matrix&) const;
    matrix operator-(const matrix&) const;
    matrix operator*(const matrix&) const;
    matrix& operator=(const matrix& b)
      {
          if(this!=&b)
          {
              val = b.val;
              n = b.n;
          }
          return *this;
      } 
    void set(ll x)
    {
      rep(i,0,n)
      rep(j,0,n)
      val[i][j]=x;
    }
    void print()
    {
      rep(i,0,n)
      {
        rep(j,0,n)
          cout<<val[i][j]<<" ";
        cout<<endl;
      }
    }
};
 
matrix::matrix(ll x)
{
  n=x;
  val.resize(x);
  rep(i,0,x)
  val[i].resize(x);
}
 
matrix matrix::operator+ (const matrix& b) const
{
  class matrix ans;
  assert(this->n==b.n);
  rep(i,0,b.n)
    rep(j,0,b.n)
      ans.val[i][j]=this->val[i][j]+b.val[i][j];
  return ans;
}
 
matrix matrix::operator- (const matrix& b) const
{
  class matrix ans;
  assert(this->n==b.n);
  rep(i,0,b.n)
    rep(j,0,b.n)
      ans.val[i][j]=this->val[i][j]-b.val[i][j];
  return ans;
}
 
 
matrix matrix::operator* (const matrix& b) const
{
  class matrix r;
  assert(this->n==b.n);
  for(ll i=0;i<this->n;i++)
    for(ll j=0;j<this->n;j++)
    {
      ll res=0;
      for(ll k=0;k<b.n;k++)
        {res += this->val[i][k]*b.val[k][j];res%=hell;}
 
      r.val[i][j] = res;
    }
  return r;      
}
 
 
class matrix matpow(class matrix a, ll n)
{
  if(n==0)
  {
    matrix ans(2);
    ans.set(0);
    ans.val[0][0]=1;
    ans.val[1][1]=1;
    return ans;
  }
  if(n==1)
    return a;
  class matrix x = matpow(a,n/2);
  class matrix r = x*x;
  if(n%2==1)
    r=r*a;
  return r;      
}
 
int solve()
{
   
 int n;
 cin>>n;
if(n==0){
  cout<<0;
  return 0;
}
if(n==1)
{
  cout<<1;
  return 0;
}
 
 vector<vi> v={{1,1},{1,0}};
 matrix m(2);
 m.val=v;
 m=matpow(m,n-1);
 cout<<(m.val[0][0])%hell<<endl;
 
 
 
 
 return 0;
 
}
 
 
signed main()
{  int t=1;
 
//pri();
  
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
 
 
 
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
