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

#### Example Output:

!(![1 foto point](https://github.com/user-attachments/assets/50fe26f5-8b36-48b0-b867-db0a182fe049)
)


### 2. Calculator Application

A simple command-line calculator implemented in C++ for performing basic arithmetic operations and advanced functions like exponentiation and modulus.
Supported Operations:

   - **Multiplication**
   - **Addition**
   - **Subtraction**
   - **Division**
   - **Square**
   - **Exponentiation**
    -**Modulus**

#### File Structure:

   - **main.cpp** - Contains logic for user interaction and input handling.
   - **Calculator.hpp** - Header file declaring the Calculator class and its methods.
   - **Calculator.cpp** - Implementation of the Calculator class methods.

#### Compilation and Running:

1- Clone the repository:
```bash
git clone <repository_url>
```

2- Navigate to the project directory:
```bash
cd calculator-app
```

3- Compile the program:
```bash
g++ -o calculator main.cpp Calculator.cpp -std=c++11
```

4- Run the program:
```bash
    ./calculator
```

#### Example Output:
!(![2foto calculator](https://github.com/user-attachments/assets/b58df821-75c8-47c9-ad58-b54ed25750f9)
)



### 3. Matrix Manipulation Library

A C++ library that performs various operations on matrices, including addition, subtraction, multiplication, inversion, and more.

#### Key Features:

   - Matrix creation from default values or 2D arrays.
   - Operations like addition, subtraction, multiplication, transposition, and inversion.
   -Methods for calculating the determinant and trace of matrices.
   - Static methods to create special matrices (zero, identity, ones).
   -Support for dot product, magnitude, and matrix printing.

#### Example Output:
!(![Screenshot from 2025-01-09 21-36-58](https://github.com/user-attachments/assets/40197fd1-e1cc-4499-ada8-853babc4d23d)
)


#### Compilation:

1- Use a C++ compiler like g++:
```bash
g++ main.cpp -o matrix_program
```

2- Run the program:
```bash
./matrix_program
```

#### Dependencies

C++11 or higher: Required for features like std::vector, exceptions, etc.
cmath: For mathematical operations like calculating magnitudes and square roots.


### Contact

For any issues or questions please reach out to Irem Aslan at iremaslan0420@hotmail.com.
