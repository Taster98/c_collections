#ifndef SORT_H
#define SORT_H
#endif
#ifndef STDIO_H
#define STDIO_H
#endif
#ifndef STDLIB_H
#define STDLIB_H
#endif

/*Linked List*/

//structure with 'generic' information type
struct elem{
	void *info;
	struct elem *next;
};
//single elementof the list
typedef struct elem Element;
//complete list of Element-s
typedef Element *List;

//function to add an element in head of list
void headAdd(List *l, void *el,size_t size){
	List new = malloc(sizeof(Element));
    new->info = malloc(size);
	new->info = el;
	new->next = *l;
    //i assume char is 1 byte:
    for(int i=0;i<size;i++)
        *(char *)(new->info + i) = *(char *)(el+i);
	*l = new;
}
//function to add an element in tail of list
void tailAdd(List *l, void *el, size_t size){
    List new = malloc(sizeof(Element));
    new->info = malloc(size);
	new->info = el;
	new->next = NULL;
	if(!(*l)){
        //i assume char is 1 byte:
        for(int i=0;i<size;i++)
            *(char *)(new->info + i) = *(char *)(el+i);
		*l = new;
	}else{
		List curr = *l;
		while(curr->next){
			curr = curr->next;
		}
        //i assume char is 1 byte:
        for(int i=0;i<size;i++)
            *(char *)(new->info + i) = *(char *)(el+i);
		curr->next = new;
	}
}
//function that reverse a list
List reverseList(List head){
   List result = NULL;
   while(head){
       Element *next = head->next;
       head->next = result;
       result = head;
       head = next;
   }
   return result;
}

//function that get size of list
int size(List head){
    Element *curr = head;
    int c=0;
    while(curr != NULL){
        c++;
        curr=curr->next;
    }
    return c;
}
//function to print all the list:
void printList(List l, void (*fptr)(void *)){ 
    while (l != NULL) 
    { 
        (*fptr)(l->info); 
        l = l->next; 
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