#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n = 5; // Example: 5 elements
    DSU dsu(n);

    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(3, 4);

    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(1): " << dsu.find(1) << endl;
    cout << "Find(2): " << dsu.find(2) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    cout << "Find(4): " << dsu.find(4) << endl;

    return 0;
}
