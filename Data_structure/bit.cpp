struct Fenwick{
     int n;
     vector<int> fen;
     Fenwick(int n) {this->n=n;fen.assign(n+5,0);}
     int query(int pos){
        int ans=0;
        while(pos>=0){
            ans=ans+fen[pos];
            pos=(pos&(pos+1))-1;
        }return ans;}
     void update(int pos,int val){
        while(pos<=n){
           fen[pos]+=val;
           pos|=(pos+1);
        }}};
