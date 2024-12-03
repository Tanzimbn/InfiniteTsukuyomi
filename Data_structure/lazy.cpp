void build(int pos, int l, int r) {
lazy[pos] = 0; /* remaining */}
void lazy_update(int pos, int l, int r) {
	seg[pos] += (r - l + 1) * lazy[pos];
	if (l != r) {
    	lazy[2 * pos] += lazy[pos];
    	lazy[2 * pos + 1] += lazy[pos];}
	lazy[pos] = 0;}
void update(int pos, int l, int r, int x, int y, ll val) {
	if (lazy[pos] != 0) lazy_update(pos, l, r);
	if (l > y || x > r) return;
	if (l >= x && r <= y) {
lazy[pos] += val;lazy_update(pos, l, r);
return;}}
