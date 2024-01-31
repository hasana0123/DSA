#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    static Node *head;
    
    bool isEmpty()
    {
        if (head == nullptr)
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

        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = nullptr;
    }

    void insertAfterPos(int pos, int data)
    {
        Node *newNode = new Node;
        newNode->data = data;

        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (isEmpty)
            cout << "List is Empty" << endl;
        else
        {
            cout << "Deleted value = " << head->data << endl;
            Node *temp = head;
            delete temp;
        }
    }

    void deleteFromEnd()
    {
        if (isEmpty)
            cout << "List is Empty!" << endl;
        else
        {
            Node *temp = head;

            while (temp->next->next != nullptr)
                temp = temp->next;

            cout << "Deleted value = " << temp->next->data << endl;
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deleteAfterPos(int pos)
    {
        if (isEmpty)
            cout << "List is Empty!" << endl;
        else
        {
            Node *temp = head;

            for (int i = 1; i < pos - 2; i++)
                temp = temp->next;

            cout << "Deleted value = " << temp->next->data << endl;
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void display()
    {
        if (isEmpty)
            cout << "List is Empty!" << endl;
        else
        {

            Node *temp = head;
            int i = 1;
            while (temp->next != nullptr)
            {
                cout << i++ << "data = " << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
Node Node::*head = nullptr;

int main()
{
    Node n1;

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
                n1.insertFromBeginning(dataToStore);
                break;
            case 2:
                n1.insertFromEnd(dataToStore);
                break;

            case 3:
                cout << "After which position? ===>";
                cin >> nodeAfter;
                n1.insertAfterPos(nodeAfter, dataToStore);
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
                n1.deleteFromBeginning();
                break;
            case 2:
                n1.deleteFromEnd();
                break;

            case 3:
                cout << "After which position? ===>";
                cin >> nodeAfter;
                n1.deleteAfterPos(nodeAfter);
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
            }
            break;

        case 3:
            n1.display();
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