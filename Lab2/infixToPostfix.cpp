#include <iostream>
#include <string.h>
using namespace std;

class Expression
{
    char operators[7] = {'*', '/', '+', '-', '^', '(', ')'};
    string infixExp;
    string opStackStatus;
    string postfixExp;
    int currentPos = 0;

public:
    void input()
    {
        cout << "Enter the infix operation to convert to postfix: " << endl;
        cin >> infixExp;
    }
    void addBraces()
    {
        infixExp = '(' + infixExp + ')';
    }

    char getCharacter()
    {
        char temp = infixExp[currentPos];
        currentPos++;
        return (temp);
    }

    int getLength()
    {
        return (infixExp.length());
    }

    bool isOperator(char character)
    {
        for (int i = 0; i < sizeof(operators); i++)
        {
            if (operators[i] == character)
            {
                return true;
            }
        }
        return false;
    }
    void compareOperators(char currentChar)
    {
        char topChar;
        switch (currentChar)
        {
        case '(':
            opStackStatus.push_back(currentChar);
            break;
        case '^':
            opStackStatus.push_back(currentChar);
            break;
        case '*':
            topChar = opStackStatus[opStackStatus.length() - 1];
            if (topChar == '(' || topChar == '+' || topChar == '-')
            {
                opStackStatus.push_back(currentChar);
            }
            else if (topChar == '/' || topChar == '^' || topChar == '*')
            {
                while (topChar == '/' || topChar == '^')
                {
                    opStackStatus.pop_back();
                    pushExp(topChar);
                    topChar = opStackStatus[opStackStatus.length() - 1];
                }
                opStackStatus.push_back(currentChar);
            }
            break;
        case '/':
            topChar = opStackStatus[opStackStatus.length() - 1];
            if (topChar == '(' || topChar == '+' || topChar == '-')
            {
                opStackStatus.push_back(currentChar);
            }
            else if (topChar == '*' || topChar == '^' || topChar == '/')
            {
                while (topChar == '*' || topChar == '^' || topChar == '/')
                {
                    opStackStatus.pop_back();
                    pushExp(topChar);
                    topChar = opStackStatus[opStackStatus.length() - 1];
                }
                opStackStatus.push_back(currentChar);
            }
            break;
        case '+':
            topChar = opStackStatus[opStackStatus.length() - 1];
            if (topChar == '(')
            {
                opStackStatus.push_back(currentChar);
            }
            else if (topChar == '/' || topChar == '^' || topChar == '*' || topChar == '-' || topChar == '+')
            {

                while (topChar == '/' || topChar == '^' || topChar == '*' || topChar == '-' || topChar == '+')
                {
                    opStackStatus.pop_back();
                    pushExp(topChar);
                    topChar = opStackStatus[opStackStatus.length() - 1];
                }
                opStackStatus.push_back(currentChar);
            }
            break;
        case '-':
            topChar = opStackStatus[opStackStatus.length() - 1];
            if (topChar == '(')
            {
                opStackStatus.push_back(currentChar);
            }
            else if (topChar == '/' || topChar == '^' || topChar == '*' || topChar == '+' || topChar == '-')
            {

                while (topChar == '/' || topChar == '^' || topChar == '*' || topChar == '+' || topChar == '-')
                {
                    opStackStatus.pop_back();
                    pushExp(topChar);
                    topChar = opStackStatus[opStackStatus.length() - 1];
                }
                opStackStatus.push_back(currentChar);
            }
            break;
        case ')':
            topChar = opStackStatus[opStackStatus.length() - 1];
            while (topChar != '(')
            {
                opStackStatus.pop_back();
                pushExp(topChar);
                topChar = opStackStatus[opStackStatus.length() - 1];
            }
            if (topChar == '(')
            {
                opStackStatus.pop_back();
            }
            break;
        default:
            cout << "not  valid expression";
            exit(0);
            break;
        }
    }
    void pushExp(char value)
    {
        postfixExp.push_back(value);
    }
    void display()
    {
        cout << "Infix Expression = " << infixExp << endl;
        cout << "Postfix Expression = " << postfixExp << endl;
    }
};

int main()
{
    Expression e1;
    char currentChar;
    e1.input();
    e1.addBraces();

    for (int i = 0; i < e1.getLength(); i++)
    {

        currentChar = e1.getCharacter();
        if (currentChar >= 97 && currentChar <= 122)
        {
            currentChar -= 32;
        }
        if (currentChar >= 65 && currentChar <= 90)
        {
            e1.pushExp(currentChar);
        }
        else if (e1.isOperator(currentChar))
        {
            e1.compareOperators(currentChar);
        }
        else
        {
            cout << "invalid input" << endl;
            exit(0);
        }
    }
    e1.display();
}