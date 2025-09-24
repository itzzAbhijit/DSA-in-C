#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <string.h>
#define SIZE 50

// Stack definition
typedef struct {
    int arr[SIZE];
    int tos;  // Top of stack
} stack;

// Stack initialization
void init(stack *s) {
    s->tos = -1;
}

// Check if stack is empty
int isEmpty(stack *s) {
    return s->tos == -1;
}

// Check if stack is full
int isFull(stack *s) {
    return s->tos == SIZE - 1;
}

// Push value into stack
void push(stack *s, int val) {
    if (!isFull(s)) {
        s->arr[++(s->tos)] = val;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop value from stack
int pop(stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->tos)--];
    } else {
        printf("Stack Underflow!\n");
        return 0;
    }
}

// Evaluate postfix expression
int evaluate(char post[]) {
    stack s;
    init(&s);
    int op1, op2, res = 0;

    for (int i = 0; post[i] != '\0'; i++) {
        char ch = post[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');  // convert char to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        return 0;
                    }
                    res = op1 / op2; 
                    break;
            }

            push(&s, res);
        }
    }

    return pop(&s);
}

// Main function
int main() {
    char in[SIZE];
    
    printf("Enter the postfix expression (e.g. 53+62/*): ");
    scanf("%s", in);  // use scanf for simple input without spaces

    int output = evaluate(in);
    printf("The Postfix Evaluation Result is: %d\n", output);

    return 0;
}
