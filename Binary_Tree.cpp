#include<iostream>

using namespace std;

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

TreeNode* newTreeNode(int val){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* createBTree(int arr[], int i, TreeNode* root, int n){
    if(i<n){
        TreeNode* temp = newTreeNode(arr[i]);
        root = temp;
        root->left = createBTree(arr, 2*i+1, root->left, n);
        root->right = createBTree(arr, 2*i+2, root->right, n);
    }
    return root;    
}

void preorder(TreeNode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    cout<<"Enter number of elements:";
    int n;
    cin>>n;
    cout<<"Enter the elements:\n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode *root = createBTree(arr,0,root,n);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}