#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
  int value;
  struct Node * next;
};

int main(void) {
  struct Node * head = (struct Node*)malloc(sizeof(struct Node));
  head->next=NULL;
  char mystr [100];
  while (scanf("%s", mystr)!=EOF){
    if (strcmp(mystr, "push-front")==0){
      int n;
      scanf("%d", &n);
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode->next=head;
      tempnode->value=n;
      head=tempnode;
      printf("%d\n", n);
    }else if (strcmp(mystr, "dump")==0){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      if (head->next==NULL){
        printf("empty\n");
      }else{
      while(tempnode->next!=NULL){
        printf("%d ",tempnode->value);
        tempnode=tempnode->next;
      }
      printf("\n");}
    }else if(strcmp(mystr, "push-back")==0){
      int n;
      scanf("%d", &n);
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      while (tempnode->next!=NULL)tempnode=tempnode->next;
      tempnode->next=(struct Node *)malloc(sizeof(struct Node));
      tempnode->value=n;
      printf("%d\n", n);
    }else if(strcmp(mystr, "clear")==0){
      while (head->next!=NULL){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      head=head->next;
      free(tempnode);
      }
      printf("empty\n");
    }else if(strcmp(mystr, "peek-front")==0){
      if (head->next==NULL){printf("empty\n");}else{
      printf("%d\n", head->value);}
    }else if(strcmp(mystr, "peek-back")==0){
      if (head->next==NULL){printf("empty\n");}else{
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      while(tempnode->next->next!=NULL)tempnode=tempnode->next;
      printf("%d\n", tempnode->value);}
    }else if(strcmp(mystr, "pop-front")==0){
      if(head->next==NULL){printf("empty\n");}else{
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      printf("%d\n", head->value);
      head=head->next;
      free(tempnode);}
    }/*else if(strcmp(mystr, "pop-back")==0){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      while(tempnode->next->next->next!=NULL)tempnode=tempnode->next;
      printf("%d\n",tempnode->next->value);
      free(tempnode->next);
      tempnode->next->next=NULL;
    }*/else if(strcmp(mystr, "size")==0){
      int n=0;
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      while(tempnode->next!=NULL){tempnode=tempnode->next;n++;};
      printf("%d\n", n);
    }else printf("unknown operation %s\n", mystr);
  }
  return 0;
}
