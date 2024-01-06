#include <iostream>
#include <iomanip>
#define MAX 3

using namespace std;

class Queue
{
    int front = 0;
    int rear = 0;
    int queuevar[MAX];

public:
    bool isEmpty()
    {
        if (rear == front)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (front == (rear + 1) % (MAX+1))
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        queuevar[rear] = data;
        rear = (rear + 1) % (MAX+1);
    }

    int dequeue()
    {
        int temp;
        temp = queuevar[front];
        front = (front + 1) % (MAX+1);
        return temp;
    }

    void display()
    {
        int i = 0;
        int frontp = front;
        int rearp = rear;
        while (frontp != rearp)
        {
            cout << setw(4)<<left << i <<":"<< queuevar[frontp] << endl;
            i++;
            frontp = (frontp + 1) % (MAX+1);
        }
        if (isFull())
            cout << "Queue is Full" << endl;
    }
};

int main()
{
    Queue q1;
    int options, pushValue;
    char endOption;
    do
    {
        cout << "Which operation? \n 1:Enqueue 2: Dequeue 3:Display ===>";
        cin >> options;
        switch (options)
        {
        case 1:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
            {
                cout << "Value to enqueue ==>";
                cin >> pushValue;
                q1.enqueue(pushValue);
            }
            break;
        case 2:
            if (q1.isEmpty())
                cout << "Queue is Empty!" << endl;
            else
            {
                cout << "Popped value ==>" << q1.dequeue()<<endl;
            }
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty!" << endl;
            else{
                q1.display();
            }
            break;
        default: 
            cout<<"Invalid Input"<<endl;
            break;
        }
        cout<<"Exit? y/n ===>";
        cin>>endOption;

    } while (endOption != 'y');
}