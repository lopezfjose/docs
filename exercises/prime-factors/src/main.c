
#include "example.h"


int main()
{
   // TODO: Refactor input? If necessary
   // Int test_number;

   // printf("Enter test number from 0 to %d: \n", INT32_MAX);
   // scanf("%d", &test_number);
   // getchar();

   // printf("Number to factor: %d\n", test_number);

   /** Super shitty implementation. I konw I only have to search up to the square
    *  root of the number, but I'm just freestyling here. I'm mostly just
    *  experimenting, getting my feet wet with C again for now.
    * 
    */

   //Int test_factor = 2;

   /** Having to instantiate a fraction to be able to use the functions might have
    *  been a terrible design flaw actually. Not really sure what I was thinking.
    * 
    */

   // printf("Is %d prime? ", test_number);
   // if (prime0(test_number) == true) {
   //    printf("yes\n");
   // } else {
   //    printf("no\n");
   // }

   Int n = DEFAULT_INITIALIZATION;

   printf("Please enter number to factor: ");
   scanf("%d", &n);
   
   PrimeFactorization(n);

   return EXIT_SUCCESS;
}