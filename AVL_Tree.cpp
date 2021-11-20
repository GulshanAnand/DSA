#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
typedef struct node node; 

int height(node* p){
    if (p == NULL) return 0;
    return p->height;
}

int getBalanceFactor(node *p){
    if (p == NULL) return 0;
    return height(p->left) - height(p->right);
}

node* newNode(int val){
    node* p = (node*)malloc(sizeof(node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

node* inorderSucc(node* p){
    node* curr = p;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

node* LLrotation(node *A){
    node *B = A->left;
    node *C = B->right;
    B->right = A;
    A->left = C;
    A->height = max(height(A->left),height(A->right)) + 1;
    B->height = max(height(B->left),height(B->right)) + 1;
    return B;
}

node* RRrotation(node *A){
    node *B = A->right;
    node *C = B->left;
    B->left = A;
    A->right = C;
    A->height = max(height(A->left),height(A->right)) + 1;
    B->height = max(height(B->left),height(B->right)) + 1;
    return B;
}

node* insert_into_Tree(node* p, int val){
    if(p == NULL) return newNode(val);
    if(val < p->data) p->left = insert_into_Tree(p->left, val);
    else if(val > p->data) p->right = insert_into_Tree(p->right, val);
    else return p;
 
    p->height = 1 + max(height(p->left),
                        height(p->right));

    int balance = getBalanceFactor(p);

    if(balance > 1 && val < p->left->data) return LLrotation(p);
    if(balance < -1 && val > p->right->data) return RRrotation(p);
    if(balance > 1 && val > p->left->data){
        p->left = RRrotation(p->left);
        return LLrotation(p);
    }
    if(balance < -1 && val < p->right->data){
        p->right = LLrotation(p->right);
        return RRrotation(p);
    }
    return p;
}

node* delete_from_Tree(node* root, int val){
    if(root == NULL) return root;
    if(val < root->data) root->left = delete_from_Tree(root->left, val);
    else if(val > root->data) root->right = delete_from_Tree(root->right, val);
    else{
        if((root->left == NULL) || (root->right == NULL)){
            node *temp = root->left ? root->left : root->right;
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else{
            node* temp = inorderSucc(root->right); 
            root->data = temp->data;
            root->right = delete_from_Tree(root->right,temp->data);
        }
    }
    if(root == NULL) return root; 

    root->height = 1 + max(height(root->left), height(root->right)); 
    int balance = getBalanceFactor(root); 

    if(balance > 1 && getBalanceFactor(root->left) >= 0) return LLrotation(root);
    if(balance > 1 && getBalanceFactor(root->left) < 0){
        root->left = RRrotation(root->left);
        return LLrotation(root);
    }
    if(balance < -1 && getBalanceFactor(root->right) <= 0) return RRrotation(root);
    if(balance < -1 && getBalanceFactor(root->right) > 0){
        root->right = LLrotation(root->right);
        return RRrotation(root);
    }
    return root;
}

void preOrder(node *root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main(){
    node *root = NULL;

    int n;
    cout<<"Enter the number of nodes to be inserted: ";
    cin>>n;
    cout<<"Enter the node-values: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        root = insert_into_Tree(root, temp);
    }

    cout<<"\nPreorder traversal: ";
    preOrder(root);
    cout<<"\nInorder traversal: ";
    inOrder(root);
    cout<<"\nPostorder traversal: ";
    postOrder(root);

    cout<<"\n\nEnter the number of nodes to be deleted: ";
    cin>>n;
    cout<<"Enter the node-values to be deleted: ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        root = delete_from_Tree(root, temp);
    }

    cout<<"\nPreorder traversal: ";
    preOrder(root);
    cout<<"\nInorder traversal: ";
    inOrder(root);
    cout<<"\nPostorder traversal: ";
    postOrder(root);

    return 0;
}