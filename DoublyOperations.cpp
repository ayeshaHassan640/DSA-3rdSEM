#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int index;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int value)
    {
        Node* temp = new Node(value);

        // Empty List
        if(head == NULL)
        {
            temp->index = 0;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->index = tail->index + 1;

            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void print()
    {
        Node* current = head;

        while(current != NULL)
        {
            cout << "Index = " << current->index
                 << "  Data = " << current->data << endl;

            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.insert(50);
    list.insert(20);
    list.insert(90);
    list.insert(10);

    list.print();

    return 0;
}
