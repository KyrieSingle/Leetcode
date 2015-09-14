class Solution {
private:
    bool helper(vector<vector<char>>& board, int row, int col, const string& word, int start, int m, int n, int length) {
        char current;
        bool result = false;
        if((current = board[row][col]) != word[start]) return false;
        if(start == length - 1) return true;
        board[row][col] = '*';
        if(row > 0) 
            result = helper(board, row-1, col, word, start+1, m, n, length);
        if(!result && row < m - 1) 
            result = helper(board, row+1, col, word, start+1, m, n, length);
        if(!result && col > 0) 
            result = helper(board, row, col-1, word, start+1, m, n, length);
        if(!result && col < n - 1)
            result = helper(board, row, col+1, word, start+1, m, n, length);
        board[row][col] = current;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int length = word.size();
        if(board.size() == 0 || length == 0) return false;
        if(board[0].size() == 0) return false;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != word[0])
                    continue;
                if(helper(board, i, j, word, 0, m, n, length))
                    return true;
            }
        }
        return false;
    }
};
