#include <iostream>
#define MAX 4

using namespace std;

int availableList = 0;

class Node
{
    int info;
    int next;

public:
    friend int getNode();
    friend void freeNode(int);
    friend void insertAfter(int, int);
    friend void deleteAfter(int);
    friend void addressing();
    friend void display();
};
Node list[MAX];

void addressing()
{
    for (int i = 0; i < MAX - 1; i++)
        list[i].next = i + 1;

    list[MAX - 1].next = -1;
}

int getNode()
{
    if (availableList == -1)
    {
        cout << "List is full!" << endl;
        exit(0);
    }

    else
    {
        int newNode = availableList;
        availableList = list[newNode].next;
        return newNode;
    }
}

void insertAfter(int nodeAfter, int data)
{
    int newNode = getNode();
    list[newNode].info = data;
    list[newNode].next = list[nodeAfter].next;
    list[nodeAfter].next = newNode;
}

void freeNode(int node)
{
    list[node].next = availableList;
    availableList = node;
}

void deleteAfter(int nodeAfter)
{
    int temp = list[nodeAfter].next;
    cout << "Deleted info ===> " << list[temp].info << endl;
    list[temp].info=0;
    list[nodeAfter].next = list[temp].next;
    freeNode(temp);
    cout << "Deleted Node ===> " << temp;
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << i << "  " << list[i].info << "   "
             << "next==>" << list[i].next << endl;
    }
    cout<<"available list = "<<availableList<<endl;
}

int main()
{
    int option, dataToStore, nodeAfter;
    char endOption;
    addressing();
    do
    {
        cout << "Enter the operation: \n 1: Insert 2:Delete 3:Display ===>";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the node after which data is to be stored:==>";
            cin >> nodeAfter;
            if (nodeAfter < 0 || nodeAfter > 3)
                cout << "Invalid node" << endl;
                
            else
            {
                cout << "Enter the data to store ==>";
                cin >> dataToStore;
                insertAfter(nodeAfter, dataToStore);
            }
            break;

        case 2:
            cout << "Enter the node after which data is to be deleted:==>";
            cin >> nodeAfter;
            if (nodeAfter < 0 || nodeAfter > 3)
                cout << "Invalid node" << endl;

            else
                deleteAfter(nodeAfter);

            break;

        case 3:
            display();
            break;

        default:
            cout<<"Invalid operation!"<<endl;
            break;

        }
        cout<<"Exit? y/n===>";
        cin>>endOption;
    }
    while(endOption!='y');
}