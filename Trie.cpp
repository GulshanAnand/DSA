#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        Node* child[26];
        bool isEnd = false;
        Node(){
            for(int i=0;i<26;i++) child[i] = NULL;
        }
};

//Any one declaration of Node works
// class Node{
//     public: 
//         vector<Node*> child = vector<Node*>(26, NULL);
//         bool isEnd = false;
// };

class Trie{
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* currNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (currNode->child[idx] == NULL) 
                currNode->child[idx] = new Node();
            currNode = currNode->child[idx];
        }
        currNode->isEnd = true;
    }
    
    bool search(string word) {
        Node* currNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (currNode->child[idx] == NULL) return false;
            currNode = currNode->child[idx];
        }
        return currNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* currNode = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';
            if (currNode->child[idx] == NULL) return false;
            currNode = currNode->child[idx];
        }
        return true;
    }
};

int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("cat");
    obj->insert("app");
    obj->insert("code");

    cout<<obj->startsWith("app")<<'\n';
    cout<<obj->startsWith("pq")<<'\n';
    cout<<obj->search("app")<<'\n';
    cout<<obj->search("cat")<<'\n';
    cout<<obj->startsWith("cattt")<<'\n';
    cout<<obj->startsWith("cat")<<'\n';

    return 0;
}