/*! \file bisection.cpp
 *  \brief Bisection implementation file for root finding algorhitm based on bisecting
 *
 *  Implementation of root finding algorhitm based on bisection. Algorhitm works in closed domain [a,b] where the limit values have different signs and there should be only one root between the domain. The range of the function is limited to range of double in current system.  
 */

#include <iostream>
#include <cmath>
#include <limits>
#include "roots.hpp"
#include <cassert>

/*
double f1(double x){
	return x;
}
double f2(double x){
	return -(x-1);
}
double f3(double x){
	return -(x*x-2)+2*x;
}
*/

/*! \brief Bisection root finding function
 *  \param f Function to be evaluated
 *  \param a Lower limit of domain as double
 *  \param b Upper limit of domain as double
 *  \param tol Tolerance of error as double
 *  \param maxIteration Maximum number of iterations as integer
 */

double bisection(double (*f)(double), double a, double b, double tol, int maxIteration){
	
	// Test if limits are correct
	
	assert(f(a)*f(b) <= 0);

	/*
	if ((*f)(a) * (*f)(b) > 0.0){
		std::cerr << "ERROR: Limits have same signs! " << std::endl;
		return -std::numeric_limits<double>::max();

	}
	*/
	

	double mean = {(a + b) / 2};	// Mean value of the domain
	double root = {f(mean)}; 	// First quess
	int iter = {0};					// Set counter to 0;
	
	while(iter < maxIteration){
		if (std::abs(root) <= tol){return mean;}	// Return mean if f(x) is inside tolerance
	
		// Change limits
		// If limit sign(f(a)) equals sign(f(mean)), set mean to a
		// else set mean to b
		f(mean)/std::abs(f(mean)) == f(a)/std::abs(f(a)) ? a = mean : b = mean; 
	
		// New mean and next try for the root
		mean = (a + b) / 2;
		root = f(mean);
		iter++;
	}

	return mean;
}

/*! \brief Bisection root finding function with default tolerance 1e-6 and maximun iterations 1e6
 * \param f Function to be evaluated as function
 * \param a lower limit of domain as double
 * \param b upper limit of domain as double
 *
 */
double bisection(double (*f)(double), double a, double b){
	return bisection(f, a, b, 1e-6, 1e6);
}


/*! \brief Root finding by secant method
 *	\param f Function which root is to be fid as pointer to function
 *	\param x0 as first point as double
 *	\param x1 as second point as double
 *	\param tol Allowed tolerance as double
 *	\param Maximum number of iterations as integer
 */

double secant(double (*f)(double), double x0, double x1, double tol, int maxIteration){
	double x2 = x1 - f(x1) * ((x1 - x0) / (f(x1) - f(x0)));
	int iter = 0;
	while (std::abs(f(x2)) > tol && iter < maxIteration){
		x0 = x1;
		x1 = x2;
		x2 = x1 - f(x1) * ((x1- x0) / (f(x1) - f(x0)));
		iter++;
	}
	return x2;
}


/*! \brief Root finding by secant methodwith default tole 1e-12 and maximum iterations 1e6
 *	\param f Function which root is to be fid as pointer to function
 *	\param x0 as first point as double
 *	\param x1 as second point as double
 */

double secant(double (*f)(double), double x0, double x1){
	return secant(f, x0, x1, 1e-12, 1e6);		
}

