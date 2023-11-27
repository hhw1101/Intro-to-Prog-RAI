# Dynamic Memory Allocation and Sorting

## Pointers and arrays
Accessing arrays using pointers
~~~
*(B+i) = B[i]
*(*(B+i)+j) = B[i][j]
*(*(*(B+i)+j)+k) = B[i][j][k]
~~~

## Static Memory Allocation

This is **memory allocated** during the compile time. This is **fixed** and cannot be changed in the run time.
This causes issues as this **wastes** memory if values stored uses less memory, and if **more** memory is needed then this can crash the program or create strange behaviours.

## Dynamic Memory Allocation

<font size="4"> This allocates memory at the time of execution (run time).</font>

Main benefits of DMA is with *limited* static memory, using DMA allows for more efficient use of memory resources and avoides memory fragmentation.

### Stack Vs Heap
![Memory Diagram](stack.png) ![Diagram representation of stack vs heap memory](diagram.png)

Memory is an **ordered** list of locatiosn with unique addresses to store data.

#### Stack

Regular Variables are stored on the stack

- As more memory is needed for variables the data is *stacked* in **order** right next to the  memory for existing variables.

A stack is memory that is allocated to store data of functions when called, once the function ends this memory is then freed up to be reused. The memory is allocated in a orderly fashion which makes using stacks fast and automatic.

Note: a recursion function creates new stacks for each call of the function.

Stack memory Definintions

StackOverflow
>The stack is the memory set aside as scratch space for a thread of execution. When a function is called, a block is reserved on the top of the stack for local variables and some bookkeeping data. When that function returns, the block becomes unused and can be used the next time a function is called. The stack is always reserved in a LIFO (last in first out) order; the most recently reserved block is always the next block to be freed. This makes it really simple to keep track of the stack; freeing a block from the stack is nothing more than adjusting one pointer. - [StackOverFlow Question](https://stackoverflow.com/a/80113)

Baeldung.com
> 
>In programming, whenever a function is called, the program generates a new stack memory block for the function to utilize. This type of memory is located in the stack section of a program’s memory space, which is a reserved restricted memory area. This section is usually located at the top of the memory space and grows downward as more data is added.
> 
>**Stack memory employs an automatic allocation and deallocation of memory that stores temporary data created by functions or procedures.** Stack memory uses a “Last In, First Out” (LIFO) data structure, meaning that the most recently added item is the first to be removed. When the function or procedure is finished executing, the stack memory block is released automatically, and the program returns to the previous point of execution.
> 
>Stack memory is useful in managing memory usage as it avoids memory leaks due to its architecture. Moreover, the stack may overflow and crash in the case of many nested function calls. - [Baeldung.com](https://www.baeldung.com/cs/memory-stack-vs-heap)


### Heap

Heap memory is used for DMA which is managed manually. This is useful to store data structres with unknown size. This is more flexible than stack and is adjustable during the runtime. However this can lead to issues such as memory leaks.

Baeldung.com
>**Compared to stack memory, heap memory operates dynamically, which basically means that the program can allocate and deallocate memory areas of different sizes when necessary.** This allocation/deallocation of memory depends on the requirements that arise during runtime.
>
>A program’s memory space consists of a heap section, which is reserved only for a program’s heap memory. The size of the heap partition is not fixed and can be dynamically adjusted at runtime.
>
>In addition, heap memory is not associated with a specific function or process. **The data in heap memory is not arranged in any specific pattern and can be reached in any order.** Throughout a program’s runtime, only useful areas of memory are retained in heap memory.
>
>Consequently, heap memory is suitable for dealing with large, complex data structures such as tables, linked lists, and trees and facilitates memory sharing between different program parts.
>
>Although, occasionally, heap memory may be more challenging and lead to memory leaks or other memory-related errors.

## Pointers and DMA

Pointers play an important role in DMA. Allocated memory can only be accessed via pointers. 

There are 4 functions that is used for DMA in the \<stdlib.h\> library:
1.  malloc()
2.  calloc()
3.  realloc()
4.  free()

### malloc()
Memory Allocation
This allocates a single large block of continuous memory.
Syntax:
~~~
(void*)malloc(size_t)    // size_t - unsigned int
// size_t is the number of bytes needed/memory locations, this depends on the length of the data type, typecasted.
~~~
This function returns a pointer to the first byte of the allocated memory if successful, otherwise NULL.

Use case: often when required memory size is unknown till runtime.

The pointer needs to be typecasted after being called as only memory is allocated and not the data type.

Examples:
~~~
//Allocating float type memory
ptr = (float *)malloc(40);      // allocates 10 float type slots.
//Allocating double type memory
ptr = (double *)malloc(80);     // allocates 10 double type slots.
//Allocating long type memory
ptr = (long *)malloc(40);       // allocates 5 long type slots.
//Allocating char type memory
ptr = (char *)malloc(10);       // allocates 10 char type slots.
~~~

### calloc()
Clear Allocation

This allocates a specified number of blocks of memory, each of a specific size.

Syntax:
~~~
(void *) calloc(size_t num_elements, size_t element_size)
~~~

calloc() returns a pointer to the first bute of the allocated memory if successfule otherwise it is NULL.

This differs from malloc() by taking 2 parameters instead of one. There there is no need to calculate the size of malloc(). And instead of having random values in the array all the data is set to 0 until changed.

![calloc vs malloc](table.png)

The main issue with malloc and calloc is, when used recursively using the same pointer type variable then the old infomation is lost.

~~~
int *ptr;
ptr = (int *)malloc(44); // 11 elements memory
ptr[0] = 3; ip[6] = 6; 
ptr = (int *)malloc(52);// 13 elements memory
ptr = (int *)realloc(ptr,52);// correct syntax
~~~

### realloc()
Reallocation

Changes the size of the memory block a solution the the above issue. The function returns a pointer to the resized memory block. If the reallocation fails then NULL is returned and the original block remains the same.

Syntax:
~~~
(void *) realloc(void *ptr, size_t new_size)
~~~

Moves the contents of the old block to a new block

 * Increase or decrease the size of the block.
 * If the new size is larger, the content of the old block is preserved up to the original size.
 * If the new size is smaller, the excess data is truncated. 

Newly allocated bytes are uninitialized and contains garbage values.

### free()
free() releases the dynamically allocated memory in the heap (forgetting the memory in the code).

<font  size="3">**Importance**</font>
Memory needs to be deallocated to prevent memory leaks.

Syntax:
~~~
(void *) free(void *ptr) // This takes a pointer and deallocated the memory from the pointer.
~~~

### Memory Leaks

Memory leaks occur when dynamically allocated memory is not release before program termination.
This leads to *inefficient memory usage*, *reduced performance*. In extreme cases the *program crashes* due to lack of memory availability.

Once the pointer is deallocated it is best practise to assign the pointer to NULL rather than leave the pointer as a "floating" pointer.

## Sorting

Sorting and searching is one of the most common parts of any programming system
There are many common sorts:
 * Bubble sort
 * Quick sort
 * Insertion sort
 * Selection sort
 * Merge sort

### Bubble Sort

A bubble sort compares two elements that are next to one another, they switch positions if the number on the left is larger than the one on the right (if sorting to find ascending order)
This can be done with strings in C using *strcmp*. Using the returned value then you can switch accordingly.
