#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int INF_ROOTS = -1;
const int NO_ROOTS  = -2;
const int ONE_ROOT  = 1;
const int TWO_ROOTS = 2;
const double BORDER = 1e-100;

double LinearEquation(double coef1, double coef2)
{
    return -coef1/coef2;
}

bool IsZero(double number)
{
    if (BORDER >= fabs(number))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int SolveSquare(double a, double b, double c, double* root1, double* root2)
{
    if (IsZero(a))              //проверка, квадратное ли уравнение//
    {
        if (IsZero(b))
        {
            if (IsZero(c))
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {
             *root1 = LinearEquation(c, b);
             return ONE_ROOT;
        }
   }
   else                                         //если уравнение квадратное//
   {
        double discriminant = b*b - 4*a*c;

        if (discriminant < 0)
        {
             return NO_ROOTS;
        }
        else
        {
             if (IsZero(discriminant))
             {
                  *root1 = LinearEquation(b, 2*a);
                  return ONE_ROOT;
             }
             else
             {
                  *root1 = (-b + sqrt(discriminant)) / (2 * a);
                  *root2 = (-b - sqrt(discriminant)) / (2 * a);
                  return TWO_ROOTS;
             }
        }
   }
}

int main()
{
   printf("Enter coefficients of square equation: ");
   double a = NAN, b = NAN, c = NAN;
   scanf("%lg %lg %lg", &a, &b, &c);

   double root1 = NAN, root2 = NAN;

   int nRoots = SolveSquare(a, b, c, &root1, &root2);
   switch(nRoots)
   {
        case ONE_ROOT:
            printf("x1 = %lg", root1);
            break;
        case TWO_ROOTS:
            printf("x1 = %lg, x2 = %lg", root1, root2);
            break;
        case NO_ROOTS:
            printf("No roots");
            break;
        case INF_ROOTS:
            printf("Infinity number of roots");
            break;
   }



}
