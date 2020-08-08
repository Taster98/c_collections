#ifndef SORT_H
#define SORT_H
#endif
#ifndef STDIO_H
#define STDIO_H
#endif
#ifndef STDLIB_H
#define STDLIB_H
#endif

/*Double Linked Dlist*/

//structure with 'generic' information type
struct delem{
	void *info;
	struct delem *next;
    struct delem *prev;
};
//single Delement of the Dlist
typedef struct delem Delement;
//complete Dlist of Delement-s
typedef Delement *Dlist;

//function to add an Delement in head of Dlist
void dHeadAdd(Dlist *l, void *el,size_t size){
	Dlist new = malloc(sizeof(Delement));
    new->info = malloc(size);
	new->info = el;
    new->prev = NULL;
	new->next = *l;
    //i assume char is 1 byte:
    for(int i=0;i<size;i++)
        *(char *)(new->info + i) = *(char *)(el+i);
	*l = new;
}
//function to add an Delement in tail of Dlist
void dTailAdd(Dlist *l, void *el, size_t size){
    Dlist new = malloc(sizeof(Delement));
    new->info = malloc(size);
	new->info = el;
	new->next = NULL;
	if(!(*l)){
        new->prev=NULL;
        //i assume char is 1 byte:
        for(int i=0;i<size;i++)
            *(char *)(new->info + i) = *(char *)(el+i);
		*l = new;
	}else{
		Dlist curr = *l;
		while(curr->next){
			curr = curr->next;
		}
        new->prev = curr;
        //i assume char is 1 byte:
        for(int i=0;i<size;i++)
            *(char *)(new->info + i) = *(char *)(el+i);
		curr->next = new;
        
	}
}
//function that get size of Dlist
int dSize(Dlist head){
    Delement *curr = head;
    int c=0;
    while(curr != NULL){
        c++;
        curr=curr->next;
    }
    return c;
}
//function to print all the Dlist:
void printDlist(Dlist l, void (*fptr)(void *)){ 
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