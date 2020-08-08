# C Library Collection
## What is
This is a collection of all common Data Structures, debug functions and so on for the C language. It is splitted between Sorting Functions, Data Structures, Error Functions, Debug Functions, File Functions.
## Usage
To use it you can simply download this tarball:
```
wget 
```
Now, you should extract it and choose which one you want to extract, specifying the command:<br>
1) ``` make install files ``` --> create .h file for file management
2) ``` make install structures ``` --> create .h file for common data structures
3) ``` make install errors ``` --> create .h file for error handlers
4) ``` make install debug ``` --> create .h file for debug handlers
5) ``` make install sorting ``` --> create .h file for sorting functions and stuff
6) ``` make install all ``` --> create all .h files

Once you installed, the h files will be generated into a folder called <i>taster/utils</i>, so you will simply have to import them into your C source file by using:
```
#include "taster/utils/[header_name].h"
```
## Documentation
### Sorting Functions
These are some useful sorting functions to use for example with qsort in C. There are implemented the various <i>compare</i> functions for the most common data structures, <i>int, float, double, char and char*</i>.
* compareIntAsc(int x, int y) --> it is the function used to sort integers with qsort function (ascending order)
* compareIntDesc(int x, int y) --> it is the function used to sort integers with qsort function (descending order)
* compareFloatAsc(float x, float y) --> it is the function used to sort float with qsort function (ascending order)
* compareFloatDesc(float x, float y) --> it is the function used to sort float with qsort function (descending order)
* compareDoubleAsc(double x, double y) --> it is the function used to sort double with qsort function (ascending order)
* compareDoubleDesc(double x, double y) --> it is the function used to sort double with qsort function (descending order)
* compareCharAsc(char x, char y) --> it is the function used to sort char with qsort function (ascending order)
* compareCharDesc(char x, char y) --> it is the function used to sort char with qsort function (descending order)
* compareStringAsc(char \*x, char \*y) --> it is the function used to sort char* with qsort function (ascending order)
* compareStringDesc(char \*x, char \*y) --> it is the function used to sort char\* with qsort function (descending order)
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
Doubly linked list is a type of linked list in which each node apart from storing its data has two links. The first link points to the previous node in the list and the second link points to the next node in the list.
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

## To be continued...
## LICENSE
This software is completely free; see <a href="LICENSE">GNU General Public License</a>.