const int N = 2e5;
vector<int> edge[N+5], vec[N+5], color(N+5), sz(N+5), cnt(N+5);
void dfs_size(int u, int p){
	sz[u] = 1;
	for(auto v: edge[u]){
    	if(v != p){
        	dfs_size(v, u);
        	sz[u] += sz[v];
    	}}}
void dfs(int u, int p, bool keep){
	int mx = -1, bigchild = -1;
	for(auto v: edge[u]){
    	if(v != p && mx < sz[v]){
        	mx = sz[v];
        	bigchild = v;}}
	for(auto v: edge[u]){
    	if(v != p && v != bigchild){
        	dfs(v, u, 0);}}
	if(bigchild != -1){
    	dfs(bigchild, u, 1);
    	swap(vec[u], vec[bigchild]);}
	vec[u].push_back(u);
	cnt[color[u]]++;
	for(auto v: edge[u]){
    	if(v != p && v != bigchild){
        	for(auto x: vec[v]){
            	vec[u].push_back(x);
            	cnt[color[x]]++;
        	}}}
	// ans area of a subtree...
	if(keep == 0){
    	for(auto v: vec[u]){
        	cnt[color[v]]--;}}}
