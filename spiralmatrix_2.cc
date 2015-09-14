class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        if(0 == n) return res;
        int curLayer = 0;
        int idx = 1;
        int curRow;
        int curCol;
        
        while(1)  {
            curRow = curLayer;
            for(int col = curLayer; col < n - curLayer; col++) {
                res[curRow][col] = idx++;
            }
            curCol = n - curLayer - 1;
            for(int row = curLayer+1; row < n - curLayer; row++) {
                res[row][curCol] = idx++;
            }
            curRow = n - curLayer -1;
            for(int col = n - curLayer-2; col >= curLayer; col--) {
                res[curRow][col] = idx++;
            }
            curCol = curLayer;
            for(int row = n - curLayer-2; row > curLayer; row--) {
                res[row][curCol] = idx++;
            }
            curLayer++;
            if((n+1)/2 == (curLayer)) {
                break;
            }          
        }
        return res;
    }
};
