#include "tsm.h"

void DP(int G[][30], int n, int start, vector<int> &path) {
    vector<vector<int>> dp(1 << n, vector<int>(n, 2147483647));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    dp[1 << start][start] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; ++v) {
                    if (!(mask & (1 << v)) && G[u][v] != 99999 && dp[mask][u] != 2147483647) {
                        int newCost = dp[mask][u] + G[u][v];
                        if (newCost < dp[mask | (1 << v)][v]) {
                            dp[mask | (1 << v)][v] = newCost;
                            parent[mask | (1 << v)][v] = u;
                        }
                    }
                }
            }
        }
    }

    int minCost = 2147483647, last = -1;
    for (int i = 0; i < n; ++i) {
        if (i != start && G[i][start] != 99999 && dp[(1 << n) - 1][i] != 2147483647) {
            int cost = dp[(1 << n) - 1][i] + G[i][start];
            if (cost <= minCost) {
                minCost = cost;
                last = i;
            }
        }
    }

    int mask = (1 << n) - 1, current = last;
    while (current != -1) {
        path.push_back(current);
        int temp = parent[mask][current];
        mask &= ~(1 << current);
        current = temp;
    }
    reverse(path.begin(), path.end());
}

string Traveling(int G[][30], int n, char startVertex) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] <= 0) G[i][j] = 99999;
        }
    }

    int start = startVertex - 'A';
    vector<int> path;
    DP(G, n, start, path);

    string kq;
    for (int i =0; i<path.size();i++) {
        kq += char('A' + path[i]);
        kq += " ";
    }
    kq += startVertex;
    return kq;
}
