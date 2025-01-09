# Overview
This folder includes 3 projects: Point Structure, Calculator Class Implementation, Matrix Class Implementation.

# Requirements

- CMake (version 3.10 or higher) 
- C++ compiler (GCC, Clang, or MSVC)

# Installation and Setup

   1- Clone the repository to your local machine.
   2- Ensure a C++ compiler is installed on your system.
   3- Create the build directory and navigate into it.
   4- Configure the project with CMake
   5- Build the project

## Point Structure

This project involves a 3D point system where each point is represented by its `x`, `y`, and `z` coordinates. The program provides various functionalities such as calculating the distance of a point from the origin, comparing points based on their distance from the origin, checking whether two points are in the same region, and identifying the region a point belongs to in a 3D coordinate space.

### Features

- **Point Class**: Represents a point in a 3D space with `x`, `y`, and `z` coordinates.
- **Zero Distance**: Calculates the distance of the point from the origin `(0, 0, 0)`.
- **Distance Between Points**: Calculates the Euclidean distance between two points.
- **Comparison**: Compares two points and returns the one further from the origin.
- **Region Classification**: Classifies a point into one of the 8 regions based on its `x`, `y`, and `z` coordinates.
- **Region Comparison**: Checks if two points lie in the same region.
- **Region Naming**: Converts a region enum value to a human-readable string.

### Regions in 3D Space

The 3D space is divided into 8 regions (or octants) based on the signs of `x`, `y`, and `z`. These regions are as follows:

1. **First Region**: `x > 0`, `y > 0`, `z > 0`
2. **Second Region**: `x < 0`, `y > 0`, `z > 0`
3. **Third Region**: `x < 0`, `y < 0`, `z > 0`
4. **Fourth Region**: `x > 0`, `y < 0`, `z > 0`
5. **Fifth Region**: `x > 0`, `y > 0`, `z < 0`
6. **Sixth Region**: `x < 0`, `y > 0`, `z < 0`
7. **Seventh Region**: `x < 0`, `y < 0`, `z < 0`
8. **Eighth Region**: `x > 0`, `y < 0`, `z < 0`
9. **Origin**: `x == 0`, `y == 0`, `z == 0`

### How It Works

1. The program defines a `Point` structure with `x`, `y`, and `z` attributes.
2. It uses basic Euclidean geometry to calculate distances.
3. The program checks the region of each point based on its coordinate signs (`x`, `y`, `z`).
4. Points are compared based on their distance from the origin.
5. It checks if two points are in the same region.

### Usage

#### Example:

The following code demonstrates how to use the `Point` class and its functionalities:

```cpp
#include <iostream>

int main() {
    Point p1(3, 4, 5);
    Point p2(5, 12, 13);
    Point p3(1, 1, 1);
    Point p4(0, 0, 0);

    // Distance from the origin
    std::cout << "Distance of p1 from origin: " << p1.zero_distance() << std::endl;
    
    // Distance between two points
    std::cout << "Distance between p1 and p2: " << Point::distance(p1, p2) << std::endl;

    // Comparison: which point is further from the origin
    Point further = Point::compare(p1, p2);
    std::cout << "Point further from origin: (" << further.x << ", " << further.y << ", " << further.z << ")" << std::endl;

    // Region of the points
    std::cout << "Region of p1: " << Point::region_to_string(p1.region()) << std::endl;
    std::cout << "Region of p2: " << Point::region_to_string(p2.region()) << std::endl;

    // Checking if points are in the same region
    std::cout << "Are p1 and p2 in the same region? " << (Point::is_in_same_region(p1, p2) ? "Yes" : "No") << std::endl;

    return 0;
}

Output:

Distance of p1 from origin: 7.07107
Distance between p1 and p2: 8.24621
Point further from origin: (5, 12, 13)
Region of p1: First
Region of p2: First
Are p1 and p2 in the same region? Yes



## Calculator Application

This is a simple command-line calculator application implemented in C++. The calculator provides functionality for performing basic arithmetic operations and more advanced mathematical functions, such as exponentiation and modulus. The operations include:

- **Multiplication**
- **Addition**
- **Subtraction**
- **Division**
- **Square**
- **Exponentiation**
- **Modulus**

## Features

1. **Multiplication (1)**: Multiply any number of values.
2. **Addition (2)**: Add any number of values.
3. **Subtraction (3)**: Subtract two numbers.
4. **Division (4)**: Divide two numbers, with an error check for division by zero.
5. **Square (5)**: Calculate the square of a number.
6. **Exponentiation (6)**: Raise a number to a specified power (base^exponent).
7. **Modulus (7)**: Calculate the remainder when dividing two integers.

## File Structure

The project consists of the following files:

1. **main.cpp** - The main file that contains the logic for interacting with the user, taking inputs, and calling the calculator operations.
2. **Calculator.hpp** - Header file declaring the `Calculator` class and its methods.
3. **Calculator.cpp** - Implementation of the `Calculator` class methods.

## How to Compile and Run

### Prerequisites:
- A C++ compiler (e.g., GCC, Clang)

### Steps to Compile and Run:

1. **Clone the repository** (or copy the files to your local machine).
   
   ```bash
   git clone https://github.com/yourusername/calculator-app.git
   
2. **Navigate to the project directory**

cd calculator-app

3. **Compile the code**

Using GCC or any other C++ compiler:

g++ -o calculator main.cpp Calculator.cpp -std=c++11

4.**Run the program**

    ./calculator

## Usage

Once the program is running, it will prompt you to choose an operation. The available options are:

    1 for Multiplication
    2 for Addition
    3 for Subtraction
    4 for Division
    5 for Square
    6 for Exponentiation
    7 for Modulus

You will be asked to input numbers based on your selected operation. After each operation, you will have the option to perform another calculation or exit the program.

**Example**

Sample Output:

What would you like to do (multiplication (1), addition (2), subtraction (3), division (4), square (5), exponentiation (6), modulus (7))? 2
How many numbers do you want to add? 3
Enter number 1: 5
Enter number 2: 3
Enter number 3: 4
The total sum is: 12

Would you like to perform another calculation? (y/n): y

What would you like to do (multiplication (1), addition (2), subtraction (3), division (4), square (5), exponentiation (6), modulus (7))? 4
Enter first number: 10
Enter second number: 2
The division of 10 / 2 is 5

Would you like to perform another calculation? (y/n): n

Have a nice day!


## Calculator Class Overview

The Calculator class includes the following methods:

    multiply(int numCount): Multiplies a series of numbers entered by the user.
    add(int numCount): Adds a series of numbers entered by the user.
    subtract(double a, double b): Subtracts two numbers.
    divide(double c, double d): Divides two numbers (includes check for division by zero).
    square(double e): Returns the square of a number.
    exponentiation(double f, double g): Returns the result of raising a number f to the power of g.
    mod(int h, int j): Returns the remainder when dividing h by j.










# Matrix Manipulation Library

## Overview
This project implements a matrix manipulation library written in C++. It includes basic operations on matrices such as addition, subtraction, multiplication, transposition, determinant calculation, inversion, and more. The code uses object-oriented principles to encapsulate matrix operations within the `Matrix` class.

## Features
- Matrix creation and initialization (with default values or from a 2D array)
- Matrix operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Negation
  - Transposition
  - Determinant calculation
  - Inversion (for square matrices)
  - Trace calculation
- Static methods to create special matrices:
  - Zero matrix (`zeroes`)
  - Identity matrix (`identity`)
  - Ones matrix (`ones`)
- Dot product and magnitude of matrices
- Matrix printing

## Classes

### `MatrixNamespace::Matrix`
This is the main class representing a matrix. It provides methods for matrix operations such as addition, subtraction, transposition, and more.

#### Constructor
- `Matrix(float rows, float cols, float initialValue = 0)`  
  Creates a matrix of size `rows x cols` initialized with the value `initialValue`.
  
- `Matrix(const std::vector<std::vector<float>>& data)`  
  Creates a matrix from a 2D vector.

#### Methods
- `Matrix inverse() const`: Returns the inverse of the matrix (if it is invertible).
- `float trace() const`: Returns the trace of the matrix (sum of diagonal elements).
- `float determinant() const`: Returns the determinant of the matrix.
- `Matrix transpose() const`: Returns the transposed matrix.
- `Matrix add(const Matrix& other) const`: Adds another matrix to the current matrix.
- `Matrix subtract(const Matrix& other) const`: Subtracts another matrix from the current matrix.
- `Matrix neg() const`: Returns the negation of the matrix.
- `Matrix multiply(const Matrix& other) const`: Multiplies the matrix with another matrix.
- `float dot(const Matrix& other) const`: Returns the dot product of two matrices (only defined for 1xN matrices).
- `float magnitude() const`: Returns the magnitude of the matrix (calculated as the square root of the sum of squares of its elements).
- `static Matrix zeroes(float rows, float cols)`: Creates a matrix filled with zeros.
- `static Matrix ones(float rows, float cols)`: Creates a matrix filled with ones.
- `static Matrix identity(float size)`: Creates an identity matrix of size `size`.

#### Overloaded Operators
- `Matrix operator+(const Matrix& other) const`: Overloads the `+` operator to add two matrices.
- `Matrix operator-(const Matrix& other) const`: Overloads the `-` operator to subtract two matrices.

#### Printing
- `void print() const`: Prints the matrix to the console.

## Example Usage

```cpp
#include "matrix.h"

using namespace std;
using namespace MatrixNamespace;

int main() {
    // Create a 3x3 zero matrix
    Matrix m1(3, 3);
    m1.print();
    
    // Create a matrix from a 2D vector
    vector<vector<float>> mat_data = {{1, 2, 3}, {5, 5, 6}, {4, 8, 9}};
    Matrix m2(mat_data);
    m2.print();

    // Transpose a matrix
    Matrix m3 = m2.transpose();
    m3.print();

    // Calculate trace, determinant
    cout << "Trace: " << m2.trace() << endl;
    cout << "Determinant: " << m2.determinant() << endl;

    // Matrix operations
    Matrix m4 = m2.add(m1);
    m4.print();
    
    Matrix m5 = m2.neg();
    m5.print();
    
    Matrix m6 = m2.multiply(m1);
    m6.print();

    // Calculate inverse (if possible)
    try {
        Matrix m7 = m2.inverse();
        m7.print();
    } catch (const std::invalid_argument& e) {
        cout << "Error calculating inverse: " << e.what() << endl;
    }

    // Create and print special matrices
    Matrix m8 = Matrix::ones(3, 3);
    m8.print();

    Matrix m9 = Matrix::identity(3);
    m9.print();

    // Dot product and magnitude
    cout << "Dot product: " << m2.dot(m1) << endl;
    cout << "Magnitude: " << m2.magnitude() << endl;

    return 0;
}


Compilation

To compile the code, you can use a C++ compiler like g++. Here is the command to compile the program:

g++ main.cpp -o matrix_program

Then, run the compiled program:

./matrix_program

Dependencies

    C++11 or higher required for features like std::vector, std::exception, etc.
    The program uses cmath for calculating magnitudes and square roots.
















    


### Quick Breakdown of the README:

1. **Introduction**: The opening paragraph introduces the calculator and the operations it supports.
2. **File Structure**: This section explains the key files in the project.
3. **How to Compile and Run**: Detailed instructions for compiling and running the project.
4. **Usage**: A section explaining how users can interact with the application.
5. **Example Output**: A sample session showing how the program works.
6. **Calculator Class**: An overview of the methods provided in the `Calculator` class.
7. **License**: Information about licensing (you can change it to your specific license if you prefer).
8. **Contact**: A place for you to add your email or other contact information.

You can simply copy and paste this `README.md` file into your project’s repository. Let me know if you need any changes!

## Contact

Should you encounter any issues or have questions regarding the C++ Variables project, please reach out to Irem Aslan at iremaslan0420@hotmail.com.
