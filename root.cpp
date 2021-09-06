
#include <iostream>
#include <cmath>

/*--------------------------------------------------------------
 Author: Michael Pace

 Summary:  The program uses user input as variables A, B, C in a quadratic function to find the roots of said function.
 It picks out numbers A that would return invalid outputs based on the discriminant and uses a do/while loop to ask for user input until a valid
 value is given.  It checks what range the discriminant lies in and plugs it into the appropriate formula.  In all cases it
 prints out an appropriate response given the resulting roots.

 Date last modified:
 08.11.2021 (mdl): created this sample starter
 08.11.2021 (mdl): small edits to add comments
 09.04.2021: user input established, root calculations created if discriminant >= 0
 09.04.2021: proper response if discriminant < 0
 09.04.2021: created loop to restart function if invalid values are given
 ....

 ----------------------------------------------------------------*/

/*--------------------------------------------------------------
 INPUT:  Three real coefficients from stdin

 OUTPUT: One or two roots to stdout
 ---------------------------------------------------------------*/

int main() {
    bool restart = false; // Restarts function main() if restart == true
    do {
        // User input and variable assignment

        double A, B, C;   // three coefficients for quadratic equation

        std::cout << "Ax^2 + Bx + C = 0" << std::endl;

        std::cout << "Choose a real coefficient for A: ";   //Choose and assign A value
        std::cin >> A;
        std::cout << "Choose a real coefficient for B: ";   //Choose and assign B value
        std::cin >> B;
        std::cout << "Choose a real coefficient for C: ";   //Choose and assign C value
        std::cin >> C;

        if (A == 0) {
            std::cout << "The given coefficients result in an invalid equation, make sure you enter real values." << std::endl;
            restart = true;
        } else {
            restart = false;
        }

        // Create boolean to dictate how many roots exist

        bool one,   // Boolean for rootOne
        two;   // Boolean for rootTwo

        // Calculation of roots

        double rootOne,      // First root
        rootTwo;      // Second root
        double discriminant;  // Discriminant
        double rootOneTop,   // Numerator of first root quadratic equation if discriminant > 0
        rootTwoTop;   // Numerator of second root quadratic equation if discriminant > 0

        discriminant = (B * B) - (4 * A * C);

        if (discriminant > 0) {           // Calculate roots if discriminant > 0
            rootOneTop = (B * (-1)) + sqrt(discriminant);
            rootOne = rootOneTop / (2 * A);
            rootTwoTop = (B * (-1)) - sqrt(discriminant);
            rootTwo = rootTwoTop / (2 * A);

            one = true;
            two = true;
        } else if (discriminant == 0) {   // Calculate roots if discriminant = 0
            rootOne = (B * (-1)) / (2 * A);

            one = true;
        } else if (discriminant < 0) {    // Calculate roots if discriminant < 0
            std::cout << std::endl;
            std::cout << "No real roots" << std::endl;
        }   // Apply correct equation depending on discriminant

        // Output Results

        std::cout << std::endl;

        if (discriminant >= 0 && A != 0) {
            std::cout << A << "x^2 + " << B << "x + " << C << " = 0" << std::endl;   // Show equation with variables
            std::cout << std::endl;
            if (one) {
                std::cout << "First root is:  " << rootOne << std::endl;   // Print root one
            }
            if (two) {
                std::cout << "Second root is: " << rootTwo << std::endl;   // Print root two
            }
        }   // Only output results if discriminant is real number

        if (!restart) {
            std::cout << std::endl << "---- Done -----------------------" << std::endl << std::endl;
        }
    } while(restart);

    return 0;

} // main
