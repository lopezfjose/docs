/** File Name:    example.h
 * 
 *  Author:       Jose Fernando Lopez Fernandez
 * 
 *  Date:         06-October-2017
 *  
 *  Description:  This file contains the function prototypes, macros, structure
 *                definition(s), and typedefs required by example.c, the main
 *                implementation file.
 * 
 *                If you have any questions or just need to reach me for
 *                anything, email is the best way to contact me, at
 *                jflopezfernandez@gmail.com
 * 
 */

#ifndef SRC_INCLUDES_PRIME_FACTORS_H_
#define SRC_INCLUDES_PRIME_FACTORS_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>

typedef int32_t Int;
typedef struct {
   Int num;
   Int den;
} *Fraction;

Fraction setupFraction(Int num, Int den);
void setFractionValues(Fraction fraction, Int numerator, Int denominator);
void printFraction(Fraction fraction);

typedef Int* Array;

bool divides(Int divisor, Int dividend);
Array getPrimeFactors(Int divisor, Int dividend);

/** Prime Factorization Calculation Functions */

Int LDF(Int k, Int n);
Int LD(Int dividend);
bool prime0(Int n);
Int PrimeFactorization(Int number);

/** Macro:  SQUARED
 * 
 *  Description:  This macro will make it much easier to ready through the
 *                implementation code. Rather than having to sift through the
 *                ^ operator, the SQUARED macro should both add clarity and
 *                reduce code noise.
 * 
 */

#define SQUARED(x) (x*x)

/** Macro:  DEFAULT_INITIALIZATION -1
 * 
 *  Description:  This macro represents the default value we set values to when
 *                initially instantiating them because we do not want to risk
 *                calling a value without having set it first.
 * 
 *                More importantly, by initializing every integer to this
 *                uniform value every time, it gives us a clear cut way of
 *                immediately recognizing at least a subset of possible errors.
 * 
 */

#define DEFAULT_INITIALIZATION (-1);

/** Macro:  VERIFY_INPUT_POSITIVE(input)
 * 
 *  Description:  This uility macro just verifies the number passed in is
 *                positive, since various functions here cannot cope with
 *                negative values.
 * 
 */

#define VERIFY_INPUT_POSITIVE(input) assert((input) >= 0)

/** Macro: VERIFY_BOTH_INPUTS_POSITIVE
 * 
 *  Description:  This macro verifies both inputs are positive to ensure the 
 *                Euclid's Greatest Common Divisor algorithm works as intended.
 *                We employ the assert macro from <assert.h> here, from the
 *                standard library.
 * 
 */

#define VERIFY_BOTH_INPUTS_POSITIVE(x,y) VERIFY_INPUT_POSITIVE(x); \
                                         VERIFY_INPUT_POSITIVE(y);

/** Macro:  VERIFY_AT_LEAST_ONE_NOT_ZERO
 *  
 *  Description:  If both inputs passed in to the Greatest Common Divisor
 *                algorithm are negative, the function will not work; it will,
 *                in fact, crash the program. For this reason, I have included
 *                this macro, to verify the algorithm receives only valid inputs.
 * 
 */

#define VERIFY_AT_LEAST_ONE_NOT_ZERO(x,y) assert(((x) + (y)) > 0)

/** Macro:  VERIFY_INPUT_IS_WITHIN_VALID_RANGE
 * 
 *  Description:  In order to prevent overflow errors, this macro asserts that
 *                the input value does not exceed INT32_MAX. If this exercise is
 *                refactored to use larger numbers in the future, this macro will
 *                have to be tweaked, since obviously it will cause the program
 *                to stop working most of the time, since the current container
 *                is a 32-bit signed integer.
 * 
 */

#define VERIFY_INPUT_IS_WITHIN_VALID_RANGE(x) assert(x < INT32_MAX)

/** Macro:  ERRMSG(msg)
 *  
 *  Description:  This macro is used to log any error messages from the program
 *                during development. If the macro is used while NDEBUG is
 *                defined, like 'assert', the macro is rendered 'useless'.
 * 
 *                In other words, it does not print any output, regardless of
 *                the severity.
 * 
 */

#ifndef NDEBUG
  #define ERRMSG(msg,val) printf("[ERROR] %s: %i (file: %s, line: %i) \n", msg, (int) val, __FILE__, __LINE__)
#else
  #define ERRMSG(msg,val)
#endif




#endif /** SRC_INCLUDES_PRIME_FACTORS_H_ */