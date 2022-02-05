#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
char get_op();
float get_num();
float m_exp(float sub_exp, char op);
float s_exp(void);
char ch;
float x;
char y;
int main(){
    bool isTrue=true;
    char s;
    while (isTrue){
        printf("Enter an arithmetic expression: ");
        x = get_num();
        y = get_op();
        printf("Result of expression: %.2f\n", s_exp());
        printf("Do you want to continue to enter a new expression? \n");
        scanf(" %c", &s);
        if(s!='Y'){
            break;
        }
    }
}
// Input: none, the s_expression will be read in from stdin
// Effect: the s_expression is evaluated using
// a while loop or a do while loop:
// repeatedly get num with m_exp() and then get op with
// get_op() while op is ’+’ or ’-’; when op is ’\n’, exit loop.
// Output: this function returns the value of the s_expression.
float s_exp(void) {
    float s_expression;  // x is op
    float num;
    bool isTrue=true;
    float result;
    while(isTrue){
        num=m_exp(x, y);
        y=get_op();
        x=get_num();
        if(get_op() == '+'){
            int nums=get_num();
            result = num+nums;
            isTrue=false;
        }else if(get_op() == '-'){
            int nums=get_num();
            result = num-nums;
            isTrue=false;
        }
        else if (get_op()== '\n') {
            break;
        }
    }
    return result;
}
// Input: ’sub_exp’: the value of the current sub m_expression
// to the left of ’op’ location in stdin.
// ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
// ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
// "+’, ’-’, or ’\n’ should be pushed back to stdin.
// the rest of the m_expression will be read in from stdin
// Effect: the m_expression is evaluated using recursion:
// get next_num with get_num() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the current m_expression.
float m_exp(float sub_exp, char op) {
    float next_sub_exp;
    if(op =='+' || op == '-' || op == '\n'){
        ungetc(op, stdin);
        return sub_exp;
    }else if (op == '*' || op == '/'){
        x=get_num();
        y = get_op();
        if(op=='/'){
            next_sub_exp=sub_exp/x;
        }else if(op=='*'){
            next_sub_exp=sub_exp*x;
        }
        return m_exp(next_sub_exp, y);
    }
}
// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() {
    if(ch=='/')
        return ch;
    else if (ch=='*')
        return ch;
    else if (ch == '+')
         return ch;
    else if(ch == '-')
        return ch;
    else if(ch=='\n')
        return ch;
}
// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() {
    char str[50];
    int i=0;
    while((ch = getc(stdin)) != EOF && ch != '\n' && (isdigit(ch) || ch == '.')) {
        if(isdigit(ch)) {
            str[i]=ch;
            i++;
        }else if(ch == '.'){
            str[i]=ch;
            i++;
        }
    }
    float c;
    c = atof(str);
    return c;
}
