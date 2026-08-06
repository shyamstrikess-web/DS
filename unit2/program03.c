#include <stdio.h>
#include <conio.h>
#define max 5
 int stack[max];
 int top = -1;
 void push(int value)

 {
 if (top== max -1)
    {
    printf("\nstack overflow");

 }
else
    {
    top++;
    stack[top]=value;

}
}
void peek(){
if(top==-1){
    printf("\n stack underflow");}
    else
    printf("\n top element=%d",stack[top]);

}
   void main(){
   push(10);
   push(20);
   push(30);

   peek();

   getch();



   }
