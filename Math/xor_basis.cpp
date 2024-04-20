const int N = 3e5 + 9;
struct Basis {
  vector<int> a;
  void insert(int x) {
	for (auto &i: a) x = min(x, x ^ i);
	if (!x) return;
	for (auto &i: a) if ((i ^ x) < i) i ^= x;
	a.push_back(x);
	sort(a.begin(), a.end()); }
  bool can(int x) {
	for (auto &i: a) x = min(x, x ^ i);
	return !x; }
  int maxxor(int x = 0) {
	for (auto &i: a) x = max(x, x ^ i);
	return x; }
  int minxor(int x = 0) {
	for (auto &i: a) x = min(x, x ^ i);
	return x; }
  int kth(int k) { // 1st is 0
	int sz = (int)a.size();
	if (k > (1LL << sz)) return -1;
	k--; int ans = 0;
	for (int i = 0; i < sz; i++) if (k >> i & 1) ans ^= a[i];
	return ans; }
}t;
int ty, k; cin >> ty >> k;
if (ty == 1) t.insert(k);
else cout << t.kth(k) << '\n';
