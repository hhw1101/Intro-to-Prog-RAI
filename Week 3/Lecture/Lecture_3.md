# Lecture 3

## Arrays and Strings

### Arrays

Arrays are a collection of similar data types.
This is a convenient way to store multiple values of the same data type under a single identifier.

Declaration Example:
 > datatype arrayName[arraySize];
 <br>
 int numbers[5];

Multiple arrays can be defiined in one line as long as they are of the same type.

> int b[100], x[23];

Arrays do not need to be initialized at declaration. If not defined then random values are assigned to array. 
To initialize the array curly brackets are used. Additionally, the size of the array can be omitted and determined when initialized.
> int numbers[5] = {2,3,4,5,6};

### Strings

A string is a one dimensional array of characters. The string needs to be terminated by a null, which is '\0'. This appears at the end of every string which means the array size is always one character longer.

> char string1[] = "hello";<br>
// The code below is how the string is stored.<br>
 char string1[] = {'h','e','l','l','o','\0'};



## Functions