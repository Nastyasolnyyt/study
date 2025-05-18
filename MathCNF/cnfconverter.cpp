#include "cnfconverter.h"
#include <stack>
#include <algorithm>

CNFConverter::CNFConverter() {}

std::string CNFConverter::convertToCNF(const std::string& expression) {
    std::string expr = removeSpaces(expression);
    std::string rpn = toRPN(expr);
    std::string cnf = toCNF(rpn);
    return simplifyCNF(cnf);
}

std::string CNFConverter::removeSpaces(const std::string& str)
{
    std::string result;
    for (char c : str) {
        if (c != ' ') result += c;
    }
    return result;
}

bool CNFConverter::isOperator(char c)
{
    return c == '&' || c == '|' || c == '!' || c == '>' || c == '=';
}

int CNFConverter::getPriority(char op)
{
    if (op == '!') return 4;
    if (op == '&') return 3;
    if (op == '|') return 2;
    if (op == '>') return 1;
    if (op == '=') return 0;
    return -1;
}

std::string CNFConverter::toRPN(const std::string& expr)
{
    std::string rpn;
    std::stack<char> ops;

    for (char c : expr) {
        if (isalpha(c)) {
            rpn += c;
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                rpn += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if (isOperator(c)) {
            while (!ops.empty() && ops.top() != '(' &&
                   getPriority(ops.top()) >= getPriority(c)) {
                rpn += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        rpn += ops.top();
        ops.pop();
    }

    return rpn;
}

std::string CNFConverter::applyOperator(char op, const std::string& a, const std::string& b)
{
    if (op == '&') return "(" + a + "&" + b + ")";
    if (op == '|') return "(" + a + "|" + b + ")";
    if (op == '>') return "(!(" + a + ")|" + b + ")";
    if (op == '=') return "((!(" + a + ")|" + b + ")&(!(" + b + ")|" + a + "))";
    return "";
}


std::string CNFConverter::toCNF(const std::string& rpn) {
    std::stack<std::string> st;

    for (char c : rpn) {
        if (isalpha(c)) {
            st.push(std::string(1, c));
        }
        else if (c == '!') {
            std::string a = st.top();
            st.pop();
            st.push(applyNegation(a));
        }
        else if (isOperator(c)) {
            std::string b = st.top();
            st.pop();
            std::string a = st.top();
            st.pop();

            // Сначала преобразуем подвыражения в КНФ
            a = toCNF(toRPN(a));
            b = toCNF(toRPN(b));

            std::string result;
            if (c == '&') {
                result = "(" + a + "&" + b + ")";
            }
            else if (c == '|') {
                result = distributeOR("(" + a + "|" + b + ")");
            }
            else if (c == '>') {
                // A → B преобразуем в ¬A ∨ B
                std::string notA = applyNegation(a);
                result = distributeOR("(" + notA + "|" + b + ")");
            }
            else if (c == '=') {
                // A ≡ B преобразуем в (¬A ∨ B) ∧ (A ∨ ¬B)
                std::string notA = applyNegation(a);
                std::string notB = applyNegation(b);
                std::string part1 = distributeOR("(" + notA + "|" + b + ")");
                std::string part2 = distributeOR("(" + a + "|" + notB + ")");
                result = "(" + part1 + "&" + part2 + ")";
            }

            st.push(result);
        }
    }

    return st.empty() ? "" : st.top();
}

std::string CNFConverter::applyNegation(const std::string& expr) {
    if (expr.empty()) return "";

    // Если отрицание уже есть, убираем его
    if (expr[0] == '!') {
        return expr.substr(1);
    }

    // Если это переменная, просто добавляем отрицание
    if (expr.size() == 1 && isalpha(expr[0])) {
        return "!" + expr;
    }

    // Для сложных выражений применяем закон де Моргана
    if (expr[0] == '(') {
        std::string inner = expr.substr(1, expr.size()-2);
        std::string rpn = toRPN(inner);

        // Анализируем оператор на верхнем уровне
        size_t op_pos = findTopLevelOp(inner);
        if (op_pos != std::string::npos) {
            char op = inner[op_pos];

            if (op == '&' || op == '|') {
                std::string left = inner.substr(0, op_pos);
                std::string right = inner.substr(op_pos+1);

                // Применяем закон де Моргана
                std::string notLeft = applyNegation(left);
                std::string notRight = applyNegation(right);

                char newOp = (op == '&') ? '|' : '&';
                return "(" + notLeft + std::string(1, newOp) + notRight + ")";
            }
        }
    }

    // Если не смогли применить закон де Моргана, просто добавляем отрицание
    return "!(" + expr + ")";
}

size_t CNFConverter::findTopLevelOp(const std::string& expr) {
    int balance = 0;
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == '(') balance++;
        else if (c == ')') balance--;
        else if (balance == 0 && (c == '&' || c == '|')) {
            return i;
        }
    }
    return std::string::npos;
}

std::string CNFConverter::distributeOR(const std::string& expr) {
    if (expr.size() < 3 || expr[0] != '(') return expr;

    std::string inner = expr.substr(1, expr.size()-2);
    size_t or_pos = inner.find('|');

    if (or_pos == std::string::npos) return expr;

    std::string left = inner.substr(0, or_pos);
    std::string right = inner.substr(or_pos+1);

    // Если одна из частей - конъюнкция, применяем дистрибутивность
    if (left.find('&') != std::string::npos) {
        size_t and_pos = left.find('&');
        std::string a = left.substr(0, and_pos);
        std::string b = left.substr(and_pos+1);

        std::string part1 = distributeOR("(" + a + "|" + right + ")");
        std::string part2 = distributeOR("(" + b + "|" + right + ")");

        return "(" + part1 + "&" + part2 + ")";
    }
    else if (right.find('&') != std::string::npos) {
        size_t and_pos = right.find('&');
        std::string a = right.substr(0, and_pos);
        std::string b = right.substr(and_pos+1);

        std::string part1 = distributeOR("(" + left + "|" + a + ")");
        std::string part2 = distributeOR("(" + left + "|" + b + ")");

        return "(" + part1 + "&" + part2 + ")";
    }

    // Если нечего распределять, возвращаем исходное выражение
    return expr;
}

std::string CNFConverter::simplifyCNF(const std::string& cnf) {
    // Упрощаем двойные отрицания и избыточные скобки
    // (здесь можно добавить дополнительную логику упрощения)
    return cnf;
}
