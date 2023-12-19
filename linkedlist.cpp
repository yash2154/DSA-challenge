#include <iostream>

struct Node
{
    int data;
    Node *next = nullptr;
};

class LinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    int InsertAtEnd(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        return value;
    }

    void Display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout<<"\n";
    }

    int InsertAtBeginning(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;

        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            newnode->next = head;
            head = newnode;
        }
        return value;
    }
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main()
{
    LinkedList list;
    list.InsertAtEnd(1);
    list.InsertAtBeginning(4);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.Display();
    list.reverse();
    list.Display();


    return 0;
}