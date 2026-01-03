// this code is mean to calculate the height of a ball using a quadratic equation 

#include <iostream>
#include <cmath>
using namespace std ; 

// this functioun is meant to check the boundries of the quadratic equation that describe the the height of the ball
int a = -1 ;
int b = 10 ;
int c = 3 ;
double delta = b*b - 4*a*c ;
double h = a*t*t + b*t + c ;

double check_the_boundries ( double h ; double t ; ){
    if (delta >= 0 ){
        return delta ;
    }
    else {
        cout << " this equation is not valid in real life " << endl ;
    }
}

// this function is meant to calculate the lowest boundry of the quadratic equation
double the_lowest_boundry (){
    double boundry [2] = { (-b + sqrt (delta)) / (2*a) , (-b - sqrt (delta)) / (2*a) } ;
    if ( boundry [0] < boundry [1] ){
        return boundry [0] ;
    }
    else {
        return boundry [1] ;
    }
}
int main (){
    check_the_boundries ( ) ;
    the_lowest_boundry ( ) ;
    for ( double t = 0 ; t <= the_lowest_boundry ( ) ; t += 0.1 ){
        double h = a*t*t + b*t + c ;
        cout << " at time " << t << " seconds , the height of the ball is " << h << " meters " << endl ;
    }
    return 0 ;
}

