#include <iostream>
#include <stack>
#include<queue>

using namespace std;

void desempilha();

stack<int> stkops;
queue<int> qchar;


int lookahead(){
    int lh = getchar();

    if(isspace(lh)){lh = getchar();}
    return lh;
}

void desempilha(){
    while(!stkops.empty()){
        std::cout << char(stkops.top());
        stkops.pop();
    }
}
void desenfilera(){
    while(!qchar.empty()){
        std::cout << char(qchar.front());
        qchar.pop();
    }
}



int main(int argc, char** argv){

auto c = lookahead();
while(c != EOF){

if(c == '+' or c == '-' or c == '*' or c== '/'){
    stkops.push(c);
}else if(isdigit(c)){
    qchar.push(c);
}

    c = lookahead();
}

desempilha();
desenfilera();

std::cout<<endl;


    return 0;
}