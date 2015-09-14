class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result = 0;
        for(int i = 0; i < matrix.size(); ++i) {
        	for(int j = 0; j < matrix[0].size(); ++j) {
        		int a = (i && j) ? matrix[i-1][j-1] : 0;
        		int b = (i) ? matrix[i-1][j] : 0;
        		int c = (j) ? matrix[i][j-1] : 0;

        		matrix[i][j] = (matrix[i][j] == '1') ? (min(a, min(b, c))+1) : 0;

        		result = max(result, matrix[i][j]*matrix[i][j]);
        	}
        }
        return result;
    }
};