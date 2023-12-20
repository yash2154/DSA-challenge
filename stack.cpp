#include <iostream>

struct StackNode
{
    int data;
    StackNode *next;
};

class Stack
{

public:
    int size=0;

    StackNode *head=nullptr;
    void Push(int value)
    {
        StackNode *newnode = new StackNode();
        newnode->data = value;
        newnode->next = head;
        size++;
        head = newnode;
    }

    int Peek()
    {
        return head->data;
    }

    int Pop()
    {
        StackNode*current = head;
        int returnvalue  = head->data;
        head=current->next;
        size--;
        delete current;
        return returnvalue;
    }

    

    void display()
    {
        StackNode *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    bool IsEmpty()
    {
        if(head==nullptr)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Stack stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Push(60);
    stack.display();
    std::cout<<stack.Pop()<<"\n";
    std::cout<<stack.size<<"\n";
    
    stack.display();
    std::cout<<stack.Peek()<<"\n";
    stack.display();
    std::cout<<stack.IsEmpty()<<"\n";
}