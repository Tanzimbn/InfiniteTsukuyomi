void dfs_sz(int u , int p = 0){
	sub[u] = 1 , par[u] = p;
	dep[u] = (p == 0) ? 0 : dep[p] + 1;
	int mxv = -1;
	for(auto &x : adj[u]){
    	if(x == p) continue;
    	dfs_sz(x , u);
    	sub[u] += sub[x];
    	if(sub[x] > mxv){
        	mxv = sub[x];
        	swap(x , adj[u][0]);
    	}
	}
}
int head[N] , st[N] , en[N] , clk;
int dfsarr[N];
void dfs_hld(int u , int p = 0){
	st[u] = ++clk;
	// cout << u << ' ' << p << ' ' << head[p] << endl;
	if(p == 0) head[u] = u;
	else if(adj[p][0] == u) head[u] = head[p];
	else head[u] = u;
	for(auto &x : adj[u]){
    	if(x == p) continue;
    	dfs_hld(x , u);
	}
	en[u] = clk;
}
int lca(int a , int b){
	while(head[a] != head[b]){
    	if(dep[head[a]] > dep[head[b]]) swap(a , b);
    	b = par[head[b]];
	}
	if(dep[a] > dep[b]) swap(a , b);
	return a;
}
int nx;
ll path_process(int a , int b , bool excl = false){
	ll ret = 0;
	while(head[a] != head[b]){
    	// cout << a << ' ' << b << ' ' << head[a] << ' ' << head[b] << ' ' << dep[head[a]] << ' ' << dep[head[b]] << endl;
    	if(dep[head[a]] > dep[head[b]]) swap(a , b);
    	// do range query on the part
    	ret += segt.query(1 , 1 , nx , st[head[b]] , st[b]);
    	// [ st[head[b]] , st[b]]
    	b = par[head[b]];
	}
	if(dep[a] > dep[b]) swap(a , b);
	// do range query on the part
	ret += segt.query(1 , 1 , nx , st[a] + excl , st[b]);
	// [ st[a] + excl , st[b]]
	// here if excl is true it will exclude the lca of main query a and b
	return ret
;}
