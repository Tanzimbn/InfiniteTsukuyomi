void solve(int l, int r){
    if(l == r)return;
    int mid = l + r >> 1;
    solve(l, mid);vector<LL> a, b;
    for(int i=l;i<=mid;i++){a.PB(A[i]);}
    for(int i = 0; i < B.size() && i <= r - l; i++)b.push_back(B[i]);
    vector<LL> temp = FFT::anyMod(a, b);
    for(int i = mid + 1; i <= r && i - l < temp.size(); i++){
        A[i] += temp[i - l];
        if(A[i] >= mod)A[i] -= mod;
    }
    solve(mid + 1, r);}