class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> current;
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push(current);
                current.clear();
                ++i;
            } else if (formula[i] == ')') {
                int j = i + 1;
                while (j < n && isdigit(formula[j])) ++j;
                int multiplicity = (j > i + 1) ? stoi(formula.substr(i + 1, j - i - 1)) : 1;
                map<string, int> temp = current;
                current = stk.top();
                stk.pop();
                for (auto &p : temp) {
                    current[p.first] += p.second * multiplicity;
                }
                i = j;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) ++j;
                string element = formula.substr(i, j - i);
                i = j;
                while (j < n && isdigit(formula[j])) ++j;
                int multiplicity = (j > i) ? stoi(formula.substr(i, j - i)) : 1;
                current[element] += multiplicity;
                i = j;
            }
        }
        
        string result;
        for (const auto &p : current) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};