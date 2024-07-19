class Solution {
private:
    bool isRowMin(vector<vector<int>> matrix,int ele, int row, int cols){
        for(int i = 0; i< cols; i++){
            if(matrix[row][i] < ele)
                return false;
        }
        return true;
    }

    bool isColMax(vector<vector<int>> matrix,int ele, int rows, int col){
        for(int i = 0; i< rows; i++){
            if(matrix[i][col] > ele)
                return false;
        }
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1 && cols == 1){
            return matrix[0];
        }
        vector<int> ans;
        for(int i = 0; i< rows; i++){
            for(int j = 0; j< cols; j++){
                int ele = matrix[i][j];
                if(isRowMin(matrix, ele, i, cols) 
                  && isColMax(matrix, ele, rows, j))
                     ans.push_back(ele);
            }
        }
        return ans;
    }
};