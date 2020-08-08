typedef struct Elem{
  void *data;
  struct Elem *next;
}elem;

typedef struct QueueSet{
    int size;
    size_t size_memb;
    elem *head;
    elem *tail;
}Queue;

//function that creates queue
void initQueue(Queue *q, size_t sz){
    q->size = 0;
    q->size_memb = sz;
    q->head = q->tail = NULL;
}

//function that deletes the queue
void deleteQueue(Queue *q){
    elem *tmp;
    while(q->size > 0){
        tmp = q->head;
        q->head = tmp->next;
        free(tmp->data);
        free(tmp);
        q->size--;
    }
    q->head = q->tail = NULL;
}

//function that adds an element into the queue
int enqueue(Queue *q, const void *data){
    elem *newElem = (elem *)malloc(sizeof(elem));
    //ERRORS
    if(newElem == NULL){
        return -1;
    }
    newElem->data = malloc(q->size_memb);
    if(newElem->data == NULL){
        free(newElem);
        return -1;
    }
    newElem->next = NULL;
    memcpy(newElem->data, data, q->size_memb);
    if(q->size == 0){
        q->head = q->tail = newElem;
    }
    else{
        q->tail->next = newElem;
        q->tail = newElem;
    }
    q->size++;
    return 0;
}
//function that remves element from the queue
void dequeue(Queue *q, void *data){
    if(q->size > 0){
        elem *temp = q->head;
        memcpy(data, temp->data, q->size_memb);
        if(q->size > 1){
            q->head = q->head->next;
        }
        else{
            q->head = NULL;
            q->tail = NULL;
        }
        q->size--;
        free(temp->data);
        free(temp);
    }
}

//function to get queue size
int sizeQueue(Queue *q){
    return q->size;
}

//function that prints the queue
//function to print all the list:
void printQueue(Queue q, void (*fptr)(void *)){ 
    while (q.head != NULL) 
    { 
        (*fptr)(q.head->data); 
        q.head = q.head->next; 
    } 
    printf("NULL\n");
} 
#ifndef DEFINED
//function to print an integer 
void printInt(void *n){ 
   printf("%d->", *(int *)n); 
}
//function to print a float 
void printFloat(void *n){ 
   printf("%f->", *(float *)n); 
}
//function to print a double 
void printDouble(void *n){ 
   printf("%lf->", *(double *)n); 
}
//function to print a char 
void printChar(void *n){ 
   printf("%c->", *(char *)n); 
}
//function to print a string 
void printString(void *n){ 
   printf("%s->", *(char **)n); 
}
#define DEFINED
#endif