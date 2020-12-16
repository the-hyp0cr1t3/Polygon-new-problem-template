#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<pair<int, int>> get_edges_random(int n);
vector<pair<int, int>> get_edges_kary(int n, int k);

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = atoi(argv[1]);
    const int n_min = atoi(argv[2]);
    const int n_max = atoi(argv[3]);

    cout << t << endl;
    while(t--) {
        int n = rnd.next(n_min, n_max);
        auto edges = get_edges_random(n);
        for(auto [u, v]: edges)
            cout << u << ' ' << v << endl;
    }
}

vector<pair<int, int>> get_edges_random(int n) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end());

    vector<int> p(n);
    int elongation = rnd.next(1, n);
    for(int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, elongation);

    vector<pair<int, int>> edges; edges.reserve(n-1);
    for(int i = 1; i < n; i++)
        if(rnd.next(2)) edges.emplace_back(perm[i]+1, perm[p[i]]+1);
        else edges.emplace_back(perm[p[i]]+1, perm[i]+1);
    shuffle(edges.begin(), edges.end());
    return edges;
}

// k = 1 for chain, k = n-1 for star
vector<pair<int, int>> get_edges_kary(int n, int k) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end());

    vector<pair<int, int>> edges; edges.reserve(n-1);
    for(int i = 0, j = 1; j < n; i++, j+=k)
        for(int id = j; id < min(n, j+k); id++)
            if(rnd.next(2)) edges.emplace_back(perm[i], perm[id]);
            else edges.emplace_back(perm[id], perm[i]);
    shuffle(edges.begin(), edges.end());
    return edges;
}
