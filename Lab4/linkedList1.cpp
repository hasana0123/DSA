#include <iostream>
// #define MAX 4

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    static Node *first;


};

Node *Node::first = nullptr;

int main()
{
    Node n1;
    Node::first = &n1;
    return 0;
}