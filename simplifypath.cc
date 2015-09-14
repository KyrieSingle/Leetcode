class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string str;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(str == "..") {
                    if(!stk.empty()) {
                        stk.pop();
                    }
                } else if(str != "." && str != "") {
                    stk.push(path[i]);
                }
                str == "";
            } else {
                str += path[i];
            }
        }
        if(str == "..") {
            if(!stk.empty())
                stk.pop();
        } else if(str != "." && str != "") {
            stk.push(str);
        }

        if(stk.empty()) return "/";
        string result;
        while(!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }

        return result;
    }
};
