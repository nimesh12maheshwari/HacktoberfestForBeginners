#include <bits/stdc++.h>
using namespace std;
#define fastt ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define pb push_back
#define fi first
#define se second
 
 
int main() {
    fastt;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(2*n);
        int i,j,k;
        int count=0,cl=0,cr=0;
        for(i=0;i<2*n;i++){
            cin>>ar[i];
            if(ar[i]==1){count++;
            if(i<n)cl++;
            else cr++;
            }
            else{
                count--;
                if(i<n)cl--;
                else cr--;
            }
        }
        if(!count){cout<<0<<endl;continue;}
        unordered_map<int,int> mp;
        int c=0;
        mp[0]=0;
        for(i=n;i<2*n;i++){
            if(ar[i]==1){
                c++;
            }
            else{c--;}
            if(mp.find(c)==mp.end()){mp[c]=i-n+1;}
        }
        int mi=2*n;c=0;
        //count-=cl;
        if(mp.find(count)!=mp.end())mi=mp[count];
        for(i=n-1;i>=0;i--){
            c=0;
            if(ar[i]==1)c++;
            else c--;
            count-=c;
            if(mp.find(count)!=mp.end()){
                mi=min(mi,n-i+mp[count]);
            }
        }
        cout<<mi<<endl;
    }
    return 0;
}