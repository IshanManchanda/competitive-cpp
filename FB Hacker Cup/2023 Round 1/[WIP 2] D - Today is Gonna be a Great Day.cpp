#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007
int power(int x, int y, int p){
    int res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}



void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    int len = (int) sqrt(n + .0) + 1;
    vector<int> mx(len, 0), mx1(len, 0);
    vector<int> flip(len, 0);
    while(n!=len*len){
        v.push_back(0);
        n++;
    }
    for(int i=0; i<n; i++){
        mx[i/len] = max(mx[i/len], v[i]);
        mx1[i/len] = max(mx1[i/len], MOD-v[i]);
    }
    int q;
    cin>>q;
    int ans = 0;
    for(int i1=0; i1<q; i1++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r){
            for (int i=l; i<=r; ++i){
                v[i] = MOD - v[i];
            }
            mx[c_l] = 0;
            mx1[c_l] = 0;
            for(int i=c_l*len; i<(c_l+1)*len; i++){
                mx[c_l] = max(mx[c_l], v[i]);
                mx1[c_l] = max(mx1[c_l], MOD-v[i]);
            }
        }
        else{
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i){
                v[i] = MOD - v[i];
            }
            mx[c_l] = 0;
            mx1[c_l] = 0;
            for(int i=c_l*len; i<(c_l+1)*len; i++){
                mx[c_l] = max(mx[c_l], v[i]);
                mx1[c_l] = max(mx1[c_l], MOD-v[i]);
            }
            for (int i=c_l+1; i<=c_r-1; ++i){
                flip[i] ^= 1;
            }
            for (int i=c_r*len; i<=r; ++i){
                v[i] = MOD - v[i];
            }
            mx[c_r] = 0;
            mx1[c_r] = 0;
            for(int i=c_r*len; i<(c_r+1)*len; i++){
                mx[c_r] = max(mx[c_r], v[i]);
                mx1[c_r] = max(mx1[c_r], MOD-v[i]);
            }
        }
        int block = 0, val = 0;
        for(int i=0; i<len; i++){
            if(flip[i]){
                if(mx1[i]>val){
                    block = i;
                    val = mx1[i];
                }
            }
            else{
                if(mx[i]>val){
                    block = i;
                    val = mx[i];
                }
            }
        }
        int idx = -1;
        for(int i=block*len; i<min((block+1)*len, n); i++){
            if(flip[block]){
                if((MOD-v[i])==val){
                    idx = i;
                    break;
                }
            }
            else{
                if(v[i]==val){
                    idx = i;
                    break;
                }
            }
        }
        ans += idx+1;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    FILE_IN
    FILE_OUT
    int t=1, tc = 1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();
    }
    return 0;
}
