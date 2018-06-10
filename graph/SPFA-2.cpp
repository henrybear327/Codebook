// https://ideone.com/s32IOI
#define x first
#define y second
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef pair<int ,long long > PIL;
int n,m;//點數、邊數
vector<PIL> g[MAXN];//圖
bool inq[MAXN];
long long d[MAXN];//答案
inline void SPFA(int from){
	for(int i=0;i<n;++i)
		random_shuffle(g[i].begin(),g[i].end());
	deque<int> q;
	for(int i=0;i<n;++i)d[i]=INF;
	q.push_front(from),inq[from]=1,d[from]=0;
	while(q.size()){
		int u=q.front();
		q.pop_front(),inq[u]=0;
		for(auto &e:g[u]){
			if(d[u]+e.y<d[e.x]){
				d[e.x]=d[u]+e.y;
				if(!inq[e.x]){
					if(q.size()&&d[e.x]<=d[q.front()]){
						q.push_front(e.x);
					}else q.push_back(e.x);
					inq[e.x]=1;
				}
			}
		}
	}
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	int u,v,w;
	while(m--){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,(long long)w});
	}
	int k;
	scanf("%d",&k);
	SPFA(k);
	for(int i=0;i<n;++i){
		if(i)putchar(' ');
		if(d[i]!=INF)printf("%lld",d[i]);
		else printf("INF");
	}
	puts("");
	return 0;
}
