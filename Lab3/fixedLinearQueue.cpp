#include <iostream>
#include<iomanip>
#define MAX 3
 
using namespace std;
 
class Queue
{
    int head =0;
    int rear =-1;
    int queuevar[MAX];
public:
    bool isEmpty()
    {
        if(rear<head)
            return true;
        else
            return false;
    }
 
    bool isFull()
    {
        if(rear == MAX-1)
            return true;
        else
            return false;
    }
 
    void shiftDown()
    {
        for(int i=0;i<rear;i++)
        {
            queuevar[i]=queuevar[i+1];
        }
        rear--;
    }
 
    void enqueue(int data)
    {
        rear++;
        queuevar[rear]=data;
    }
 
    int dequeue()
    {
        int temp= queuevar[head];
        shiftDown();
        return temp;
    }
 
    void display()
    {
        cout<<"The elements in the queue are: "<<endl;
        cout<<"-----------------------"<<endl;
        for(int i =head;i<=rear;i++)
         cout<<setw(3)<<i+1<<":"<<queuevar[i]<<endl;
        if(isFull())
            cout<<"Queue is Full"<<endl;
    }
};
 
 
int main()
{
    Queue q1;
    int option,pushValue,poppedValue;
    char endOption;
    while(endOption!='y')
    {
        cout<<"Which operation? \n1:Enqueue 2:Dequeue 3:Display"<<endl;
        cin>>option;
 
        switch(option)
        {
        case 1:
            if(q1.isFull())
                cout<<"Queue is full"<<endl;
            else
            {
                cout<<"to enqueue: ";
                cin>>pushValue;
                q1.enqueue(pushValue);
            }
 
            break;
        case 2:
            if(q1.isEmpty())
                cout<<"Queue is empty"<<endl;
            else
            {
                poppedValue=q1.dequeue();
                cout<<"popped value is: "<<poppedValue<<endl;
            }
            break;
        case 3:
             if(q1.isEmpty())
                cout<<"Queue is empty"<<endl;
            else
            {
                q1.display();
            }
            break;
        default:
            cout<<"Invalid operation"<<endl;
            break;
        }
        cout<<"Exit?: y/n: ";
        cin>>endOption;
    }
}