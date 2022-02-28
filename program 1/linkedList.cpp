/************************************************************************
 *          Jamil Omer                                                  *
 *          linkedlist class with int main                              *
 *          Includes: node class, linkedlist class, int main            *
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

class LinkedList
{
    Node* head;
    Node* tail;
    public:
    LinkedList()
    {
        head = tail = nullptr;
    }
    void insert(int value)
    {
        Node* node = new Node(value);

        if(head == nullptr)
        {
            head = tail = node;
            return;
        }

        tail->set_next(node);
        tail = tail->get_next();

        return;
    }
    void print_list()
    {
        Node* curr = head;

        cout<<"printing the list for free : [ ";

        while(curr != nullptr)
        {
            cout << curr->get_value();
            curr = curr->get_next();
            if(curr)cout<<" , ";
        }
        cout << " ] ";
    }
    bool  exists(int k)
    {
        Node* curr = head;
        while(curr != nullptr)
        {
            if( curr->get_value() == k)return true;
            curr = curr->get_next();
        }
        return false;
    }

    /*BONUS :DDDDDDDDDDDDDDDDDDDDDDDDDDD*/
    
    void remove(int k)
    {
        if(!exists(k))return; 

        Node* curr = head;

        if(head->get_value() == k)
        {
            if(tail == head)
            {
                head = head->get_next();
                delete curr;
                tail=head;
            }
            else
            {
                head = head->get_next();
                delete curr;
            }
            return;
        }

        Node* prev = curr;

        while(curr->get_value()!=k)
        {
            prev = curr;
            curr = curr->get_next();
        }
        prev->set_next(curr->get_next());

        if(tail == curr)tail = prev;

        delete curr;
        return;
    }
};

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
   int choice = 0;
   LinkedList* chad = new LinkedList();

   do
   {
       cout << "select an operation, free of charge ;) : \n";
       cout << "1) add\n2) print\n3) remove\n4) exists\n5) exit\n";

       cin >> choice;

       if(choice == 1)
       {
           cout << "what value would you like me to add dude :) : ";
           int val;
           cin >> val;

           chad->insert(val);
       }
       else if(choice == 2)
       {
           chad->print_list();
       }
       else if(choice == 3)
       {
           cout << "which value needs to be put in timeout? : ";
           int val;
           cin >> val;

           chad->remove(val);
       }
       else if(choice == 4)
       {
           cout << "which element are we searching for :D? : ";
           int val;
           cin >> val;

           if(chad->exists(val))
           {
               cout << "THERE HE IS!";
           }
           else
           {
               cout << "yea either he doesn't exist, or he has the best hiding spot ever.";
           }
           cout << "\n";
       }
       else break;
   }
   while(choice!=5);
}