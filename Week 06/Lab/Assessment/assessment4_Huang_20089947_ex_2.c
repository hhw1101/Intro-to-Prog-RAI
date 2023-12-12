/*
Jennifer Huang
20089947
Assessment 4 Exercise 2
13/11/2023
*/

#include <stdio.h>

int
main ()
{
  //part a
  int arrayLength;
  printf ("Enter the size of array: ");
  scanf ("%d", &arrayLength);

  int inputNumbers[arrayLength];
  puts ("Enter the elements of array: ");
  for (int i = 0; i < arrayLength; i++)
    {
      scanf ("%d", &inputNumbers[i]);
    }
  printf ("The entered array is: ");
  for (int i = 0; i < arrayLength; i++)
    {
      printf ("%d ", inputNumbers[i]);
    }

  //part b
  int search, position = 0;
  printf ("\nEnter the element to search: ");
  scanf ("%d", &search);

  for (int i = 0; i < arrayLength; i++)
    {
      if (search == inputNumbers[i])
	{
	  position = i + 1;
	  break;
	}
    }
  if (position == 0)
    {
      printf ("\n%d is not found in the array.", search);
    }
  else
    {
      printf ("\n%d is present at position %d.", search, position);
      //part c
      //This prints the array without the searched element
      printf ("\nThe array after deletion is: ");
      for (int i = 0; i < arrayLength; i++)
	{
	  if (search != inputNumbers[i])
	    {
	      printf ("%d ", inputNumbers[i]);
	    }
	}

      for (int i = position - 1; i < arrayLength; i++)
	{
	  if (i != arrayLength)
	    {
	      inputNumbers[i] = inputNumbers[i + 1];

	    }
	  else
	    {
	      inputNumbers[i] = 0;
	    }
	}
      // This version removes the searched element
      printf ("\nThe array after deletion is: ");
      for (int i = 0; i < arrayLength - 1; i++)
	{
	  printf ("%d ", inputNumbers[i]);
	}
    }


  return 0;
}
