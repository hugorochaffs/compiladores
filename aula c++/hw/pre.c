#include <stdio.h>
#include <stdlib.h>

int lookahead;

int next_token()
{
    return getchar();
}

void erro()
{
    fprintf(stderr, "erro sintático\n");
    exit(-1);
}

void reconhecer(int c)
{
    if (lookahead == c)
        lookahead = next_token();
    else
        erro();
}

void R();

void A()
{
    reconhecer('b');
    R();
}

void R()
{
    if (lookahead == 'a')
    {
        reconhecer('a');
        R();
    }
}

void parser()
{
    lookahead = next_token();

    A();

    if (lookahead != '\n' && lookahead != EOF)
        erro();
}

int main()
{
    parser();

    return 0;
}
