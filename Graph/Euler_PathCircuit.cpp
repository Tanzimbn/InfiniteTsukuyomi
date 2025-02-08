/* conditins :
all edges should be in same connected component
#directed graph:
euler path: for all-> indeg=outdeg || 1 node-> (indeg-outdeg=1) and one node-> (outdeg-indeg=1) and others-> in=out
euler circuit: for all -> indeg = outdeg
#undirected graph:
euler path: all degrees are even or exactly 2 of them are odd
euler circuit: all degrees are even */
vector<pii> g[N];//nxtNode-EdgeNum
vector<int> ans;
int done[N], vis[M];
void dfs(int u) {
  while (done[u] < g[u].size()) {
    auto e = g[u][done[u]++];
    if (vis[e.second]) continue;
    vis[e.second] = 1;
    dfs(e.first);
  }
  ans.push_back(u);
}
int solve(int n) {
// check conditions, return 0 if dont exist
/* for dirGraph root: if any node (outdeg != indeg) -> node with outdeg > indeg  
 else any node with outdeg >= 1 */
/* for undirGraph root: if all even deg -> any with deg>=1
else node with deg odd */
  if (root == 0) return 1; //empty graph
  dfs(root);
  if (ans.size() != M + 1) return 0; //connectivity
  reverse(ans.begin(), ans.end());
  return 1;
}
