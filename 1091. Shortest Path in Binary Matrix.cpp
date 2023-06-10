class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; // Check if the start or end cell is blocked
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int currRow = curr.first;
            int currCol = curr.second;

            // Check if reached the bottom-right cell
            if (currRow == n - 1 && currCol == n - 1) {
                return dist[currRow][currCol];
            }

            for (int i = 0; i < 8; i++) {
                int newRow = currRow + dr[i];
                int newCol = currCol + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 &&  dist[newRow][newCol] == -1) {
                    q.push({newRow, newCol});
                    dist[newRow][newCol] = dist[currRow][currCol] + 1;
                }
            }
        }

        return -1; // No clear path found
    }
};
