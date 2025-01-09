# Calculator Application

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
The division of 10/2 is 5

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

## License

This project is licensed under the MIT License - see the LICENSE file for details.
Contact

For any questions or suggestions, feel free to reach out at [your.email@example.com].


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

