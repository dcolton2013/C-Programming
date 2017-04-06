/*
* WeightConverter.c
*
*/


#include<stdio.h>


int main()
{
  float weightInPounds = 165.8;
  char weightUnit;
  scanf("%c", &weightUnit);
  switch(weightUnit){
   	case 'p':
  	case 'P':
                   printf("%f pounds \n", weightInPounds);
                   break;
  	case 'o':
    case 'O':
                   printf("%f ounces \n", 16.0 * weightInPounds);
                   break;
    case 'g':
  	case 'G':
                   printf("%f grams \n", 454.0 * weightInPounds);
                   break;
    default:
   		             printf("that unit is not handled");
  		             break;
  }
return 0;
}
