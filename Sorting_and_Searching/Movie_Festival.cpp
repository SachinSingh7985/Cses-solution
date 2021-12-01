        #pragma GCC optimize("Ofast")
        #pragma GCC optimize("unroll-loops")
        #pragma GCC target("sse2")
     
        #include <bits/stdc++.h>
        #include <vector> 
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/tree_policy.hpp>
        using namespace std;
     
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
        #define rep(i,a,b)  for(int i=a;i<b;i++)
         int hell=1000000007;
         ll mod=998244353;
 
 
 
         
        int solve(){ 
 
          
         int n;
         cin >> n;
         vii a(n);
         vi v;
         for(int i=0;i<n;i++){
          cin >> a[i].FF >> a[i].SS;
          v.pb(a[i].SS);
          v.pb(a[i].FF);
         }
         sort(all(v));
         v.resize(unique(all(v))-v.begin());
         sort(all(a));
         for(auto &x:a){
          x.FF=lower_bound(all(v),x.FF)-v.begin();
          x.SS=lower_bound(all(v),x.SS)-v.begin();
         }
 
         int dp[2*n+10]={0};
         for(int i=n-1;i>=0;i--){
          if(i<n-1)
          for(int j=a[i+1].FF;j>=a[i].FF;j--)dp[j]=max(dp[j],dp[j+1]);
          dp[a[i].FF]=max(dp[a[i].FF],dp[a[i].SS]+1);
         }  
 
         cout << dp[0] << endl;
 
         
 
 
 
 
        
         return 0;
            
            }
 
 
 
        signed main()
        {      
    
 
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r" , stdin);
        // freopen("output.txt", "w", stdout);                                  
        // #endif  
      
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0); 
     
        int t=1,k=1;                                                                                                                  
          // cin>>t;
 
       
       
        while(t--)
        {
         
         // cout<<"Case #"<<k++<<": ";
         solve();
         //cout<<endl;
        }
        return 0;
        } 
