#include<iostream>

using namespace std;

struct node{
    int data;
    node* link;
};
typedef struct node node;

void insertAtTail(node* head, int data);
void display(node* head);
node* createLinkedList(int n);
void insertAtHead(node* &head, int data);
void insert(node* head, int data, int k);

void display(node* head){
    cout<<"Current list is:\n";
    node *p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->link;
    }
}

node* createLinkedList(int n){
    cout<<"Enter data seperated by spaces:\n";
    node* head = new node;
    int tmp;
    cin>>tmp;
    head->data = tmp;
    head->link = NULL;
    for(int i=1;i<n;i++){
        int data;
        cin>>data;
        insertAtTail(head, data);
    }
    return head;
}

void insertAtTail(node* head, int data){
    node* p = head;
    node* tmp = new node;
    tmp->data = data;
    tmp->link =NULL;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = tmp;
}

void insertAtHead(node* &head, int data){
    node* tmp = new node;
    tmp->data = data;
    tmp->link = head;
    head = tmp;
}

void insert(node* head, int data, int k){
    node* tmp = new node;
    tmp->data = data;
    node* p = head;
    while(--k > 1){
        p = p->link;
    }
    tmp->link = p->link;
    p->link = tmp;
}

int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    node *head = createLinkedList(n);
    display(head);
    int res;
    cout<<"\n1 : insert at head\n2 : insert at tail\n3 : insert at n\n";
    cin>>res;
    if(res == 1){
        cout<<"Enter data:";
        int data;
        cin>>data;
        insertAtHead(head, data);
    }
    else if(res == 2){
        cout<<"Enter data:";
        int data;
        cin>>data;
        insertAtTail(head, data);
    }
    else if(res == 3){
        cout<<"Enter data:";
        int data;
        cin>>data;
        cout<<"Enter position:";
        int pos;
        cin>>pos;
        insert(head, data, pos);
    }
    else cout<<"Invalid choice\n";
    display(head);
    return 0;
}