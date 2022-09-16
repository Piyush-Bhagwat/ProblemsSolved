#include<iostream>
using namespace std;

class List{
    public:
        List* next;
        int data;

        List(){}
        List(int n){
            next = NULL;
            data = n;
        }
};

void insertAtStart(List* &head, int n){
    List* newNode = new List(n);

    if(head == NULL){
        head =  newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void display(List* head){
    while(head != NULL){
        cout<<head->data;
        if(head->next != NULL){
            cout<<", ";
        }
        head=head->next;
    }
    cout<<endl;
}

main(){
    List* hd = NULL;

    while(true){
        int n;
        cout<<"Enter a num: ";
        cin>>n;
        if(cin.fail()){ //if non int is inputed loop will end
            cout<<"If you insert non iterger program will stop \n";
            break;
        }
        insertAtStart(hd, n);
    }

    cout<<"final List: "; 
    display(hd);

}