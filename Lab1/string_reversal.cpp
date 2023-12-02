#include <iostream>
#include <string.h>
#define MAX 5

using namespace std;

class Stack
{
    int top = -1;
    char s[MAX];

public:
    bool isFull()
    {
        if (top >= MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char value)
    {
        top++;
        s[top] = value;
    }

    char pop()
    {
        char temp = s[top];
        top--;
        return temp;
    }
    char peek()
    {
        return (s[top]);
    }
};

int main()
{
    Stack s1;
    char s[MAX], peekedValue;
    char reverse[MAX], poppedValue;
    char endOption = 'n';
    int option;
    int j;
    do
    {
        cout<<"------------------------------------------------------------"<<endl;
        cout << "Enter the action to perform \n 1= Push   2: Pop   3:Peek   ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the string to be reversed" << endl;
            cin >> s;

            for (int i = 0; i < sizeof(s); i++)
            {
                if (s1.isFull())
                {
                    cout << "Stack is full, pop the current values first!!" << endl;
                    break;
                }
                else
                {
                    s1.push(s[i]);
                }
            }
            break;
        case 2:
            if (s1.isEmpty())
            {
                cout << "Stack is empty!!" << endl;
                break;
            }
            else
            {
                j = 0;
                while (!s1.isEmpty())
                {
                    poppedValue = s1.pop();
                    // reverse += poppedValue;
                    reverse[j] = poppedValue;
                    j++;
                }
            }
            cout << "Reversed string = " << reverse << endl;
            break;

        case 3:
            if (s1.isEmpty())
            {
                cout << "Stack is empty, nothing to peek!!" << endl;
                break;
            }
            else
            {
                peekedValue = s1.peek();
            }
            cout << "Value at the top of stack is " << peekedValue << endl;
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
        cout << "Do you want to end the program?  y/n   ";
        cin >> endOption;
    } while (endOption != 'y');
}