#include <stdio.h>
#include<stdlib.h>

int main() {
    
    struct stacknode{
        char value;
        struct stacknode *next;
    };
    
    struct stacknode *topstack=NULL;
    
    void push(char element){
        struct stacknode *newnode;
        newnode=(struct stacknode *)malloc(sizeof(struct stacknode));
        newnode->value=element;
        newnode->next=topstack;
        topstack=newnode;
    }
    
    
    void pop(){
        struct stacknode *tempnode;
        tempnode=topstack;
        topstack=topstack->next;
        free(tempnode);
    }
    
    void display(){
        
        while(topstack!=NULL){
            printf("%c",topstack->value);
            topstack=topstack->next;
        }
        
    }
    
   //Prefix Evaluation
   
   char prefixexp[11]={'-','+','2','*','3','2','/','8','^','2','3'};
   
    char newchar;
   for(int i=10;i>=0;i--){
       
       if(prefixexp[i]=='-' || prefixexp[i]=='+' || prefixexp[i]=='*' || prefixexp[i]=='/' || prefixexp[i]=='^'){
           
           char op1=topstack->value;
           char op2=topstack->next->value;
           int value;
           
           if(prefixexp[i]=='+'){
               
               int val = op1 - '0';
               int newval=op2-'0';
               
                value=val+newval;
                newchar=value+'0';
           }
           else if(prefixexp[i]=='-'){
               
                int val = op1 - '0';
                int newval=op2-'0';
               
                value=val-newval;
                newchar=value+'0';
           }
           else if(prefixexp[i]=='*'){
                int val = op1 - '0';
                int newval=op2-'0';
               
                value=val*newval;
                
               newchar=value+'0';
           }
           else if(prefixexp[i]=='/'){
               
                int val = op1 - '0';
                int newval=op2-'0';
               
                value=val/newval;
                newchar=value+'0';
           }
           else if(prefixexp[i]=='^'){
               
               int expression=1;
               
                int val =op1-'0';
                int newval=op2-'0';
                
               
               for(int i=0;i<newval;i++){
                   expression*=val;
               }
                value=expression;
                newchar=value+'0';
                
           }
           
           pop();pop();
           push(newchar);
       }
       else{
           push(prefixexp[i]);
       }
       
   }
  
   printf("%c",newchar);
    
}
