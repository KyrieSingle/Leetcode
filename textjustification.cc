class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int start = 0;
        vector<string> result;
        if(n == 0) return result;
        while(start < n) {
            int i = start;
            int curWidth = words[i].size();
            i++;
            while(i < n && curWidth + 1 + words[i].size() <= maxWidth) {
                curWidth += 1 + words[i].size();
                ++i;
            }
            int space = maxWidth - curWidth;
            stringstream ss;
            int j = start;
            ss << words[j];
            j++;
            for(; j < i; j++) {
                int pad = 0;
                if(i < n) {
                    pad = space / (i-j)+(space % (i-j) ? 1 : 0);
                }
                for(int k = 0; k < pad + 1; ++k) {
                    ss << " ";
                }
                space -= pad;
                ss << words[j];
            }
            for(int k = 0; k < space; ++k) {
                ss << " ";
            }
            result.push_back(ss.str());
            start = i;
        }

        return result;
    }
};
