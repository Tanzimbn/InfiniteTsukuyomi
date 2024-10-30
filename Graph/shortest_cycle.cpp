#define N 100200
vector<int> gr[N];
void Add_edge(int x, int y)
{gr[x].PB(y);gr[y].PB(x);}
int shortest_cycle(int n){
    int ans = INT_MAX;
for (int i = 0; i < n; i++) {
    vector<int> dist(n,(int)(1e9));
    vector<int> par(n, -1);
    dist[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int it : gr[x]) {
            if (dist[it] == (int)(1e9)) {
                dist[it] = 1 + dist[x];
                par[it] = x;
                q.push(it);
            }
            else if(par[x]!=it & par[it]!= x)
            ans=min(ans,dist[x]+dist[it]+1);
        }
    }
}
if(ans == INT_MAX)return -1;
else return ans;
}