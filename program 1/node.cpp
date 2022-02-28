/************************************************************************
 *          Jamil Omer                                                  *
 *          Node class-                                                 *
 *          Includes: get_value, set_next, get_next                     *
 * **********************************************************************/

#include<iostream>

using namespace std;

class Node{
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
