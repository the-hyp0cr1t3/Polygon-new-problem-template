#include "testlib.h"
#include <vector>
#include <numeric>
using namespace std;

const int Q = 2e5;
const int N = 1e6;
int vis[N];

void dfs(int v, vector<vector<int>>& g) {
    vis[v] = 1;
    for(auto& x: g[v])
        if(!vis[x]) dfs(x, g);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int t = inf.readInt(1, Q, "t");
    inf.readEoln();
    int sum_n = 0;
    
    for(int it = 1; it <= t; it++) {
        setTestCase(it);

        int n = inf.readInt(1, N, "n");
        inf.readEoln();
        sum_n += n;
        ensuref(sum_n <= N, "sum N limit exceeded");

        for(int j = 0; j < 2; j++) {
            int r = -1; vector<vector<int>> g(n);
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < n; i++) {
                if(i) inf.readSpace();
                int p = inf.readInt(-1, n, "pari");
                ensuref(p != i+1, "self loop");
                if(~p) g[--p].push_back(i);
                else {
                    ensuref(r == -1, "More than one root");
                    r = i;
                }
            }
            inf.readEoln();
            ensuref(~r, "No roots");
            dfs(r, g);
            ensuref(accumulate(vis, vis+n, 0) == n, "not connected");
        }
    }
    inf.readEof();
}
