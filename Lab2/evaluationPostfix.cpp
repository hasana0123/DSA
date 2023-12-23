#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Evaluation
{
    string postfixExp;
    int stackStatus[50];
    int currentPos = 0;
    int top = -1;

public:
    void input()
    {
        cout << "Enter a postfix exp: " << endl;
        cin >> postfixExp;
    }

    int getlength()
    {
        return (postfixExp.length());
    }

    char getChar()
    {
        char temp = postfixExp[currentPos];
        currentPos++;
        return temp;
    }

    bool isOperand(char character)
    {
        if (character >= '0' && character <= '9')
            return true;
        else
            return false;
    }

    bool isOperator(char op)
    {
        char operators[] = {'*', '/', '^', '+', '-', '$'};
        for (int i = 0; i < 6; i++)
            if (operators[i] == op)
                return true;

        return false;
    }

    void push(int value)
    {
        top++;
        stackStatus[top] = value;
    }

    int pop()
    {
        int temp = stackStatus[top];
        top--;
        return temp;
    }

    void Operation(int op1, int op2, char operand)
    {
        int temp;
        switch (operand)
        {
        case '*':
            temp = op1 * op2;
            break;

        case '/':
            temp = op1 / op2;
            break;

        case '+':
            temp = op1 + op2;
            break;

        case '-':
            temp = op1 - op2;
            break;

        case '^':
            temp = pow(op1, op2);
            break;

        case '$':
            temp = pow(op1, op2);
            break;
        }

        push(temp);
    }
};

int main()
{
    Evaluation e1;
    e1.input();
    char currentChar;
    int poppedValue1, poppedValue2, result;
    for (int i = 0; i < e1.getlength(); i++)
    {
        currentChar = e1.getChar();
        if (e1.isOperand(currentChar))
            e1.push(currentChar - '0');

        else if (e1.isOperator(currentChar))
        {
            poppedValue2 = e1.pop();
            poppedValue1 = e1.pop();
            e1.Operation(poppedValue1, poppedValue2, currentChar);
        }
    }
    result = e1.pop();
    cout << "Final value for evaluation of postfix " << result << endl;
}