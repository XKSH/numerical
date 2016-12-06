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

#endif
