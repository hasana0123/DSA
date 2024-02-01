#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    friend bool isEmpty();
    friend void insertFromBeginning(int data);
    friend void insertFromEnd(int data);
    friend void insertAfterPos(int pos, int data);
    friend void deleteFromBeginning();
    friend void deleteFromEnd();
    friend void deleteAfterPos(int pos);
    friend void display();
};
Node *head = 0;

bool isEmpty()
{
    if (head == 0)
        return true;

    else
        return false;
}

void insertFromBeginning(int data)
{
    Node *newNode = new Node;
    newNode->next = head;
    newNode->data = data;
    head = newNode;
}

void insertFromEnd(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (!isEmpty())
    {
        Node *temp = head;
        while (temp->next != 0)
            temp = temp->next;

        temp->next = newNode;
    }

    else

        head = newNode;
    newNode->next = 0;
}

void insertAfterPos(int pos, int data)
{
    if (isEmpty())
    {
        if (pos == 0)
            insertFromBeginning(data);

        else
            cout << "Cannot insert in given position, list is empty" << endl;
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = data;

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning()
{
    if (isEmpty())
        cout << "List is Empty" << endl;

    else
    {
        cout << "Deleted value = " << head->data << endl;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteFromEnd()
{
    if (isEmpty())
        cout << "List is Empty!" << endl;

    else
    {
        Node *temp = head;
        if (temp->next == 0) // If only one element in the list
        {
            cout << "Deleted value = " << temp->data << endl;
            delete temp;
            head = 0;
        }
        else
        {
            while (temp->next->next != 0)
                temp = temp->next;
            cout << "Deleted value = " << temp->next->data << endl;
            delete temp->next;
            temp->next = 0;
        }
    }
}

void deleteAfterPos(int pos)
{
    if (isEmpty())
        cout << "List is Empty!" << endl;
    else
    {
        Node *temp = head;
        Node *temp1;

        for (int i = 0; i <= pos; i++)
            temp = temp->next;

        cout << "Deleted value = " << temp->next->data << endl;
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
    }
}

void display()
{
    if (isEmpty())
        cout << "List is Empty!" << endl;

    else
    {
        Node *temp = head;
        int i = 1;

        while (temp != 0)
        {
            cout << i++ << "data = " << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{

    int option1, option2, dataToStore, nodeAfter;
    char endOption;

    do
    {
        cout << "Enter the operation : \n 1:Insert 2:Delete 3:Display ===>";
        cin >> option1;
        switch (option1)
        {
        case 1:
            cout << "Enter the value to insert===>";
            cin >> dataToStore;
            cout << "-----------------------" << endl;
            cout << "Which insert? \n 1:Insert from Beginning 2: Insert from end 3:Insert after position 'p'===>";
            cin >> option2;
            switch (option2)
            {
            case 1:
                insertFromBeginning(dataToStore);
                break;

            case 2:
                insertFromEnd(dataToStore);
                break;

            case 3:
                cout << "After which position? ===>";
                cin >> nodeAfter;
                insertAfterPos(nodeAfter, dataToStore);
                break;

            default:
                cout << "Invalid input!" << endl;
                break;
            }

            break;

        case 2:
            cout << "Which delete? \n 1:Delete from Beginning 2: Delete from end 3:Delete after position 'p'===>";
            cin >> option2;
            switch (option2)
            {
            case 1:
                deleteFromBeginning();
                break;

            case 2:
                deleteFromEnd();
                break;

            case 3:
                cout << "After which position? ===>";
                cin >> nodeAfter;
                deleteAfterPos(nodeAfter);
                break;

            default:
                cout << "Invalid input!" << endl;
                break;
            }
            break;

        case 3:
            display();
            break;

        default:
            cout << "Invalid Input!" << endl;
            break;
        }
        cout << "Exit? y/n";
        cin >> endOption;

    } while (endOption != 'y');
    return 0;
}