# C Library Collection
## What is
This is a collection of all common Data Structures, debug functions and so on for the C language. It is splitted between Sorting Functions, Data Structures, Error Functions, Debug Functions.
## Usage
To use it you can simply clone this repo and copy the folder named "taster" to your directory. Then you will need to include the headers file you want to your project, such as:

```
#include "[your/directory]/taster/utils/[header_name].h"
```
And there it is! You can check for a full test implementation here: <a href ="test.c" alt="Test">Test</a>
## Documentation
### Sorting Functions
These are some useful sorting functions to use for example with qsort in C. There are implemented the various <i>compare</i> functions for the most common data structures, <i>int, float, double, char and char*</i>.
* ```compareIntAsc(int x, int y)``` --> it is the function used to sort integers with qsort function (ascending order)
* ```compareIntDesc(int x, int y)``` --> it is the function used to sort integers with qsort function (descending order)
* ```compareFloatAsc(float x, float y)``` --> it is the function used to sort float with qsort function (ascending order)
* ```compareFloatDesc(float x, float y)``` --> it is the function used to sort float with qsort function (descending order)
* ```compareDoubleAsc(double x, double y)``` --> it is the function used to sort double with qsort function (ascending order)
* ```compareDoubleDesc(double x, double y)``` --> it is the function used to sort double with qsort function (descending order)
* ```compareCharAsc(char x, char y)``` --> it is the function used to sort char with qsort function (ascending order)
* ```compareCharDesc(char x, char y)``` --> it is the function used to sort char with qsort function (descending order)
* ```compareStringAsc(char \*x, char \*y)``` --> it is the function used to sort char* with qsort function (ascending order)
* ```compareStringDesc(char \*x, char \*y)``` --> it is the function used to sort char\* with qsort function (descending order)
Example of usage:
```
//integer array 'arr' of 'n' elements in descending order
qsort(arr,n,sizeof(int),compareIntDesc);
```

### Data Structures
There are many data structures usually useful when programming. There are also some useful functions in each data structure file:

#### Single Linked List
Single linked list are the most simple dynamic data structures which exist. Here, they are implemented as:
```
struct elem{
	void *info;
	struct elem *next;
};

typedef struct elem Element;

typedef Element *List;
```  
So the data type is 'generic', and there are also some useful functions:
* ```void headAdd(List *l, void *el,size_t size)``` --> which adds an element <i>el</i> of type (void \*) to the beginning of the list. The third parameter is the size of the element (which you can fetch by using sizeof function in stdlib).
* ```void tailAdd(List *l, void *el, size_t size)``` --> which adds an element <i>el</i> at the end of the linked list.
* ```List reverseList(List head)```--> which returns the reverted list pointed by head.
* ```int size(List head)```-->which returns the number of elements of the given list.
* ```void printList(List l, void (*fptr)(void *))```-->which prints a list in the format: &nbsp; ``` el1->el2->..->NULL```. The second parameter is a function pointer to the function which prints the correct type of data: 
    * ```void printInt(void *n)```-->to print integers
    * ```void printFloat(void *n)```-->to print float
    * ```void printDouble(void *n)```-->to print double
    * ```void printChar(void *n)```-->to print char
    * ```void printString(void *n)```-->to print string
#### Double Linked List
Double linked list is a type of linked list in which each node apart from storing its data has two links. The first link points to the previous node in the list and the second link points to the next node in the list.
```
struct delem{
	void *info;
	struct delem *next;
    struct delem *prev;
};
typedef struct delem Delement;
typedef Delement *Dlist;
```
The functions are the same as single linked list:
* ```void dHeadAdd(List *l, void *el,size_t size)``` --> which adds an element <i>el</i> of type (void \*) to the beginning of the list. The third parameter is the size of the element (which you can fetch by using sizeof function in stdlib).
* ```void dTailAdd(List *l, void *el, size_t size)``` --> which adds an element <i>el</i> at the end of the linked list.
* ```int dSize(List head)```-->which returns the number of elements of the given list.
* ```void printDlist(List l, void (*fptr)(void *))```-->which prints a list in the format: &nbsp; ``` el1->el2->..->NULL```. The second parameter is a function pointer to the function which prints the correct type of data: 
    * ```void printInt(void *n)```-->to print integers
    * ```void printFloat(void *n)```-->to print float
    * ```void printDouble(void *n)```-->to print double
    * ```void printChar(void *n)```-->to print char
    * ```void printString(void *n)```-->to print string

#### Queue
The queue is a well known data structure always used in all programming languages to handle different problems.
```
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
```
There are the useful following functions:
* ```initQueue(Queue *q, size_t sz)```--> which initialize a queue with elements of size sz.
* ```deleteQueue(Queue *q)```--> which deletes queue q and free its memory.
* ```enqueue(Queue *q, const void *data)```--> which insert an element into the queue and returns 0 if ok, -1 on error.
* ```dequeue(Queue *q, void *data)``` --> which removes the first element of the queue and free its memory.
* ```sizeQueue(Queue *q)``` --> which returns queue length
* ```printQueue(Queue q, void (*fptr)(void *))``` --> equals to the lists function print, it prints the queue by taking a function as argument based on which type of element you want to print.

### Debug Handlers
Here there are a little collection of debug functions which may be useful and shorter than C already existing functions:
* ```println(char *s)``` --> prints the string s and a \n
* ```print(char *s)``` --> prints the string s without \n
* ```printI(char *s, int i)``` --> prints the string s and int i
* ```printF(char *s,float f)```--> prints the string s and float f
* ```printD(char *s,double d)```--> prints the string s and double d
* ```printC(char *s,char c)```--> prints the string s and char c
* ```printLog(char *output)```--> prints the string output into a file named logfile.log
* ```printFile(char *filename, char *output)``` --> prints the string output to the file named filename
* ```printFileM(char *filename, char *openmode, char *output)``` --> prints the string output to the  file named filename with the mode openmode (w for write, a for append, wb for write bit, see ``` man fopen ``` for more).

### Error Handlers
As for debug handlers, here there are some useful error macro handlers which may be useful to better handler errors:
* ```#define ec_less1(s,m)``` --> used to print -1 errors
* ```#define ec_zero(s,m)``` --> used to print 0 errors
* ```#define ec_null(s,m)``` --> used to print NULL errors
## To be continued...
## LICENSE
This software is completely free; see <a href="LICENSE">GNU General Public License</a>.