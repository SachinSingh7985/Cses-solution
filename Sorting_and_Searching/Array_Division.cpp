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
 
    
     vi a;
     int n,k;
 
         bool check(int x){
          int sum = 0,cnt = 1;
          for(int i=0;i<n;i++){
            if(a[i]>x)return false;
            if(sum+a[i]<=x)sum+=a[i];
            else {cnt++;sum=a[i];}
          }
          if(cnt<=k)return true;
          return false;
         }
 
         
        int solve(){ 
 
     
       
         cin >> n >> k;
         for(int i=0;i<n;i++){
          int x;
          cin >> x;
          a.pb(x);
         }
         int l = 0,r = hell*hell;
 
         while(r-l>1){
          int mid = (r+l) >> 1;
          if(check(mid)){
            r = mid;
          }
          else l = mid;
         }
         if(check(r))return cout << r ,0;
         cout << l << endl;
 
 
 
 
 
        
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
         // cout<<endl;
        }
        return 0;
        }  
