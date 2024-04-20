string s;
  cin >> s;
  n = s.size();
  vector<int> d1(n);  // maximum odd length palindrome centered at i
  // here d1[i]=the palindrome has d1[i]-1 right characters from i
  // e.g. for aba, d1[1]=2;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  vector<int> d2(n);  // maximum even length palindrome centered at i
  // here d2[i]=the palindrome has d2[i]-1 right characters from i
  // e.g. for abba, d2[2]=2;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
int get(int l, int r) {
  return r * (r + 1) / 2 - (l - 1) * l / 2;
}
wavelet_tree oddl, oddr;
int odd(int l, int r) {
  int m = (l + r) / 2;
  int c = 1 - l;
  int less_ = oddl.LTE(l, m, c);
  int ansl = get(l, m) + oddl.sum(l, m, c) + (m - l + 1 - less_) * c;
  c = 1 + r;
  less_ = oddr.LTE(m + 1, r, c);
  int ansr = -get(m + 1, r) + oddr.sum(m + 1, r, c) + (r - m - less_) * c;
  return ansl + ansr;
}
wavelet_tree evenl, evenr;
int even(int l, int r) {
  int m = (l + r) / 2;
  int c = -l;
  int less_ = evenl.LTE(l, m, c);
  int ansl = get(l, m) + evenl.sum(l, m, c) + (m - l + 1 - less_) * c;
  c = 1 + r;
  less_ = evenr.LTE(m + 1, r, c);
  int ansr = -get(m + 1, r) + evenr.sum(m + 1, r, c) + (r - m - less_) * c;
  return ansl + ansr;
}
int a[N], b[N], c[N], d[N];
for(i = 1; i <= n; i++) a[i] = d1[i - 1] - i;
  oddl.init(a + 1, a + n + 1, -MAXV, MAXV);
  for(i = 1; i <= n; i++) b[i] = d1[i - 1] + i;
  oddr.init(b + 1, b + n + 1, -MAXV, MAXV);
  for(i = 1; i <= n; i++) c[i] = d2[i - 1] - i;
  evenl.init(c + 1, c + n + 1, -MAXV, MAXV);
  for(i = 1; i <= n; i++) d[i] = d2[i - 1] + i;
  evenr.init(d + 1, d + n + 1, -MAXV, MAXV);
