/*
 * Bracket Validation Using Stack
 * 
 * This program validates whether brackets in an expression are properly balanced using a stack.
 * It checks for three types of brackets: (), {}, and [] and ensures each opening bracket
 * has a corresponding closing bracket in the correct order. The algorithm uses a stack to
 * track opening brackets and validates matches when closing brackets are encountered.
 * Input consists of an expression string containing brackets and other characters.
 * Output indicates whether the brackets are balanced or not balanced.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct sNode {
    char data;
    struct sNode* next;
};

void push(struct sNode** top_ref, char new_data) {
    struct sNode* new_node = new sNode;
    if (!new_node) {
        cout << "Stack overflow\n";
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

char pop(struct sNode** top_ref) {
    if (*top_ref == NULL) {
        return '\0'; // stack underflow
    }
    struct sNode* top = *top_ref;
    char res = top->data;
    *top_ref = top->next;
    delete top;
    return res;
}

bool isMatchingPair(char character1, char character2) {
    return (character1 == '(' && character2 == ')') ||
           (character1 == '{' && character2 == '}') ||
           (character1 == '[' && character2 == ']');
}

bool areBracketsBalanced(char exp[]) {
    struct sNode* stack = NULL;  // empty stack
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        // if opening bracket → push
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        }
        // if closing bracket → check match
        else if (c == ')' || c == '}' || c == ']') {
            if (stack == NULL) {
                return false; // closing bracket without opening
            }
            char topChar = pop(&stack);
            if (!isMatchingPair(topChar, c)) {
                return false;
            }
        }
    }
    // stack should be empty if balanced
    return stack == NULL;
}

int main() {
    char exp[100];
    cin >> exp;

    cout << "Expression: " << exp << endl;
    if (areBracketsBalanced(exp))
        cout << "Brackets are balanced";
    else
        cout << "Brackets are not balanced";
    return 0;
}
