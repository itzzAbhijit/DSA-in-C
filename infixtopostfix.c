#include <stdio.h>
#include <string.h>
#define SIZE 50

typedef struct {
    char arr[SIZE];
    int tos;
} stack;

// Initialize stack
void init(stack *s) {
    s->tos = -1;
}

// Check if stack is full
int isFull(stack *s) {
    if (s->tos == SIZE - 1)
        return 1;
    else
        return 0;
}

// Check if stack is empty
int isEmpty(stack *s) {
    if (s->tos == -1)
        return 1;
    else
        return 0;
}

// Push to stack
int push(stack *s, char val) {
    if (isFull(s)) {
        printf("Stack is full, push is failed\n");
        return 0;
    } else {
        s->tos++;
        s->arr[s->tos] = val;
        return 1;
    }
}

// Pop from stack
int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, pop is failed\n");
        return -999;
    } else {
        int val = s->arr[s->tos];
        s->tos--;
        return val;
    }
}

// Get precedence of operator
int preced(char ch) {
    if (ch == '/' || ch == '*' || ch == '%')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

// Peek top of stack
int peek(stack *s) {
    return s->arr[s->tos];
}

// Convert infix to postfix
char* convert(char in[]) {
    int i, j = 0;
    stack s;
    init(&s);
    static char out[SIZE];

    for (i = 0; in[i] != '\0'; ++i) {
        if ((in[i] >= '0' && in[i] <= '9') || (in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z')) {
            out[j++] = in[i];
        } else {
            switch (in[i]) {
                case '(': 
                    push(&s, in[i]);
                    break;

                case ')': {
                    char t = pop(&s);
                    while (t != '(') {
                        out[j++] = t;
                        t = pop(&s);
                    }
                    break;
                }

                default:
                    while (isEmpty(&s) == 0 && preced(peek(&s)) >= preced(in[i])) {
                        out[j++] = pop(&s);
                    }
                    push(&s, in[i]);
            }
        }
    }

    while (isEmpty(&s) != 1) {
        out[j++] = pop(&s);
    }

    out[j] = '\0';
    return out;
}

// Main function
int main() {
    char in[SIZE];
    printf("Enter the Infix:\n");
    fgets(in, sizeof(in), stdin);
    in[strcspn(in, "\n")] = '\0'; // Remove newline

    printf("The Infix to Postfix Conversion is:\n");
    char *output = convert(in);
    printf("The Postfix is: %s\n", output);

    return 0;
}