class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //pahle smaple space create kar le
        vector<int> element;
        for(int i = 1; i<= n*n; i++)
           element.push_back(i);
        int k = element.size();

        vector<vector<int>> ans(n, vector<int>(n));
        int startRow = 0, startCol = 0, endRow = n-1, endCol = n-1;
        int count = 0;
        while(count< k)
        {   vector<int>temp;
            for(int index = startCol; count< k && index<= endCol; index++)
            {
                ans[startRow][index] = *element.begin();
                element.erase(element.begin());
                count++;
            }
            startRow++;

            for(int index = startRow;count< k && index<= endRow; index++)
            {
                ans[index][endCol] = *element.begin();
                element.erase(element.begin());
                count++;
            }
            endCol--;

            for(int index = endCol;count< k && index>= startCol; index--)
            {
                ans[endRow][index] = *element.begin();
                element.erase(element.begin());
                count++;
            }
            endRow--;

            for(int index = endRow;count< k && index>= startRow; index--)
            {
                ans[index][startCol] = *element.begin();
                element.erase(element.begin());
                count++;
            }
            startCol++;


        }
        return ans;
    }
};