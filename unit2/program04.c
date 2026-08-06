#include<stdio.h>
#include<conio.h>

#define max 5
int stack[max];
int top = -1;
void push(int value)
{

    if (top== max-1){
        printf("\nstack overflow");
  }
   else
   {
       top++;
       stack[top]=value;
          }
    }



    void peep(int pos)
    {

        int index;
        if(top == -1)
        {
            printf("\nstack underflow");
            return;
        }
        index =top -pos +1;
if(index<0){
    printf("\ninvalid position ");}
else{
    printf("\nelement at position %d=%d",pos,stack[index]);
    }
    }

    void main()
    {
        int pos;
        push(10);
        push(20);
        push(30);
        push(40);

        printf("\n enter position from top:");
        scanf("%d",&pos);
        peep(pos);
        getch();

    }



