#include <bits/stdc++.h>

    #ifndef ONLINE_JUDGE
    #include "debug.cpp"
    #else
    #define debug(...)
    #endif

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl "\n"
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
constexpr double PI= acos(-1);
constexpr int INF=LLONG_MAX;

#define TimeShow(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define Time(i) \
for ( \
  auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
  blockTime.second; \
  TimeShow("#%d : %d ms\n", i, (int)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
  )
 
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
    Time(i) fun();
  }
  return 0;
}



