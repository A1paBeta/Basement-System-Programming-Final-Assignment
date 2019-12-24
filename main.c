#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define Registration 1
#define ShowAll 2
#define Delete 3
#define FindByInBirth 4
#define Exit 5

#define COUNT_SHOW 1000
#define COUNT_HIDDEN 1001

typedef struct Node{
  char *name, *phone, *birth;
  struct Node *nextNode;
}Node;

typedef struct LinkedList{
  Node *head, *tail;
  int length;
}LinkedList;

LinkedList *linkedList;

void initialize(){
  linkedList = (LinkedList *)malloc(sizeof(LinkedList));
  linkedList->head = NULL;
  linkedList->tail = NULL;
  linkedList->length = 0;
}
void swapFunction(char **str, char **str2){
  char *temp = *str;
  *str = *str2;
  *str2 = temp;
}
void sortList(LinkedList *list){
  struct Node *temp = list->head;
  for(int i=0;i<linkedList->length;++i){
    Node *temp2 = list->head;
    for(int j=0;j<linkedList->length;++j){
      if(strcmp(temp->name, temp2->name) > 0){
        swapFunction(&temp->name, &temp2->name);
        swapFunction(&temp->phone, &temp2->phone);
        swapFunction(&temp->birth, &temp2->birth);
      }
      temp2 = temp2->nextNode;
    }
    temp = temp->nextNode;
  }
}

void addNodeInList(char *pName, char *pPhone, char *pBirth, int mode){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->nextNode = NULL;
  newNode->name = (char *)malloc(sizeof(char)*21);
  newNode->name = pName;
  newNode->phone = (char *)malloc(sizeof(char)*16);
  newNode->phone = pPhone;
  newNode->birth = (char *)malloc(sizeof(char)*9);
  newNode->birth = pBirth;

  if(linkedList->head == NULL && linkedList->tail == NULL){
    linkedList->head = newNode;
    linkedList->tail = newNode;
  }else {
    linkedList->tail->nextNode = newNode;
    linkedList->tail = newNode;
  }

  linkedList->length++;
  if(mode == COUNT_SHOW){
    printf("count: %d\n", linkedList->length);
  }
  sortList(linkedList);
}

void loadFileData(){

  int accessRes = access("user.txt",0);
  if(accessRes == 0){
    FILE *fp = (FILE *)fopen("user.txt", "r");
    int userNum;

    fscanf(fp, "%d", &userNum);
    for(int i=0;i<userNum;++i){
      char *name = (char *)malloc(sizeof(char)*21);
      char *phone = (char *)malloc(sizeof(char)*16);
      char *birth = (char *)malloc(sizeof(char)*9);

      fscanf(fp, " %s %s %s", name, phone, birth);
      addNodeInList(name, phone, birth, COUNT_HIDDEN);
    }
  }
}

void writeFileData(){
  FILE *fp = (FILE *)fopen("user.txt", "w");
  fprintf(fp, "%d\n", linkedList->length);
  
  Node *temp = linkedList->head;
  while(temp){
    fprintf(fp, "%s %s %s\n", temp->name, temp->phone, temp->birth);
    temp = temp->nextNode;
  }
}
void showAllNodesInList(){
  struct Node *temp = linkedList->head;

  while(temp != NULL){
    printf("%s %s %s\n", temp->name, temp->phone, temp->birth);
    temp = temp->nextNode;
  }
}

void doRegistration(){
  printf("Name:");  // 고정
  char *name = (char *)malloc(sizeof(char)*21);
  scanf(" %s", name);
  printf("Phone number:"); // 고정
  char *phone = (char *)malloc(sizeof(char)*16);
  scanf(" %s", phone);
  printf("Birth:"); //고정
  char *birth = (char *)malloc(sizeof(char)*9);
  scanf(" %s", birth);

  addNodeInList(name, phone, birth, COUNT_SHOW);
}

void deleteNodeByInName(){

  if(linkedList->length == 0){
    printf("No record founded.\n");
    return;
  }
  printf("Name:");
  char *name = (char *)malloc(sizeof(char)*21);
  scanf(" %s",name);

  if(linkedList->length == 0) return;
  else if(linkedList->length == 1){
    if(strcmp(linkedList->head->name, name) == 0){
      free(linkedList->head);
      linkedList->head = NULL;
      linkedList->tail = NULL;
      linkedList->length--;
      writeFileData();
      return;
    }
  }
  else{
    Node *prevNode = linkedList->head, *nowNode = linkedList->head;
    while(nowNode){
      if(strcmp(nowNode->name,name) == 0){
        if(prevNode == nowNode){
          linkedList->head = linkedList->head->nextNode;
          free(nowNode);
        }else {
          prevNode->nextNode = nowNode->nextNode;
          free(nowNode);
        }
        linkedList->length--;
        writeFileData();
        return;
      }else {
        if(prevNode == nowNode){
          nowNode = nowNode->nextNode;
        }else {
          nowNode = nowNode->nextNode;
          prevNode = prevNode->nextNode;
        }
      }
    }
  }
}

void findByInBirth(){
  int birth;
  printf("Birth:");
  scanf("%d",&birth);

  Node *temp = linkedList->head;
  if(1<= birth && birth<10){
    while(temp){
      if(temp->birth[5] == birth+'0'){
        printf("%s %s %s\n",temp->name, temp->phone, temp->birth);
      }
      temp = temp->nextNode;
    }
  }else {
    while(temp){
      if(temp->birth[4] == birth/10+'0' && temp->birth[5] == birth%10+'0'){
        printf("%s %s %s\n",temp->name, temp->phone, temp->birth);
      }
      temp = temp->nextNode;
    }
  }
}

short showCommand(){
  printf("*****Menu*****\n");
  printf("1. Registration, 2. ShowAll, 3. Delete, 4. FindByBirth, 5. Exit\n");
  printf("Enter the menu number:");

  int command;
  scanf("%d",&command);

  switch(command){
    case Registration :
      doRegistration();
      break;
    case ShowAll :
      showAllNodesInList();
      break;
    case Delete :
      deleteNodeByInName();
      break;
    case FindByInBirth :
      findByInBirth();
      break;
    default :
      writeFileData();
      break;
  }

  return command;
}

int main(void){
  initialize();
  loadFileData();
  while(showCommand() != Exit){}
}
