class Solution {
public:
   bool binarySearchRow(vector<vector<int>>& matrix, int row, int target) {
        int left = 0, right = matrix[row].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    
    bool binarySearchColumn(vector<vector<int>>& matrix, int col, int target) {
        int top = 0, bottom = matrix.size() - 1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][col] == target) {
                return true;
            } else if (matrix[mid][col] < target) {
                top = mid + 1;
            } else {
                bottom = mid - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Iterate over the diagonals
        for (int i = 0; i < std::min(rows, cols); ++i) {
            // Perform binary search in the row and column starting from (i, i)
            if (binarySearchRow(matrix, i, target) || binarySearchColumn(matrix, i, target)) {
                return true;
            }
        }
        
        return false;
    }
};