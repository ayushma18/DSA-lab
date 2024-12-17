#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE ];
int top = -1;
void push(int item){
if (top == MAX_SIZE - 1){
    printf("overflow! stack is full");

}
else{
    stack[++top]=item;
    scanf("%d inserted item" & item);


}
}
void pop(){
    if ()
}
