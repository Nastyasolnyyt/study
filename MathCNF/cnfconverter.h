// cnfconverter.h
#ifndef CNFCONVERTER_H
#define CNFCONVERTER_H

#include <string>
#include <stack>

class CNFConverter {
public:
    CNFConverter();
    std::string convertToCNF(const std::string& expression);

private:
    std::string removeSpaces(const std::string& str);
    bool isOperator(char c);
    int getPriority(char op);
    std::string toRPN(const std::string& expr);
    std::string applyNegation(const std::string& expr);
    std::string applyDeMorgan(const std::string& rpn);
    std::string applyOperator(char op, const std::string& a, const std::string& b);
    std::string distributeOR(const std::string& expr);
    std::string toCNF(const std::string& rpn);
    std::string simplifyCNF(const std::string& cnf);
    size_t findTopLevelOp(const std::string& expr);

};

#endif // CNFCONVERTER_H
