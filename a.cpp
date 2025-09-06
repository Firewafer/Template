#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl "\n"
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
constexpr double PI= acos(-1);
constexpr int INF=LLONG_MAX;

/*********************************
# PBDS


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// change 'int' to any data type
// less_equal for multiset increasing order
// less for set increasing order
// greater_equal for multiset decreasing order
// greater for set decreasing order

// *a.find_by_order(k) // iterator to the k-th element
// a.order_of_key(k)  // number of items in a set that are strictly smaller than k

// lower_bound, upper_bound also work in pbds
// all functions are like set
***************************/

/*********************************
# Prime Factors


int const MAXN = (int)1e7 + 5;
vector<int> spf(MAXN + 1, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

***************************/

/*********************************
# Modular Division

  int mod(int a, int m){
    return ((a%m)+m) % m;
  }
  int modAdd(int a, int b, int m){
    return mod(mod(a,m) + mod(b,m), m);
  }
  int modSub(int a, int b, int m){
    return mod(mod(a,m) - mod(b,m) + m, m);
  }
  int modMul(int a, int b, int m){
    return mod(mod(a,m) * mod(b,m), m);
  }

// ## Binary Expo
int binExpoItrMod(int a, int b, int m){
  int ans = 1LL;
  while(b>0){
    if(b&1){
      ans = (ans*a) % m;
    }
    a = (a*a)%m;
    b >>= 1;
  }
  return ans;
}

int modInverse(int x, int m){
  return binExpoItrMod(x,m-2LL, m);

  // (b^-1 % m) = (b^(m-2)) % m
}

int modDivide(int a, int b, int m){
    return modMul(a,modInverse(b, m), m);
}


***************************/

/*********************************
# nCr, nPr, factorial

const int N = (int)2e5 + 5;
vector<int> fact(N);
// Call preCalc();
void precalc(){
  fact[0] = 1;
  for(int i=1;i<N;i++){
     fact[i]=modMul(fact[i-1LL],i, m);
  }
  
}
//All other function like, modular division (3)

int nCr(int n, int r, int m){
  if (r < 0 || r > n) return 0;
  return modDivide(fact[n],modMul(fact[r],fact[n-r], m), m);
}

int nPr(int n, int r, int m){
  if (r < 0 || r > n) return 0;
  return modDivide(fact[n],fact[n-r], m);
}


***************************/

/*********************************
# 5.  Extended Euclidean Algorithm 

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int x, y;
  int g = gcd(a, b, x, y); // return gcd and x, y




***************************/

/*********************************
# 5.  Extended Euclidean Algorithm 

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int x, y;
  int g = gcd(a, b, x, y); // return gcd and x, y




***************************/


/*********************************
# Seive

  const int _max = (int)1e5 + 5;
vector<bool> sei(_max);
void seive(){
    
    for(int i=2; i*i <= _max; i++){
      if(sei[i] ==  false){
        for(int j = i * i; j<= _max; j += i){
          sei[j] = true;
        }
      }
    }
}


***************************/

/*********************************
# DFS 2D

const int MAX = 1000; // Max grid size
int grid[MAX][MAX];
int vis[MAX][MAX];

bool possible(int x, int y, int n, int m){
    // n -> row // m -> column
    return (x<n && x>=0 && y<m && y>=0);
}

void dfs(int x,int y, int n, int m){
  // vis -> 0 -> not visited // vis -> 1 -> visited
  // grid -> 0 -> no path // grid -> 1 -> path
  if(!possible(x,y,n,m) || vis[x][y]!=0 || grid[x][y]==0) return; 
  vis[x][y]=1;
  int dx[]={0,0,1,-1}; // For LRUD :: can add more values for diagonal movement
  int dy[]={1,-1,0,0};
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
  for(int i=0;i<4;i++){
    int nx=x+dx[i],ny=y+dy[i];
    dfs(nx,ny,n,m);
  }
}



***************************/

/*********************************
# Range Bitwise AND

  int rangeBitwiseAnd(int left, int right) {
    for(int i = 0; i < 32; i++){
      if(left != right){
        left = (left >> 1);
        right = (right >> 1);
      }else{
        int val=  (left << i);
        return val;
      }
    }

    return 0;
}



***************************/

/*********************************
# Range Bitwise OR

int rangeBitwiseOr(int left, int right) {
    for(int i = 0; i < 32; i++){
      if(left != right){
        left = (left >> 1);
        right = (right >> 1);
      }else{
        int val=  (left << i);
        for(int j = 0; j < i; j++){
          val = val | (1 << j);
        }
        return val;
      }
    }

    return 0;
}


***************************/
/*********************************
# MEX

  int const MAX_N = (int)1e5 + 5;

// From
// https://cp-algorithms.com/sequences/mex.html
//O(n)
int mex(vector<int> const& A) {
    static bool used[MAX_N+1] = { 0 };

    // mark the given numbers
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = true;
    }

    // find the mex
    int result = 0;
    while (used[result])
        ++result;

    // clear the array again
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = false;
    }

    return result;
}


***************************/

/*********************************
# Merge overlap intervals

// Code from:
// https://www.geeksforgeeks.org/dsa/merging-intervals/
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}



***************************/




void fun(){
   
} //END

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("er.txt", "w", stderr);
  #endif
  int t; cin>>t;
  for(int i=1; i<=t; i++){
     fun();
  }
  return 0;
}



