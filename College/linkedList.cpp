#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
        }
        Node(int n){
            data = n;
            next=NULL;
        }
};

class LinkedList{
    private: 
        Node* header = NULL;
    
    public:
        void insterAtStart(int n){
            Node* newNode = new Node(n);

            if(header == NULL){
                header = newNode;
                return;
            }
            newNode->next = header;
            header = newNode;
        }

        void display(){
            Node* temp = header;
            while(temp!= NULL){
                cout<<temp->data;
                if(temp->next != NULL){
                    cout<<", ";
                }
                temp= temp->next;
            }
            cout<<endl;
        }
};



main()
{
    LinkedList hed;

    hed.insterAtStart(6);
    hed.insterAtStart(5);
    hed.insterAtStart(8);
    hed.insterAtStart(6);
    hed.insterAtStart(3);
    hed.display();

    return 0;
}