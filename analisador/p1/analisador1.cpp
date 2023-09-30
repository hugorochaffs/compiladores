/*Analisador preditivo top down para a linguagem:
A-> bBR
R-> aR | vazio
B -> Ab | a
*/

#include <iostream>


using namespace std;

void A();
void B();
void R();

int lookahead;



void erro(){
    cout<< "erro detectado" << endl;
    exit(-1);
}

void reconhecer(int a){
    if(lookahead == a)
        lookahead = getchar();
    else{
        cout<< "erro em reconhecer"<<endl;
        erro();
    }
    
}

void A(){

    if(lookahead == 'b'){
            reconhecer('b');
            B();
            R();
            }else{
                cout<< "erro em A"<<endl;
                erro();
            }

    }
       


    


void R(){

    if(lookahead == 'a'){
        reconhecer('a');
        R();
    }
}

void B(){
    if(lookahead == 'a'){
        reconhecer('a');
    }else{
        A();
        if(lookahead== 'b'){
            reconhecer('b');
        }else{
            cout<< "erro em B"<<endl;
            erro();
        }
    }
}

void parser(){
    lookahead = getchar();

    A();
    if(lookahead != '\n'&& lookahead != EOF)
        erro();
}

int main (int argv, char** argc){

    parser();

    return 0;
}