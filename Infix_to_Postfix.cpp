#include<iostream>

using namespace std;

char st[50];
int tp = 0;

int ISP(char s);
int ICP(char s);
string infixToPostfix(string s);

void push(char item){
    st[tp] = item;
    tp++;
}

char pop(){
    tp--;
    return st[tp];
}

char top(){
    return st[tp-1];
}

int ISP(char s){
    if(s == '^') return 3;
    else if(s == '*' || s == '/') return 2;
    else if(s == '+' || s== '-') return 1;
    else if(s == '(') return 0;
    else if(s == '$') return -1;
}

int ICP(char s){
    if(s == '^') return 4;
    else if(s == '*' || s == '/') return 2;
    else if(s == '+' || s== '-') return 1;
    else if(s == '(') return 4;
}

string infixToPostfix(string e){
    string res = "";
    push('$');
    for(int i=0;i<e.size();i++){
        char x = e[i];
        if(x == '#'){
            while(tp > 1){
                res = res + pop();
            }
            return res;
        }
        else if((x >= 97 && x <= 122) || (x >= 48 && x <= 57)){
            res = res + x;
        }
        else if(x == '('){
            push(x);
        }
        else if(x == ')'){
            while(top() != '('){
                res = res + pop();
            }
            pop();
        }
        else if(x == '*'||x=='/'||x=='+'||x=='-'||x=='^'){
            while(ISP(top()) >= ICP(x)){
                res = res + pop();
            }
            push(x);
        }
    }
    while(top() != '$'){
        res = res + pop();
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<infixToPostfix(s)<<endl;
    // for(int i=0;i<tp;i++){
    //     cout<<st[i]<<" ";
    // }
    return 0;
}