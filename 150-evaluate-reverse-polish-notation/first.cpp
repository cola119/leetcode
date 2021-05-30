class Solution {
public:
    /*
    ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
                                         ↑
    [10,6,3]+ => 9+3=12
    [10,6,12,-11]* => -132
    [10,6,-132]/ => 6/-132
    [10,6/-132]* => 60/-132
    [60/-132,17]+ => 60/-132
    */
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token: tokens) {
            if(isOp(token)) {
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                int result =  token == "+" ? num2+num1
                            : token == "-" ? num2-num1
                            : token == "*" ? num2*num1
                            : num2/num1;
                s.push(result);
            } else {
                int num = stoi(token);
                s.push(num);
            }
        }
        return s.top();
    }
    
    bool isOp(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};