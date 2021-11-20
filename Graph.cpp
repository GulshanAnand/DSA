#include<iostream>

using namespace std;
#define MAX_VERTICES 50

struct gnode {
    int vertex;
    struct gnode *link;
};
typedef struct gnode graph_node;

graph_node* graph[MAX_VERTICES];
int n=0;
short int visited[MAX_VERTICES];

//Queue start
int arr[100];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear >= 19){
        cout<<"queue full\n";
        return;
    }
    rear++;
    if(front == -1) front = rear;
    arr[rear] = x;
}

int dequeue(){
    if(front == -1){
        cout<<"queue empty\n";
        return -1;
    }
    
    int res = arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return res;
    }
    front++;
    if(front == rear){
        arr[0] = arr[front];
        front = 0;
        rear = 0;
    }
    return res;
}

bool isempty(){
    if(rear == -1){
        return true;
    }
    return false;
}
//Queue end

//Stack start
int st[MAX_VERTICES];
int tp = 0;

void push(int a){
    st[tp] = a;
    tp++;
}

int pop(){
    tp--;
    return st[tp];
}
//Stack end

void addDirEdge(int a, int b){
    graph_node* temp = (graph_node*)malloc(sizeof(graph_node));
    temp->vertex = b;
    temp->link = NULL;
    graph_node* p = graph[a];
    if(p != NULL){
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
    else{
        graph[a] = temp;
    }
    n++;
}

void addEdge(int a, int b){
    graph_node* temp = (graph_node*)malloc(sizeof(graph_node));
    temp->vertex = b;
    temp->link = NULL;
    graph_node* p = graph[a];
    if(p != NULL){
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
    else{
        graph[a] = temp;
    }

    temp = NULL;
    temp = (graph_node*)malloc(sizeof(graph_node));
    temp->vertex = a;
    temp->link = NULL;
    p = graph[b];
    if(p != NULL){
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
    else{
        graph[b] = temp;
    }
    n++;
}

void delEdge(int a, int b){
    graph_node* temp = graph[a];
    if(temp->vertex == b){
        graph[a] = temp->link;
        free(temp);
    }
    else{
        while(temp->link->vertex != b){
            temp = temp->link;
        }
        graph_node *del = temp->link;
        temp->link = del->link;
        free(del);
    }

    temp = graph[b];
    if(temp->vertex == a){
        graph[b] = temp->link;
        free(temp);
    }
    else{
        while(temp->link->vertex != a){
            temp = temp->link;
        }
        graph_node *del = temp->link;
        temp->link = del->link;
        free(del);
    }
}

void dfs(int v){
    graph_node *w;
    visited[v]= 1;
    cout<<v<<" ";
    for(w=graph[v]; w; w=w->link){
        if (!visited[w->vertex])
        dfs(w->vertex);
    }  
}

bool hasCycle(int v, int parent){
    graph_node *w;
    visited[v]= 1;
    bool cyclic = false;
    for(w=graph[v]; w; w=w->link){
        if(visited[w->vertex] && w->vertex == parent) continue;
        if (visited[w->vertex]) return true;
        cyclic |= hasCycle(w->vertex, v);
    }
    return cyclic;
}

void bfs(int v){
    graph_node *w;
    cout<<v<<" ";
    visited[v] = 1;
    enqueue(v);
    while(!isempty()){
        v = dequeue();
        for(w=graph[v]; w; w=w->link){
            if(!visited[w->vertex]){
                cout<<w->vertex<<" ";
                enqueue(w->vertex);
                visited[w->vertex] = 1;
            }
        }
    }
}

void refresh(){
    for(int i=0;i<MAX_VERTICES;i++){
        visited[i] = 0;
    }
    tp = 0;
}

void dfs_top(int v){
    graph_node *w;
    visited[v]= 1;
    for(w=graph[v]; w; w=w->link){
        if (!visited[w->vertex])
        dfs_top(w->vertex);
    }
    push(v);  
}

void topsort(){
    for(int i=0;i<MAX_VERTICES;i++){
        if(graph[i] != NULL){
            if(visited[i]) continue;
            dfs_top(i);
        }
    }
    cout<<"Topological sorting is: ";
    while(tp != 0){
        cout<<pop()<<" ";
    }
    cout<<endl;
}

int main(){
    // addEdge(0, 1);
    // addEdge(0, 2);
    // addEdge(1, 2);
    // addEdge(2, 0);
    // addEdge(2, 3);
    // addEdge(3, 4);
    // addEdge(5, 5);
    // addEdge(0, 4);

    // addEdge(0, 1);
    // addEdge(0, 7);
    // addEdge(0, 8);
    // addEdge(1, 5);
    // addEdge(8, 5);
    // addEdge(7, 5);
    // addEdge(8, 9);
    // addEdge(8, 4);

    addDirEdge(1,2);
    addDirEdge(1,3);
    addDirEdge(2,3);
    addDirEdge(2,4);
    addDirEdge(2,5);
    addDirEdge(3,5);
    addDirEdge(4,5);
    addDirEdge(4,6);
    addDirEdge(5,6);

    //dfs call:
    for(int i=0;i<MAX_VERTICES;i++){
        if(graph[i] != NULL){
            if(visited[i]) continue;
            dfs(i);
        }
    }
    refresh();
    cout<<endl;
    //bfs call:
    for(int i=0;i<MAX_VERTICES;i++){
        if(graph[i] != NULL){
            if(visited[i]) continue;
            bfs(i);
        }
    }
    refresh();
    cout<<endl;
    //check for cycle:
    for(int i=0;i<MAX_VERTICES;i++){
        if(graph[i] != NULL){
            if(visited[i]) continue;
            if(hasCycle(i, -1)){
                cout<<"Graph is cyclic.";
                break;
            }
        }
    }
    refresh();
    cout<<endl;
    //topsort:
    topsort();
    return 0;
}