/*
 * A game where the user enters a distance, and then has 5 tries to guess 
 * the angle and velocity needed to shoot a projectile that distance.
 * 
 * Author: Chase Urban
 * Due: 1/27/2020
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double distance(double velocity, double angle);

double radians(double degrees);

/*
 * Main method, handles input and output, as well as logical tests.
 */
int main(int argc, char** argv) {
    cout << "Enter the distance to the target\n";
    double userDistance, angle, dis;
    cin >> userDistance;
    for(int i = 0; i < 5; i++){
        cout << "Enter the angle and the velocity of the projectile\n";
        double degrees, velocity;
        cin >> degrees >> velocity;
        angle = radians(degrees);
        dis = distance(velocity, angle);
        double disMinus = userDistance - (userDistance * 0.001);
        double disPlus = userDistance + (userDistance * 0.001);
        if(disMinus <= dis && dis <= disPlus){
            cout << "Congrats! You Won\n";
            break;
        } 
        cout << "Incorrect. Your guess was " << (dis - userDistance) 
             << " units off. " << (4 - i) << " tries left.\n";
        if (i == 4) cout << "Game over\n";
    }
}

/**
 * distance function, uses distance formula given in homework assignment
 * precondition: velocity and angle must be greater than zero
 * postcondition: distance projectile will travel
 */
double distance(double velocity, double angle){
    return ((pow(velocity,2)*sin(2*angle))/(32.2));
}

/**
 * function to convert degrees to radians
 * precondition: a number, representing degrees of an angle
 * postcondition: the radian value of the degree value
 */
double radians(double degrees){
    return ((degrees * 3.14159265)/(180.0));
}