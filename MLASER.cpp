#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair 
#define f first 
#define s second 
#define pii pair <int,int>
#define int long long 

const int N = 102;

int MOD = 1e9+7;
int w,h,ans[N][N];//min mirrors needed
string adj[N];
int srcx,srcy,destx,desty;
int bfs(int x,int y){
    queue<pii> q;
    int i,j;
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            ans[i][j]=-2;
    ans[x][y] = -1;
    q.push(mp(x,y));
    while(!q.empty()){
        pii node = q.front();
        q.pop();
        int current = ans[node.f][node.s];
        for(i=node.f,j=node.s-1;j>=0;j--){
            if(adj[i][j]=='*') break;
            if(ans[i][j]==-2){
                ans[i][j] = current + 1;
                q.push(mp(i,j));
            }
        }
        for(i=node.f,j=node.s+1;j<w;j++){
            if(adj[i][j]=='*') break;
            if(ans[i][j]==-2){
                ans[i][j] = current + 1;
                q.push(mp(i,j));
            }
        }
        for(i=node.f-1,j=node.s;i>=0;i--){
            if(adj[i][j]=='*') break;
            if(ans[i][j]==-2){
                ans[i][j] = current + 1;
                q.push(mp(i,j));
            }
        }
        for(i=node.f+1,j=node.s;i<h;i++){
            if(adj[i][j]=='*') break;
            if(ans[i][j]==-2){
                ans[i][j] = current + 1;
                q.push(mp(i,j));
            }
        }
    }
    return ans[destx][desty];
}
int gcd(int a, int b){
	while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int mexp(int a, int b) {
    if (b == 0) return 1;
    int t = mexp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,c=0;
    cin >> w >> h;
    for(i=0;i<h;i++) cin >> adj[i];
    for(i=0;i<h;i++) 
        for(j=0;j<w;j++) 
            if(adj[i][j]=='C'){
                if(c==0){
                    c=1;
                    srcx=i,srcy=j;
                }
                else{
                    destx=i,desty=j;
                }
            }
    cout << bfs(srcx,srcy) << endl;
 	return 0;
}