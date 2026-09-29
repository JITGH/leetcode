class Solution {
    int memo[101][101][101];

    bool solve(int r, int c, int bal, vector<vector<char>>& grid, int m, int n) {
        bal += (grid[r][c] == '(' ? 1 : -1);

        // Cannot drop below zero
        if (bal < 0) return false;

        // Prune if there aren't enough cells left to close remaining open brackets
        int remaining = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining) return false;

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }

        bool res = false;
        if (r + 1 < m && solve(r + 1, c, bal, grid, m, n)) {
            res = true;
        }
        if (!res && c + 1 < n && solve(r, c + 1, bal, grid, m, n)) {
            res = true;
        }

        return memo[r][c][bal] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Total path length must be even, start must be '(', end must be ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, grid, m, n);
    }
};