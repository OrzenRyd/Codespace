#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define mkp make_pair
#define pb push_back
#define P pair<int,int>
#define _ 0
const int N=1e5+10,mod=1e9+7,MOD=1e9+123,inf=1e18;
int T=1,n;
struct node{
    int mat[4][4];
    node(){
        memset(mat,0,sizeof(mat));
    }
};
node operator *(const node &x,const node &y){
    node z;
    for(int k=1;k<=3;k++){
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                z.mat[i][j]=(z.mat[i][j]+x.mat[i][k]*y.mat[k][j]%mod)%mod;
            }
        }
    }
    return z;
}
void solve(){
    cin>>n;
    node a,b,ans;
    ans.mat[1][1]=ans.mat[2][2]=ans.mat[3][3]=1;
    a.mat[1][1]=a.mat[2][1]=a.mat[3][1]=1;
    b.mat[1][1]=b.mat[1][3]=b.mat[2][1]=b.mat[3][2]=1;
    if(n<=3){
        cout<<1<<endl;
        return ;
    }
    n-=3;
    while(n){
        if(n&1) ans=ans*b;
        n>>=1;
        b=b*b;
    }
    ans=ans*a;
    cout<<ans.mat[1][1]<<endl;
}
signed main(){
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    // ios::sync_with_stdio(false),cin.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
    return ~~(0^_^0);
}