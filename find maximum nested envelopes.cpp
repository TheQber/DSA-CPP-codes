/*
 * Find Maximum Nested Envelopes (Russian Doll Problem)
 * 
 * This program finds the maximum number of envelopes that can be nested inside each other
 * using dynamic programming and graph traversal. It builds a parent graph where edges
 * represent which envelopes can contain others, then uses DFS with memoization to find
 * the longest nesting chain. Envelopes are sorted by width and height to optimize the
 * solution. Input consists of number of envelopes followed by width-height pairs.
 * Output displays the maximum number of nested envelopes possible.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Envelope {
    int w, h;
};

class Envelopes {
public:
    vector<Envelope> env;
    vector<vector<int>> parents;  // parents[i] = all envelopes that can contain i
    vector<int> memo;             // memo[i] = longest chain starting from i

    // Recursive DFS to find longest nesting depth starting from envelope i
    int dfs(int i) {
        if (memo[i] != -1) return memo[i];
        int best = 1; // the envelope itself
        for (int p : parents[i]) {
            best = max(best, 1 + dfs(p));
        }
        memo[i] = best;
        return best;
    }

    // Build the parent graph and find longest nesting chain
    int findLongestChain() {
        int n = env.size();
        parents.assign(n, {});
        memo.assign(n, -1);

        // Build edges (i -> j) where j can contain i
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (env[j].w > env[i].w && env[j].h > env[i].h)
                    parents[i].push_back(j);
            }
        }

        // Find longest path among all nodes
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dfs(i));
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Envelopes e;
    e.env.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> e.env[i].w >> e.env[i].h;

    // Sort by width asc, then height asc
    sort(e.env.begin(), e.env.end(), [](const Envelope &a, const Envelope &b) {
        if (a.w == b.w) return a.h < b.h;
        return a.w < b.w;
    });

    cout << e.findLongestChain() << endl;
    return 0;
}
