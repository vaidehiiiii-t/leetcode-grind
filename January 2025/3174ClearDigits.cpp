class Solution {
    public:
        static string clearDigits(string& s) {
            int n=s.size(), j=0;
            for(int i=0; i<n; i++){
                if (isdigit(s[i]) && j>0) j--;
                else  s[j++]=s[i]; 
            }
            s.resize(j);
            return s;
        }
    };

    //approach 2 using stack

    class Solution {
        public:
            std::string clearDigits(const std::string& s) {
                std::stack<char> stack;
        
                for (char ch : s) {
                    if (isdigit(ch) && !stack.empty()) {
                        stack.pop(); 
                    } else {
                        stack.push(ch); 
                    }
                }
        
                std::string result;
                while (!stack.empty()) {
                    result += stack.top(); 
                    stack.pop();
                }
        
                std::reverse(result.begin(), result.end()); 
                return result;
            }
        };