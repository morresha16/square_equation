#ifndef SOLVESQUARE_H_INCLUDED
#define SOLVESQUARE_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define DEBUG

//----------------------------------------------------------------------------------------------------------------------------
//! This function solves a linear equation coef1*x + coef2 = 0
//! @param [in] coef1 coef1 - coefficient
//! @param [in] coef2 coef2 - coefficient
//----------------------------------------------------------------------------------------------------------------------------

double LinearEquation (double coef1, double coef2);

//----------------------------------------------------------------------------------------------------------------------------
//! This function determines whether a number doesn't equal zero
//! @param [in] number - number
//----------------------------------------------------------------------------------------------------------------------------

bool IsZero (double number);

//----------------------------------------------------------------------------------------------------------------------------
//! This function determines whether the 1st number equals the 2nd number
//! @param [in] number1  number1 - the 1st number
//! @param [in] number2  number2 - the 2nd number
//----------------------------------------------------------------------------------------------------------------------------

bool IsEqual (double number1, double number2);

//----------------------------------------------------------------------------------------------------------------------------
//! This function solves a square equation ax^2 + bx + c = 0
//! @param [in]   a       a - coefficient
//! @param [in]   b       b - coefficient
//! @param [in]   c       c - coefficient
//! @param [out]  root1   root1 - Pointer of the 1st root
//! @param [out]  root2   root2 - Pointer of the 2nd root
//!
//! @return Roots of the square excursion if they exist
//! @note In case of infinite number of roots, returns “Infiniti number of roots”. In case of no roots, returns “No roots”.
//----------------------------------------------------------------------------------------------------------------------------

int SolveSquare (double a, double b, double c, double* root1, double* root2);

//----------------------------------------------------------------------------------------------------------------------------
//! This function outputs the result of solving a square equation
//! @param [in]   nRoots  nRoots - Pointer of the number of roots
//! @param [out]  root1   root1  - Pointer of the 1st root
//! @param [out]  root2   root2  - Pointer of the 2nd root
//!
//! @return Roots of the square equation if they exist
//! @note In case of infinite number of roots, returns “Infiniti;) number of roots”. In case of no roots, returns “No roots”.
//----------------------------------------------------------------------------------------------------------------------------

void OutputSolution (int nRoots, double root1, double root2);

//----------------------------------------------------------------------------------------------------------------------------
//! This function inputs the coefficients of square equation ax^2 + bx + c = 0
//! @param [in]   a       a - coefficient
//! @param [in]   b       b - coefficient
//! @param [in]   c       c - coefficient
//!
//! @note In case user enter other symbol instead of numbers, function asks to enter again until user won't make 5 wrong enters,
//!       in that case function asks user go to sleep
//----------------------------------------------------------------------------------------------------------------------------

int InputCoeffitients (double* a, double* b, double* c);

#ifdef DEBUG

//----------------------------------------------------------------------------------------------------------------------------
//! This function tests functionality of SolveSquare function
//!
//!
//! @return OK - if test completed, Error - if test failed, ALL TESTS COMPLETED! - if all of the tests completed
//----------------------------------------------------------------------------------------------------------------------------

void TestSolvingFunction();

#endif

enum Number_of_roots
{
                      //! Marks the case of infinity of roots
    INF_ROOTS = -1,
                      /// Marks the case of no roots
    NO_ROOTS,
                      /// Marks the case of one root
    ONE_ROOT,
                      /// Marks the case of two roots
    TWO_ROOTS,
};

const double BORDER = 1e-100;
const int    LEN = 5;

#endif // SOLVESQUARE_H_INCLUDED
