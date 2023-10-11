class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<int>> m;
        unordered_map<int,vector<int>> m_row;
        unordered_map<int,vector<int>> m_col;
        int count;
        for(int i = 0; i<9;i++){
            if(i<3)
                count = 0;
            else if(i>2 && i<6)
                count = 3;
            else if(i>=6)
                count = 6;
            for(int j = 0; j<9;j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    m_row[i].push_back(board[i][j] - '0');
                    m_col[j].push_back(board[i][j] - '0');
                    m[count + j/3].push_back(board[i][j] - '0');
                }     
            }
            count = 0;
        }
        
        for(auto p : m_col){
            vector<int> temp(10,0);
            for(auto it: p.second)
                temp[it]++;
            for(auto it : temp){
                if(it>1)
                    return false;
            }
        }
        for(auto p:m_row){
            vector<int> temp(10,0);
            for(auto it: p.second)
                temp[it]++;
            for(auto it : temp){
                if(it>1)
                    return false;
            }
        }
        for(auto p:m){
            vector<int> temp(10,0);
            for(auto it: p.second)
                temp[it]++;
            for(auto it : temp){
                if(it>1)
                    return false;
            }
        }
        return true;
    }
};