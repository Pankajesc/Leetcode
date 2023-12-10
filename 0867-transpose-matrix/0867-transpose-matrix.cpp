class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> mat;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> temp;

        int i = 0;

        while (i<cols)
        {
            int j = 0;
            while (j < rows)
            {
                temp.push_back(matrix[j][i]);
                j++;
            }
            mat.push_back(temp);
            temp.clear();
            i++;    
        }
        

        
        return mat;
    }
};