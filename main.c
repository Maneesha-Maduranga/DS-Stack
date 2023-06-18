//Linked list Implementation of Stacks

#include<stdio.h>
#include<stdlib.h>

typedef int stackentry;

typedef struct{

 stackentry entry;
 struct Node *next;

}Node;

typedef enum {TRUE,FALSE} Boolean;


typedef struct{
 int no_ele;
 Boolean full;
 Node *top;
}stack;

void CreateStack(stack *s){
 s->no_ele=0;
 s->full = FALSE;
 s->top= NULL;
}

Boolean IsStackEmpty(stack *s){
 return(s->top == NULL);
}

Boolean IsStackFull(stack *s){
 return s->full;
}


void pop(stackentry *item, stack *s){
  Node *np;
 *item = s->top->entry;
  np = s->top;
  s->top = s->top->next;
  s->no_ele--;
  free(np);
}

void push(stackentry item, stack *s){
 Node *np;
 np = (Node *)malloc(sizeof(Node));
 if(np == NULL){
    printf("Not Enough Memory");
    s->full = TRUE;
 }
 else{
    np->entry=item;
    np->next = s->top;
    s->top = np;
    s->no_ele++;
 }
}

void main(){

    int fullornot,value;
    stack M;

    CreateStack(&M);
    push(1,&M);
    push(2,&M);
    pop(&value,&M);
    pop(&value,&M);
    printf("%d",IsStackEmpty(&M));
    printf("%d",value);


}
