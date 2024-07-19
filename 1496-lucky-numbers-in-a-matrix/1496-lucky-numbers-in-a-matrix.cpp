class Solution {
private:
    vector<int> commonEle(vector<int> rowMin, vector<int> colMax){
        vector<int> ans;
        unordered_set<int> s(rowMin.begin(), rowMin.end());
        for(auto i : colMax){
            if(s.find(i) != s.end())
               ans.push_back(i);
        }
        return ans; 
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1 && cols == 1){
            return matrix[0];
        }
        vector<int> rowMin;
        vector<int> colMax;
        for(int i = 0; i< rows; i++){
            int ele = INT_MAX;
            for(int j = 0; j< cols; j++){
                if(matrix[i][j] < ele)
                    ele = matrix[i][j];
            }
            rowMin.push_back(ele);
        }
        for(int j = 0; j< cols; j++){
            int ele = INT_MIN;
            for(int i = 0; i< rows; i++){
                if(matrix[i][j] > ele)
                    ele = matrix[i][j];
            }
            colMax.push_back(ele);
        }
        
        return commonEle(rowMin, colMax);
    }
};