# C++ Fundamentals: Variable Types and Keywords

This repository contains C++ code examples and explanations related to various topics of C++ programming, including variable types, pointers, limits, and modern C++ keywords such as `auto`, `const`, and `constexpr`. The code snippets in this repository cover:

- **Pointer Sizes**: Understanding the size of pointers for different types.
- **Numeric Limits**: Exploring the lower and upper bounds of various numeric types.
- **Auto Keyword**: Demonstrating the usage of the `auto` keyword for type inference.
- **Const and Constexpr Keywords**: Explaining how `const` and `constexpr` are used to define constant variables and optimize compile-time computation.
- **Fixed-Width Types**: Using fixed-width types like `int32_t` and `uint64_t` for guaranteed bit-width integers and floating-point types.

### Project Structure

This project includes:

- **Code Examples**: The LaTeX document provides annotated C++ code snippets to demonstrate different topics.
- **Figures**: Visuals are included to help better understand concepts such as pointer sizes and numeric limits.

### Key Concepts Covered

#### Pointer Sizes

This section demonstrates how to find the size of pointers for various data types in C++.

long double g = 10;
long double* pointerlongDouble = &g;
cout << "Pointer long double --> " << sizeof(pointerlongDouble) << endl;

#### Numeric Limits

This section covers the numeric_limits template from the <limits> header, which provides the minimum and maximum values for different types such as int, float, double, and more.

#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "Lower limit of int: " << numeric_limits<int>::min() << endl;
    cout << "Upper limit of int: " << numeric_limits<int>::max() << endl;
    // Additional limits for other types
}

#### Auto Keyword

In this section, the auto keyword is explained, showing how it allows the compiler to deduce the type of a variable automatically.

auto a = 10;    // 'a' is deduced to be of type 'int'
auto b = 10.5;  // 'b' is deduced to be of type 'double'

#### Const and Constexpr Keywords

This section explains the use of the const and constexpr keywords. const ensures that a variable's value cannot be modified, while constexpr forces evaluation at compile-time.

Examples include:

    Constant variables and pointers.
    Constant expressions evaluated at compile-time for better performance.

const int x = 15;
constexpr int max_size = 100;

#### Fixed-Width Types

C++ offers fixed-width types such as int32_t and uint64_t for guaranteed bit-width integers. This section covers their usage.

int32_t a = 100;   // 32-bit signed integer
uint64_t b = 1000; // 64-bit unsigned integer
