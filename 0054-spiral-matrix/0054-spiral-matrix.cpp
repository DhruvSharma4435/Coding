class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;

        int startRow = 0, startCol = 0;
        int endRow = row - 1, endCol = col -1;
        int count = 0;
        vector<int> ans;

        while(count< total)
        {
            //starting row se ending row tk print kara de
            for(int index = startCol;count< total && index<= endCol; index++){
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;

            //starting col se ending col tk print kara de
            for(int index = startRow;count< total && index<= endRow; index++ ){
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;
            //ending row se starting row tk print kara de
            for(int index = endCol;count< total && index>= startCol; index--){
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            for(int index = endRow;count< total && index >= startRow; index--){
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};