vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
     vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
        if(classes==n)break;//jodi logn iteration er aghei sort hoye jay
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sortedShift = sort_cyclic_shifts(s);
    sortedShift.erase(sortedShift.begin());
    return sortedShift;
}
//longest common prefix of string suffix
vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;}
// Here We need to build sparse table of lcp array and write query function
int get_lcp(int i, int j) {// lcp of suffix starting from i and j
    if (i == j) return n - i;
    int l = rank[i], r = rank[j];
    if (l > r) swap(l, r);
    return query(l, r - 1);}
  int lower_bound(string &t) {
    int l = 0, r = n - 1, k = t.size(), ans = n;
    while (l <= r) {
      int mid = l + r >> 1;
      if (s.substr(sa[mid], min(n - sa[mid], k)) >= t) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    return ans;
  }
  int upper_bound(string &t) {
    int l = 0, r = n - 1, k = t.size(), ans = n;
    while (l <= r) {
      int mid = l + r >> 1;
      if (s.substr(sa[mid], min(n - sa[mid], k)) > t) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    return ans; }
  // occurrences of s[p, ..., p + len - 1]
  pair<int, int> find_occurrence(int p, int len) {
    p = rank[p];
    pair<int, int> ans = {p, p};
    int l = 0, r = p - 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(mid, p - 1) >= len) ans.first = mid, r = mid - 1;
      else l = mid + 1;
    }
    l = p + 1, r = n - 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(p, mid - 1) >= len) ans.second = mid, l = mid + 1;
      else r = mid - 1;
    }
    return ans;
  }