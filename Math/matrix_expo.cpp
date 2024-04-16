struct mat {
	ll a[3][3];
	mat() { mem(a, 0); }
	mat operator*(const mat &b) const {
    	    mat ret;
    	    rep(i, 3) rep(j, 3) rep(k, 3) ret.a[i][j] = add(ret.a[i][j], mult(a[i][k], b.a[k][j]));
    	    return ret; } };
mat power(mat a, ll b) {
	mat ret;
	rep(i, 3) ret.a[i][i] = 1;
	while (b) {
    	    if (b & 1) ret = ret * a;
    	    b >>= 1;
    	    a = a * a; }
	return ret; }
const int MOD = 998244353;
typedef vector<int> row;
typedef vector<row> matrix;
inline int add(const int &a, const int &b) {
  int c = a + b;
  if (c >= MOD) c -= MOD;
  return c; }
inline int mult(const int &a, const int &b) {
  return (long long)a * b % MOD; }
matrix operator+(const matrix &m1, const matrix &m2) {
  int r = m1.size();
  int c = m1.back().size();
  matrix ret(r, row(c));
  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
  	ret[i][j] = add(m1[i][j], m2[i][j]); } }
  return ret; }
matrix operator*(const matrix &m1, const int m2) {
  int r = m1.size();
  int c = m1.back().size();
  matrix ret(r, row(c));
  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
  	ret[i][j] = mult(m1[i][j], m2); } }
  return ret; }
matrix operator*(const matrix &m1, const matrix &m2) {
  int r = m1.size();
  int m = m1.back().size();
  int c = m2.back().size();
  matrix ret(r, row(c, 0));
  for (int i = 0; i < r; i++) {
	for (int k = 0; k < m; k++) {
  	for (int j = 0; j < c; j++) {
    	ret[i][j] = add(ret[i][j], mult(m1[i][k], m2[k][j]));}}}
  return ret;}
matrix one(int dim) {
  matrix ret(dim, row(dim, 0));
  for (int i = 0; i < dim; i++) {
	ret[i][i] = 1; }
  return ret; }
matrix operator^(const matrix &m, const int &e) {
  if (e == 0) return one(m.size());
  matrix sqrtm = m ^ (e / 2);
  matrix ret = sqrtm * sqrtm;
  if (e & 1) ret = ret * m;
  return ret; }
