#include "stdio.h"
#include "hw1.h"

char reverse_string(char * str, int length) {
  char compare_array[length];
  char hold;
  int i = 0;
  int j = 0;
  int rem = length % 2;
  int error = 0;


  if (length < 1) {
    printf("Error: Length must be greater than 0");
    error = 1;
  } else {
    //printf("Implement a copy of str array for comparison check:\n");
    for(i = 0; i<length; i++) {
      compare_array[i] = *(str+i);
      //printf("%c",compare_array[i]);
    }
    //printf("\n\n");

    //switch positions of characters up to length/2+remainder
    for(i = 0; i<length/2+rem; i++) {
      
      /*Uncomment for string debugging
       *printf("current str reverse: ");
       *for(j = 0; j<length; j++) {
       *  printf("%c",*(str+j));
       *}
       *printf("\n");
       */
      
      hold = *(str+i);
      *(str+i) = *(str+(length-1-i));
      *(str+(length-1-i)) = hold;
    }
    
    
    printf("Output str array in reverse in chars:\n");
    for(i = 0; i<length; i++) {
      printf("%c",*(str+i));
      if(compare_array[length-1-i] != *(str+i)) {
	error=2;
	printf("\nReverse comparison failed");
	break;
      }
    }
    printf("\n\n");
    printf("Output str array in reverse as a string:\n%.*s\n\n",length,str);

    //Uncomment below line for error debugging
    //printf("error: %c",error);
    return error;
  }

}
