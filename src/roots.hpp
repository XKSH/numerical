/*! \file bisection.hpp
 *  \brief Header file for root finding algorhitm based on bisecting
 *
 *  Header file for root finding algorhitm based on bisection. Algorhitm works in closed domain [a,b] and there should be only one root between the domain. The range is limited to range of double. 
 */

#ifndef BISECTION
#define BISECTION


/*! \brief Root finding by bisection function 
 *  \param f Function which root is to be find as pointer to function
 *  \param a Lower limit of the domain as double
 *  \param b Upper limit of the domain as double
 *  \param tol Allowed tolerance as double
 *  \param iter Maximun number of iterations as integer
 */

double bisection(double (*f)(double),double a,double b, double tol, int maxIteration);

/*! \brief Root finding by bisection function with default tolerance and iterations
 *  \param f Function which root is to be find as pointer to function
 *  \param a Lower limit of the domain as double
 *  \param b Upper limit of the domain as double
 */
double bisection(double (*f)(double),double a,double b);


/*! \brief Root finding by secant method
 *	\param f Function which root is to be fid as pointer to function
 *	\param x0 as first point as double
 *	\param x1 as second point as double
 *	\param tol Allowed tolerance as double
 *	\param Maximum number of iterations as integer
 */

double secant(double (*f)(double), double x0, double x1, double tol, int maxIteration);

/*! \brief Root finding by secant method with default values
 *	\param f Function which root is to be fid as pointer to function
 */

double secant(double (*f)(double), double x0, double x1);




#endif
