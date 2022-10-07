class Solution {
public:
    int maximumInvitations(vector<int>& A) {
        int N = A.size(); // number of employees
        vector<int> m(N, -1); // m[i] = j means employee i's favorite person is employee j
        vector<vector<int>> r(N); // reverse mapping of m
        for (int i = 0; i < N; ++i) r[A[i]].push_back(i); // build reverse mapping of m
        function<int(int)> dfs = [&](int u) { // dfs to find the maximum number of employees that can be invited to the meeting
            if (m[u] != -1) return m[u]; 
            int ans = 0; 
            for (int v : r[u]) ans = max(ans, dfs(v)); // find the maximum number of employees that can be invited to the meeting if employee u is invited
            return m[u] = 1 + ans;
        };

        // find the longest path in the graph (the longest path is the maximum number of employees that can be invited to the meeting)
        int ans = 0, free = 0;
        for (int i = 0; i < N; ++i) {

            if (m[i] != -1) continue;

            if (A[A[i]] == i) { 
                m[i] = m[A[i]] = 0; // if employee i and employee A[i] are each other's favorite person, then they cannot be invited to the meeting
                int a = 0, b = 0;  // points to the two ends of the longest path in the graph
                for (int v : r[i]) { // find the two ends of the longest path in the graph
                    if (v == A[i]) continue; // skip the other end of the longest path in the graph
                    a = max(a, dfs(v)); // find the longest path in the graph
                }

                for (int v : r[A[i]]) { // find the two ends of the longest path in the graph
                    if (v == i) continue; // skip the other end of the longest path in the graph
                    b = max(b, dfs(v)); // find the longest path in the graph
                }

                free += a + b + 2; // the number of employees that can be invited to the meeting if employee i and employee A[i] are invited
            }
        }

        // handle the rest of the nodes 
        function<tuple<int, int, bool>(int)> dfs2 = [&](int u)->tuple<int, int, bool> {
            if (m[u] != -1) return {u, m[u], false}; // if employee u is already visited, return the longest path in the graph
            m[u] = 0; // mark employee u as visited
            auto [entryPoint, depth, cycleVisited] = dfs2(A[u]); // find the longest path in the graph
            if (cycleVisited) {
                return {entryPoint, depth, true}; // if employee u is in a cycle, return the longest path in the graph
            }
            m[u] = 1 + depth; // update the longest path in the graph
            return {entryPoint, m[u], u == entryPoint}; // if employee u is the entry point of the cycle, return the longest path in the graph
        };
        return max(ans, free); // return the maximum number of employees that can be invited to the meeting
    }
};
