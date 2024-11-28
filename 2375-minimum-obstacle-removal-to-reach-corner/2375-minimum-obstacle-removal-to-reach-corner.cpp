// class Solution {
// private:
//     // Directions for movement: right, left, down, up
//     vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();

//         vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

//         // Start from the top-left corner, accounting for its obstacle value
//         minObstacles[0][0] = grid[0][0];

//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
//             pq;

//         // Add the starting cell to the priority queue
//         pq.push({minObstacles[0][0], 0, 0});

//         while (!pq.empty()) {
//             // Process the cell with the fewest obstacles removed so far
//             vector<int> current = pq.top();
//             pq.pop();
//             int obstacles = current[0], row = current[1], col = current[2];

//             // If we've reached the bottom-right corner, return the result
//             if (row == m - 1 && col == n - 1) {
//                 return obstacles;
//             }

//             // Explore all four possible directions from the current cell
//             for (vector<int>& dir : directions) {
//                 int newRow = row + dir[0], newCol = col + dir[1];

//                 if (isValid(grid, newRow, newCol)) {
//                     // Calculate the obstacles removed if moving to the new cell
//                     int newObstacles = obstacles + grid[newRow][newCol];

//                     // Update if we've found a path with fewer obstacles to the
//                     // new cell
//                     if (newObstacles < minObstacles[newRow][newCol]) {
//                         minObstacles[newRow][newCol] = newObstacles;
//                         pq.push({newObstacles, newRow, newCol});
//                     }
//                 }
//             }
//         }

//         return minObstacles[m - 1][n - 1];
//     }

//     // Helper method to check if the cell is within the grid bounds
//     bool isValid(vector<vector<int>>& grid, int row, int col) {
//         return row >= 0 && col >= 0 && row < grid.size() &&
//                col < grid[0].size();
//     }
// };

//0-1 BFS
class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Distance matrix to store the minimum obstacles removed to reach each
        // cell
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = 0;

        deque<array<int, 3>> deque;
        deque.push_back({0, 0, 0});  // {obstacles, row, col}

        while (!deque.empty()) {
            auto current = deque.front();
            deque.pop_front();
            int obstacles = current[0], row = current[1], col = current[2];

            // Explore all four possible directions from the current cell
            for (auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        // If it's an obstacle, add 1 to obstacles and push to
                        // the back
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deque.push_back({obstacles + 1, newRow, newCol});
                    } else {
                        // If it's an empty cell, keep the obstacle count and
                        // push to the front
                        minObstacles[newRow][newCol] = obstacles;
                        deque.push_front({obstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

private:
    // Helper method to check if the cell is within the grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};