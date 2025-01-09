# C++ Projects: Point Structure, Calculator, and Matrix 

This repository contains three C++ projects:

1. **Point Structure** - A 3D point system that provides various functionalities for working with points in 3D space.
2. **Calculator Class Implementation** - A simple command-line calculator that performs basic and advanced arithmetic operations.
3. **Matrix Manipulation Library** - A library for performing operations on matrices like addition, multiplication, inversion, etc.

---

## Requirements

- **CMake**: Version 3.10 or higher
- **C++ Compiler**: GCC, Clang, or MSVC

---

## Installation and Setup

1. Clone the repository to your local machine:
    ```bash
    git clone <repository_url>
    ```
   
2. Ensure that a C++ compiler is installed (e.g., GCC, Clang, MSVC).

3. Create and navigate to the build directory:
    ```bash
    mkdir build && cd build
    ```

4. Configure the project using CMake:
    ```bash
    cmake ..
    ```

5. Build the project:
    ```bash
    cmake --build .
    ```

---

## Projects

### 1. Point Structure

This project implements a 3D point system, where each point is represented by `x`, `y`, and `z` coordinates. The program provides several features like calculating distances, comparing points, and classifying points into regions based on their coordinates in 3D space.

#### Key Features:
- **Point Class**: Represents a point in 3D space.
- **Zero Distance**: Calculates the distance from the origin `(0, 0, 0)`.
- **Distance Between Points**: Calculates the Euclidean distance between two points.
- **Comparison**: Compares two points and returns the one further from the origin.
- **Region Classification**: Classifies a point into one of the 8 regions in 3D space based on its coordinates.
- **Region Comparison**: Checks if two points lie in the same region.

#### 3D Space Regions:
- First Region: `x > 0`, `y > 0`, `z > 0`
- Second Region: `x < 0`, `y > 0`, `z > 0`
- Third Region: `x < 0`, `y < 0`, `z > 0`
- Fourth Region: `x > 0`, `y < 0`, `z > 0`
- Fifth Region: `x > 0`, `y > 0`, `z < 0`
- Sixth Region: `x < 0`, `y > 0`, `z < 0`
- Seventh Region: `x < 0`, `y < 0`, `z < 0`
- Eighth Region: `x > 0`, `y < 0`, `z < 0`
- Origin: `x == 0`, `y == 0`, `z == 0`

#### Example Usage:

```cpp
#include <iostream>

int main() {
    Point p1(3, 4, 5);
    Point p2(5, 12, 13);

    std::cout << "Distance of p1 from origin: " << p1.zero_distance() << std::endl;
    std::cout << "Distance between p1 and p2: " << Point::distance(p1, p2) << std::endl;
    Point further = Point::compare(p1, p2);
    std::cout << "Point further from origin: (" << further.x << ", " << further.y << ", " << further.z << ")" << std::endl;

    std::cout << "Region of p1: " << Point::region_to_string(p1.region()) << std::endl;
    std::cout << "Are p1 and p2 in the same region? " << (Point::is_in_same_region(p1, p2) ? "Yes" : "No") << std::endl;

    return 0;
}

### 2. Calculator Application

A simple command-line calculator implemented in C++ for performing basic arithmetic operations and advanced functions like exponentiation and modulus.
Supported Operations:

    Multiplication
    Addition
    Subtraction
    Division
    Square
    Exponentiation
    Modulus

File Structure:

    main.cpp: Contains logic for user interaction and input handling.
    Calculator.hpp: Header file declaring the Calculator class and its methods.
    Calculator.cpp: Implementation of the Calculator class methods.

Compilation and Running:

    Clone the repository:

git clone <repository_url>

Navigate to the project directory:

cd calculator-app

Compile the program:

g++ -o calculator main.cpp Calculator.cpp -std=c++11

Run the program:

    ./calculator

Example Output:

What would you like to do (multiplication (1), addition (2), subtraction (3), division (4), square (5), exponentiation (6), modulus (7))? 2
How many numbers do you want to add? 3
Enter number 1: 5
Enter number 2: 3
Enter number 3: 4
The total sum is: 12

Would you like to perform another calculation? (y/n): y

3. Matrix Manipulation Library

A C++ library that performs various operations on matrices, including addition, subtraction, multiplication, inversion, and more.
Key Features:

    Matrix creation from default values or 2D arrays.
    Operations like addition, subtraction, multiplication, transposition, and inversion.
    Methods for calculating the determinant and trace of matrices.
    Static methods to create special matrices (zero, identity, ones).
    Support for dot product, magnitude, and matrix printing.

Example Usage:

#include "matrix.h"

int main() {
    Matrix m1(3, 3);  // Create a 3x3 zero matrix
    m1.print();

    std::vector<std::vector<float>> mat_data = {{1, 2, 3}, {5, 5, 6}, {4, 8, 9}};
    Matrix m2(mat_data);
    m2.print();

    Matrix m3 = m2.transpose();
    m3.print();

    std::cout << "Trace: " << m2.trace() << std::endl;
    std::cout << "Determinant: " << m2.determinant() << std::endl;

    Matrix m4 = m2.add(m1);
    m4.print();

    return 0;
}

Compilation:

To compile the code, use a C++ compiler like g++:

g++ main.cpp -o matrix_program

Then run the program:

./matrix_program

Dependencies

    C++11 or higher: Required for features like std::vector, exceptions, etc.
    cmath: For mathematical operations like calculating magnitudes and square roots.

License

[Insert your license here]
Contact

For questions or inquiries, please contact [Your Name] at [Your Email].
