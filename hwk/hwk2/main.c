#include "stdio.h"
#include "hw1.c"

//Including limiting array length to the below define 
//This is so somebody doesn't try to put 2^31-1 as the length
#define MAX_ARRAY_LENGTH 512


int main(void)
{
  int i = 0;
  char reverse_succeed = 0;
  
  //given char arr that should be inputted by user (to be updated)
  char arr[17] = "This is a string.";
  //char arr[18] = "some NUMmbers12345";
  //char arr[30] = "Does it reverse \n\0\t correctly?"; 
  
   //Just for testing
   //char arr[5] = "\0\0\0\0\0"; 

  //Specifically to check that the array is not completely null characters \0
  //This is something I don't believe to be reasonable to reverse as it will not output anything useful
  int all_null = 0;

  printf("Given str array:\n");

  for(i = 0; i<sizeof(arr); i++) {
    printf("%c",arr[i]);
    //check for how many nulls found in array
    if(arr[i]=='\0') {
      all_null++;
    }
  }
  printf("\n\n");

  if(sizeof(arr) < 1) {
    printf("Error: Array length must be greater than 0\n");
    reverse_succeed = 1;
  } else if (sizeof(arr) > MAX_ARRAY_LENGTH) {
    printf("Error: Array length must be equal to or less than %d\n", MAX_ARRAY_LENGTH);
    reverse_succeed = 3;
  } else if (all_null == sizeof(arr)){
    printf("All null character string not allowed\n");
    reverse_succeed = 4;
  } else {
    char* ptr = arr;
    reverse_succeed = reverse_string(ptr,sizeof(arr));
  }
  return reverse_succeed;
}

