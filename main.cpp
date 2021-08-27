#include "SolveSquare.h"

//----------------------------------------------------------------------------------------------------------------------------
//! This program solver the quadratic equation and tests itself for right working :)
//----------------------------------------------------------------------------------------------------------------------------

int main()
{
    #ifdef DEBUG
    TestSolvingFunction();
    #else

    double a = NAN, b = NAN, c = NAN;
    double root1 = NAN, root2 = NAN;

    if (InputCoeffitients(&a, &b, &c) != -1)
    {
        int nRoots = SolveSquare(a, b, c, &root1, &root2);
        OutputSolution(nRoots, root1, root2);
    }
    #endif
}
