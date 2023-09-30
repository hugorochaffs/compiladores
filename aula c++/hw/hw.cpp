#include <iostream>

using namespace std;

void R();
void S();
void erro();
int lookahead;

void reconhecer(int c){
    if(lookahead == c)
        lookahead = getchar();
    else
        erro();
}

void erro(){
    std::cout<<"Erro Sintático"<<endl;
}

void S() {
    if(lookahead == 't' or lookahead == 'f'){
        reconhecer(lookahead);
        R();
    } 
    else{
        erro();
    }
        
}

void R(){
    if(lookahead == '^'){
        reconhecer('^');
        S();
    }
}

void parser(){
    lookahead = getchar();
    S();
}

int main(int argc, char** argv){

parser();

    return 0;
}