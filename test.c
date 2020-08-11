#include <stdio.h>
#include <stdlib.h>
#include "taster/utils/sort.h"
#include "taster/utils/list.h"
#include "taster/utils/doublelist.h"
#include "taster/utils/queue.h"
#include "taster/utils/debug.h"
#include "taster/utils/error.h"

int main(){
    int n=5;
    char *arr[] = { "word1", "word2", "word3", "word4", "word5" };
    printf("Unsorted array:\n");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
    qsort(arr,n,sizeof(char*),compareStringDesc);
    printf("\nSorted array:\n");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
    printf("\n");
    List l = NULL;
    char *a = "hello";
    char *b = "world";
    char *c = "gcc";
    headAdd(&l,&a,sizeof(char*));
    headAdd(&l,&b,sizeof(char*));
    tailAdd(&l,&c,sizeof(char*));
    printList(l, printString);
    //reverted list
    l=reverseList(l);
    printList(l, printString);
    printf("%d\n",size(l));

    Dlist l2 = NULL;
    int e=1;
    int f=2;
    int g=3;
    dHeadAdd(&l2,&e,sizeof(int));
    dHeadAdd(&l2,&f,sizeof(int));
    dTailAdd(&l2,&g,sizeof(int));
    printDlist(l2,printInt);
    printf("%d\n",dSize(l2));
    //QUEUE TEST
    Queue q;
    initQueue(&q,sizeof(char));
    char el = 'c';
    int ret = enqueue(&q,&el);
    printQueue(q,printChar);
    //debug test
    print("Ciao");
    println("Ciao");
    printI("Ciao",4);
    printF("Ciao",7.3);
    printC("Ciao",'w');
    printD("Ciao",3.14);
    printLog("Wewe amigo");
    printFile("test.dat","We ciao amico");
    printFileM("test.txt","a","Ciaone amicone");
    return 0;
}
