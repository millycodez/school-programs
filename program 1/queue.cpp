/************************************************************************
 *          Jamil Omer                                                  *
 *          queue class with int main                                   *
 *          Includes: node class, queue class, int main                 *
 * **********************************************************************/

#include<iostream>

using namespace std;

class Node
{
    int data;
    Node* next;

    public:
        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
        int get_value()
        {
            return this->data;
        }
        void set_next(Node* next_node)
        {
            this->next = next_node;
        }
        Node* get_next()
        {
            return this->next;
        }
};

class Queue
{
    Node* head;
    Node* tail;

    int size_queue;

    public:
    Queue()
    {
        head = tail = nullptr;
        size_queue = 0;
    }
    void enqueue(int val)
    {
        Node* node = new Node(val);
        size_queue++;

        if(head == nullptr)
        {
            head = tail = node;
            return;
        }
        tail->set_next(node);
        tail = tail->get_next();
        return;
    }
    void print_queue()
    {
        Node* curr = head;
        cout<<"Printing the queue : [ ";
        while(curr != nullptr)
        {
            cout <<curr->get_value();
            curr = curr->get_next();

            if(curr)cout<<" , ";
        }
        cout<<" ] ";
    }

    int dequeue()
    {
        
        Node* curr = head;

        if(head == nullptr)return -1;

        size_queue--;

        if(head == tail)
        {
            int data = head->get_value();
            delete head;
            head = tail = nullptr;
            return data;
        }
        head = head->get_next();;
        int data = curr->get_value();
        delete curr;
        return data;
    }
    int peek()
    {
        if(head == nullptr)return -1;
        return head->get_value();
    }
    bool isEmpty()
    {
        if(head == tail)return true;
        return false;
    }
    int size()
    {
        return size_queue;
    }
};

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
   int choice = 0;

   Queue* baka = new Queue();

   do{
       cout << "which choice pleases you the most my majesty? : \n";
       cout << "1)enqueue\n2)dequeue\n3)peek\n4)print\n5)xit\n";

       cin >> choice;

       if(choice == 1)
       {
           cout<<"enter a cool number to be enqueue : ";
           int val; 
           cin >> val;

           baka->enqueue(val);
       }
       else if(choice == 4)
       {
           baka->print_queue();
       }
       else if(choice == 2)
       {
           int val;
           val = baka->dequeue();
           cout << "valued dequeued : " << val << "\n";
       }
       else if(choice == 3)
       {
           cout << "value at the peek (a boo) " << baka->peek();
           cout << "\n";
       }
       else break;
   }
   while(choice!=5);
}