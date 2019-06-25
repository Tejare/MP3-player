#include <stdio.h>
#include <stdlib.h>
 

 
 
 /*
Created by:Tejas Paranjape(35)
            Vinit Pardhi(36)
            Vaibhav Pudke(40)
            Rajat Pattu(39)
 
AIM:To make a user friendly mp3 payer using the concepts of Queues and GUI 
 */
/*
    initialize queue pointers
*/
void init(int *head, int *tail)
{
    *head = *tail = 0;
}
 
/*
   enqueue a song
   precondition: the queue is not full
*/


void enqueue(int *q,int *tail, int element)
{
    q[(*tail)++] = element;
}
 
 //To swap two songs

void swap(int *q,int *head,int ele1,int ele2) 
{
    int temp=q[ele1];
    q[ele1]=q[ele2];
    q[ele2]=temp;
} 
 
 
/*
    dequeue a song
    precondition: queue is not empty
*/

int dequeue(int *q,int *head)
{
    return q[(*head)++];
}
 
/*
    return 1 if queue is full, otherwise return 0
*/
int full(int tail,const int size)
{
    return tail == size;
}
 
/*
  return 1 if the queue is empty, otherwise return 0
*/
int empty(int head, int tail)
{
    return tail == head;
}
 
/*
  display queue content
*/
void display(int *q,int head,int tail)
{
    int i = tail - 1;
    while(i >= head)
    {
        
        printf("%d ",q[i--]);
        
    }
    
    printf("\n");
}
 
 

 
int main()
{
    const int SIZE = 5; /* queue's size */
    
    int head, tail, element;
    
    int queue[SIZE];
 
    init(&head,&tail);//Function to initialise the queue
 
    printf("--Enqueue songs--\n");
    //Details about the songs available
    printf("Songs available:\n1 : Tum hi ho \n2 : Dheere dheere se  \n3 : Teri Deewani  \n4 :Mere Rashke Qamar  \n5 : Swag se Swagat \n You may repeatedly listen to your favourite songs too!!\n ");
   
    /* push elements into queue */
   
    while(!full(tail,SIZE))
    {   
        printf("Enter a number to enqueue (Between 1 and 5):");
        
        scanf("%d",&element);
        
        if(element>5||element<1)
        {
        do{
            printf("Not a valid response.Please enter a number between 1 and 5\n");
            
            scanf("%d",&element);
            
            
        }while(element>5||element<1);
        
            
        }
        
        //Call the function enqueue to insert another element into the queue
        
        enqueue(queue,&tail,element);
        
        //Call the function display to display the contents of the queue
        
        display(queue,head,tail);
    }
    printf("Playlist is complete!!\n\n");
    
    int i=0;
    
    
    //Menus to swap two songs
    
    do{
            printf("Do you want to swap any songs?\nPress 1 if 'yes' and 2 if 'no'.\n");
            
            scanf("%d",&i);
            
      }while(!(i==1||i==2));
        
        
    do{
        
        
        int ele1=0;
        int ele2=0;
        
        if(i==1)
        {
            
            printf("Enter the song numbers of the songs to be swapped\n");
            
            scanf("%d%d",&ele1,&ele2);
            
            ele1--;ele2--;//The arrays start from 0
        }
        
        
        swap(queue,&head,ele1,ele2);
        
        if(i==1)
        {
        do{
            i=0;
            
            printf("Do you want to swap any more songs?\nPress 1 if yes and 2 if no.\n");
            
            scanf("%d",&i);
            
        }while(!(i==1||i==2));
        
            
        }
        
    }while(i==1);

    
    //To play the songs in the sequence that is given
    
    printf("--Play songs --\n");
    
    while(!empty(head,tail))//Call to function 'empty' which will return a true or a false value
    {
        element = dequeue(queue,&head);
        //To take out songs from the queue one by one
        printf("Playing song %d \n",element);
        //To display the remaining contents of the queue
        display(queue,head,tail);
    }
    
    printf("Have a good day!!\n");
    
    //Queue is empty
    
    return 0;
}