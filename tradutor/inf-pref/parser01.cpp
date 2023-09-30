//parser para a expressao S-> 0S1 | 01
#include <iostream>

using namespace std;

int lookahead(){
    int c  = getchar();
    return c;
}

void S(){
    int look = lookahead();
    if(look == '0'){
        S();
    }
    else if(look == '1'){
        
    }
    else{
        std::cout<<"ERRO"<< endl;
    }
}
int main(int argc , char** argv){


    S();





    return 0;
}