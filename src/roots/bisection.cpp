/*! \file bisection.cpp
 *  \brief Bisection implementation file for root finding algorhitm based on bisecting
 *
 *  Implementation of root finding algorhitm based on bisection. Algorhitm works in closed domain [a,b] where the limit values have different signs and there should be only one root between the domain. The range of the function is limited to range of double in current system.  
 */

#include <iostream>
#include <cmath>
#include <limits>
#include "bisection.hpp"

double f1(double x){
	return x;
}
double f2(double x){
	return x-1;
}
double f3(double x){
	return x*x-2;
}

/*! \brief Bisection root finding function
 *  \param f Function to be evaluated
 *  \param a Lower limit of domain as double
 *  \param b Upper limit of domain as double
 *  \param tol Tolerance of error as double
 *  \param maxIteration Maximum number of iterations as integer
 */

double bisection(double (*f)(double), double a, double b, double tol, int maxIteration){
	
	// Test if limits are correct
	if ((*f)(a) * (*f)(b) > 0.0){
		std::cerr << "ERROR: Limits have same signs! " << std::endl;
		return -std::numeric_limits<double>::max();

	}

	double mean = {(a + b) / 2};	// Mean value of the domain
	double root = {(*f)(mean)}; 	// First quess
	int iter = {0};					// Set counter to 0;
	
	while(iter < maxIteration){
		if (std::abs(root) <= tol){return mean;}	// Return mean if f(x) is inside tolerance
	
		// Change limits
		if (root < 0.0){
			(*f)(a) < (*f)(b) ? a = mean : b = mean;
		}else{
			(*f)(a) < (*f)(b) ? b = mean : a = mean;
		}
	
		// New mean and next try for the root
		mean = (a + b) / 2;
		root = (*f)(mean);
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

int main(void){
	std::cout << bisection(f1, 2, 3, 1e-6, 1e6) << std::endl;
	std::cout << bisection(f2, -2, 5, 1e-6, 1e6) << std::endl;
	std::cout << bisection(f3, 0, 5, 1e-6, 1e6) << std::endl;
	std::cout << bisection(f3, -5, 0, 1e-6, 1e6) << std::endl;

	std::cout << bisection(f1, 2, 3) << std::endl;
	std::cout << bisection(f2, -2, 5) << std::endl;
	std::cout << bisection(f3, 0, 5) << std::endl;
	std::cout << bisection(f3, -5, 0) << std::endl;

	return 0;
}
