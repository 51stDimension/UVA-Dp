
ll dp[50000][110];
ll get_min_diff(vector<ll> v,ll i,ll sum,ll total){
    if(i == v.size()){
        total -= sum;
        return abs(total-sum);
    } 
    if(dp[sum][i]!=-1) return dp[sum][i];

    ll opt1 = get_min_diff(v,i+1,sum+v[i],total);
    ll opt2 = get_min_diff(v,i+1,sum,total);

    return dp[sum][i] = min(opt1,opt2);

}

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    memset(dp,-1,sizeof(dp));
    ll total = 0;
    rep(i,0,n) {
        cin>>v[i];
        total += v[i];
    }

    ll diff = get_min_diff(v,0,0,total);
    cout<<diff<<endl;
}
  
