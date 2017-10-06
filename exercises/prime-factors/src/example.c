/** File Name:    example.c
 * 
 *  Author:       Jose Fernando Lopez Fernandez
 * 
 *  Date:         06-October-2017
 *  
 *  Description:  This file contains the implementation details for the
 *                prime_factors exercise. I have done my best to document this
 *                project and write simple, understandable code.
 * 
 *                If you have any questions or just need to reach me for
 *                anything, email is the best way to contact me, at
 *                jflopezfernandez@gmail.com
 * 
 */

#include "example.h"


// Prime Factorization Algorithm
// While n != 1 do begin p = LD(n); n = n / p END

/** Function:     Get Greatest Common Denominator
 *  
 *  Description:  This function implements the Euclidean algorithm to calculate
 *                the greatest common denominator of two numbers. The caveats
 *                are that the numbers cannot be negative, they must be integers,
 *                and at least one of them must not equal zero.
 * 
 *                For the implementation, I decided not to use anything fancy for
 *                the datatype (i.e...unsigned int64), which is what I wanted to
 *                do because the implementation starts getting a little hairy
 *                trying to split hairs between Linux and Windows, especially
 *                with regards to IO. I did, however, typedef the numerical data
 *                type, so that first and foremost, the numerical data used
 *                throughout was guaranteed to be the same size, and more
 *                importantly, because the refactor process is made that much
 *                easier by not having to track down every iteration of the data
 *                type used.
 * 
 *  Note:         This function is static because it is meant to have internal
 *                linkage.
 * 
 */

static Int getGCD(Int divisor, Int dividend) {
   VERIFY_BOTH_INPUTS_POSITIVE(divisor, dividend);
   VERIFY_AT_LEAST_ONE_NOT_ZERO(divisor, dividend);
   VERIFY_INPUT_IS_WITHIN_VALID_RANGE(divisor);
   VERIFY_INPUT_IS_WITHIN_VALID_RANGE(dividend);

   Int n = divisor;
   Int m = dividend;

   Int remainder = m % n;

   while (remainder != 0) {
      m = n;
      n = remainder;

      remainder = m % n;
   }

   return n;
}

/** Function:  LDF */

Int LDF(Int k, Int n)
{
   if (divides(k,n) == true)
      return k;
   else if (SQUARED(k) > n)
      return n;
   else
      return (LDF(k + 1, n));
}

/** Function:  LD */

Int LD(Int dividend) {
   return (LDF(2, dividend));
}

/** Function:     prime0 
 * 
 *  Parameter:    This function takes a single integer-type input: the number to
 *                test for primality.
 * 
 *  Description:  Using the LD, LDF, and getGCD helper his function determines
 *                whether functions, this function determines whether or not the
 *                passed-in parameter is prime.
 * 
 *  Author:       Dr. Kees Doets
 *                Dr. Jan van Eijck
 * 
 *                Translated to C by Jose Fernando Lopez Fernandez
 * 
 */

bool prime0(Int n) {
   if (n < 1) {
      printf("Error: not a positive integer.\n");
      return false;
   } else if (n == 1) {
      return false;
   } else {
      return(LD(n) == n);
   }
}

/** Function:     The Prime Factorization Algorithm
 * 
 *  Parameters:   Int - number to factor
 * 
 *  Description:  Using the following formula, as well as the helper functions
 *                above, this function prints the prime factors of the passed-in
 *                parameter.
 * 
 *                TODO: Build an array and add each factor to the array
 * 
 */

Int PrimeFactorization(Int number) {
   VERIFY_INPUT_POSITIVE(number);

   Int p = DEFAULT_INITIALIZATION;
   Int n = number;

   if (number < 1) {
      printf("Error: argument must be positive\n");
      return 0;
   } else if (number == 1) {
      return 0;
   } else {
      p = LD(number);
      n = (n / p);
      
      printf("p: %d\n", p);

      return n + PrimeFactorization(n);
   }
}

/** Function:     Setup Fraction
 *  
 *  Parameters:   Int numerator
 *                Int denominator
 * 
 *  Description:  This is the constructor for the Fraction data type. In this
 *                function, we make a call to the utility function set fraction
 *                values. We then verify the integrity of the obj, and if the
 *                item was built successfully, we return a pointer back to the
 *                calling function.
 * 
 */

Fraction setupFraction(Int num, Int den) {
   Fraction newFraction = (Fraction) malloc(sizeof(*newFraction));

   // Set Fraction values to -1 first, to make sure if something goes wrong
   // during construction, we can tell from the negative values we set here
   newFraction->num = DEFAULT_INITIALIZATION;
   newFraction->den = DEFAULT_INITIALIZATION;

   // TODO: Call function that will setup values
   setFractionValues(newFraction, num, den);

   return newFraction;
}

/** Function:     Set Fraction Values
 *  
 *  Parameters:   Fraction
 *                Int numerator
 *                Int denominator
 *  
 *  Description:  This will be the function responsible for initializing,
 *                changing, and setting every Function structures' numerator
 *                and denominator values. This setup allows us to centralize
 *                the verification and validation of Fraction member values to
 *                a single function. If we run into any negative values during
 *                program execution, it will be because this function was either
 *                not called or not called correctly, thanks to our canary-in-
 *                the-coalmine utility macro DEFAULT_INITIALIZATION. That is the
 *                only possible negative value a Fraction member can hold, and
 *                and even then only until this function is called, immediately
 *                afterwards.
 * 
 *  Note:         A negative parameter is allowed as input into this function,
 *                specifically the number (-2), because that will represent a
 *                request by the caller to disregard that particular value and
 *                just set the other one only.
 * 
 */

void setFractionValues(Fraction fraction, Int numerator, Int denominator) {
   // TODO: Implement verification and validation
   fraction->num = numerator;
   fraction->den = denominator;
}

/** Function:     Print Fraction
 * 
 *  Parameters:   Fraction
 * 
 *  Description:  This is the function used to display a fraction's value. The
 *                function uses printf as its output, although I may or may not
 *                change that in the near future.
 * 
 */

void printFraction(Fraction fraction) {
   printf("(%d,%d)\n", fraction->num, fraction->den);
}

/** Function:     Divides
 * 
 *  Description:  This function checks to see whether or not one number divides
 *                another; specifically, whether the first number divides the
 *                second. This function is pivotal to both our project, as well
 *                as Dr. Kees Doets and Dr. Jan van Eijck, their book "The 
 *                Haskell Road to Logic, Maths, and Programming."
 * 
 *  Parameters:   Fraction
 * 
 *  Returns:      Boolean
 * 
 *  Notes:        This function is 'strange' in the world of C because it uses
 *                a boolean data type, with the inclusion of <stdbool.h>. This
 *                data type is just a simple typedef around a simple integer, 
 *                with a zero meaning false and a one meaning true, although the
 *                more common application of booleans also holds true, where a
 *                zero represents false and any non-null and non-zero value
 *                represents true.
 * 
 */

// TODO: Actually implement this function
bool divides(Int divisor, Int dividend) {
   Int gcd = getGCD(divisor,dividend);

   if (gcd > 1)
      return true;
   else
      return false;
}

