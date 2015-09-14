class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        int x = 0, y = 0;
        int rx = matrix.size() - 1; 
        int ry = matrix[0].size() -1;
        while(x <= rx && y <= ry){
            if (x == rx) {
                for(int i = y; i <= ry; ++i) {
                    result.push_back(matrix[x][i]);
                }
            } else if(y == ry && rx != 0) {
                for(int i = x; i <= rx; ++i) {
                    result.push_back(matrix[i][y]);
                }
            } else {
                int curX = x, curY = y;
                while(curY != ry) {
                    result.push_back(matrix[x][curY]);
                    curY++;
                }
                while(curX != rx){
                    result.push_back(matrix[curX][ry]);
                    curX++; 
                }
                while(curY != y) {
                    result.push_back(matrix[rx][curY]);
                    curY--;
                }
                while(curX != x) {
                    result.push_back(matrix[curX][y]);
                    curX--;
                }
            }
            x++;
            y++;
            rx--;
            ry--;
        }
        return result;
    }
};

