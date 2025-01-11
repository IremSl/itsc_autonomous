# C++ VARIABLES

---
This repository contains C++ code examples and explanations for various topics related to variables, pointers, and modern C++ keywords. The topics include variable sizes, pointer sizes, numeric limits, and the use of `auto`, `const`, and `constexpr` keywords.The code snippets in this repository cover:

- **Pointer Sizes**: Understanding the size of pointers for different types.
- **Numeric Limits**: Exploring the lower and upper bounds of various numeric types.
- **Auto Keyword**: Demonstrating the usage of the `auto` keyword for type inference.
- **Const and Constexpr Keywords**: Explaining how `const` and `constexpr` are used to define constant variables and optimize compile-time computation.
- **Fixed-Width Types**: Using fixed-width types like `int32_t` and `uint64_t` for guaranteed bit-width integers and floating-point types.
---

### Project Structure

This project includes:

- **Code Examples**: The LaTeX document provides annotated C++ code snippets to demonstrate different topics.
- **Figures**: Visuals are included to help better understand concepts such as pointer sizes and numeric limits.
---

## Table of Contents

1. [Sizes of Variables](#c-variables)
2. [Sizes of Pointers](#sizes-of-pointers)
3. [Numeric Limits](#numeric-limits)
4. [Auto Keyword](#auto-keyword)
5. [Const and Constexpr Keywords](#const-and-constexpr-keywords)
   
### Key Concepts Covered

#### Sizes of Variables

In this section, various data types are used to demonstrate their respective sizes in bytes.

```cpp
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << left << "======================";
    cout << setw(10) << right << "======================" << endl;
    cout << setw(10) << left << "Type";
    cout << setw(2) << right << " ";
    cout << setw(14) << right << "Size" << endl;
    cout << setw(10) << left << "======================";
    cout << setw(10) << right << "======================" << endl;

    cout << setw(10) << left << "int";
    cout << setw(2) << right << " ";
    cout << setw(12) << right << sizeof(int) << endl;
    cout << setw(10) << left << "short int";
    cout << setw(2) << right << " ";
    cout << setw(12) << right << sizeof(short int) << endl;
    // Additional size demonstrations...
}

```
![](https://github.com/user-attachments/assets/fe93dadc-a182-4ea4-8968-5bffb8c853b1)


---
#### Sizes of Pointers

This section demonstrates how to find the size of pointers for various data types in C++.

```cpp
long double g = 10;
long double* pointerlongDouble = &g;
cout << "Pointer long double --> " << sizeof(pointerlongDouble) << endl;
```
![](https://github.com/user-attachments/assets/88479061-23a2-41cd-bda9-74fb0824100e)

---
#### Numeric Limits

This section covers the numeric_limits template from the <limits> header, which provides the minimum and maximum values for different types such as int, float, double, and more.

```cpp
#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "Lower limit of int: " << numeric_limits<int>::min() << endl;
    cout << "Upper limit of int: " << numeric_limits<int>::max() << endl;
    // Additional limits for other types
}
```
![](https://github.com/user-attachments/assets/cf65db55-a9b8-452e-8303-ac6485555e6a)

---
#### Auto Keyword

In this section, the auto keyword is explained, showing how it allows the compiler to deduce the type of a variable automatically.

```cpp
auto a = 10;    // 'a' is deduced to be of type 'int'
auto b = 10.5;  // 'b' is deduced to be of type 'double'
```
---
#### Const and Constexpr Keywords

This section explains the use of the const and constexpr keywords. const ensures that a variable's value cannot be modified, while constexpr forces evaluation at compile-time.

Examples include:

  -  **Constant variables and pointers.**
  -  **Constant expressions evaluated at compile-time for better performance.**
    
```cpp
const int x = 15;
```

```cpp
constexpr int max_size = 100;
```
---
#### Fixed-Width Types

C++ offers fixed-width types such as int32_t and uint64_t for guaranteed bit-width integers. This section covers their usage.

```cpp
int32_t a = 100;   // 32-bit signed integer
uint64_t b = 1000; // 64-bit unsigned integer
```

---
---

# C++ POINTERS

---
This repository explores various concepts related to Pointers and memory management in C++, including the mechanisms of garbage collection, smart pointers, raw pointers, and common memory management pitfalls. It covers key topics such as:

   - **The fundamentals of Pointers, including their types and usage.**
   - **An overview of Garbage Collection Mechanism and its relevance in C++.**
   - **A detailed guide to Smart Pointers and their various forms:**
        - **Void Pointer, Null Pointer Auto Pointer, Unique Pointer, Shared Pointer, and Weak Pointer.**
   - **Applications of Smart Pointers in modern C++ programming.**
   - **Challenges such as Raw Pointers, Wild Pointers, Data Inconsistency, and Buffer Overflow.**
   - **Understanding Ownership Models in C++ with `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.**

This guide aims to provide a comprehensive understanding of memory management techniques in C++, ensuring better management of resources, safer code, and improved application performance.

## Table of Contents

- [**Pointers**](#pointers)
- [**Garbage Collection Mechanism**](#garbage-collection-mechanism)
- [**Smart Pointers**](#smart-pointers)
  - [Void Pointer](#void-pointer)
  - [Null Pointer](#null-pointer)
  - [Auto Pointer](#auto-pointer)
  - [Unique Pointer](#unique-pointer)
  - [Shared Pointer](#shared-pointer)
  - [Weak Pointer](#weak-pointer)
- [**Applications of Smart Pointers**](#applications-of-smart-pointers)
- [**Raw Pointers**](#raw-pointers)
- [**Wild Pointers**](#wild-pointers)
- [**Data Inconsistency**](#data-inconsistency)
- [**Buffer Overflow**](#buffer-overflow)
- [**Ownership Models**](#ownership-models)
  - [std::unique_ptr](#stdunique_ptr)
  - [std::shared_ptr](#stdshared_ptr)
  - [std::weak_ptr](#stdweak_ptr)

 ## 1- Pointers

In C++, a pointer is a variable that holds the memory address of another variable. Instead of directly storing data, a pointer stores the location where the data is stored in memory.

```cpp
int a = 5;
int* ptr = &a;  // ptr now holds the address of 'a'
```
### Key Operations:

Dereferencing: Access the value at the memory address the pointer is pointing to.
    
```cpp
std::cout << *ptr;  // Prints the value of 'a'
```
 Modifying Value via Pointer:
    
```cpp
*ptr = 20;  // Modifies the value of 'a' indirectly via pointer
```
---
## Garbage Collection Mechanism

Garbage collection is an automatic memory management technique where memory occupied by variables or objects no longer in use is collected and freed. C++ does not have built-in garbage collection, but it supports manual memory management. C++ also provides smart pointers to manage memory efficiently.

---

## Smart Pointers

### Void Pointer

A void* is a pointer that can point to any data type, making it a general-purpose pointer.

```cpp
int intVar = 10;
void* ptr = &intVar;  // Void pointer can store any address
```
### Null Pointer

A null pointer is used to indicate that a pointer is not pointing to any valid memory address. It is often used to initialize pointers and check for valid memory addresses.

```cpp
int* ptr = nullptr;
if (ptr == nullptr) {
    std::cout << "Pointer is null." << std::endl;
}
```

### Auto Pointer

auto_ptr is a smart pointer that manages dynamically allocated memory. It automatically deletes the managed object when the auto_ptr goes out of scope, thus preventing memory leaks.

```cpp
auto_ptr<int> ptr(new int(10));
```

### Unique Pointer

unique_ptr is a smart pointer that ensures a resource is owned by only one pointer. It cannot be copied but can be moved.
```cpp

std::unique_ptr<int> ptr(new int(10));
```
Example:


```cpp
std::unique_ptr<A> p1(new A);
p1->printA();  // Prints output using unique pointer
```

### Shared Pointer

shared_ptr allows multiple pointers to share ownership of the same resource. It maintains a reference count that ensures proper deallocation when all references are gone.

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
```
Example:

```cpp
std::shared_ptr<A> p1(new A);
std::cout << p1.use_count() << std::endl;  // Displays reference count
```

### Weak Pointer

weak_ptr is a non-owning pointer that works alongside shared_ptr to prevent cyclic dependencies. It doesn't affect the reference count, thus allowing an object to be deleted when there are no owning shared_ptr references left.

```cpp

std::weak_ptr<A> weakPtr;
```

Example:
```cpp
std::shared_ptr<A> p1 = std::make_shared<A>();
std::weak_ptr<A> weakPtr = p1;
```

### Applications of Smart Pointers

 **Preventing Circular References**: weak_ptr helps avoid memory leaks caused by cyclic dependencies between shared_ptr objects.
 **Efficient Resource Management**: Smart pointers automate memory management, making it safer and easier to manage dynamically allocated memory.
 
---
    
## Raw Pointers

A **raw pointer** in C++ is a basic pointer that holds the memory address of a variable or an object. It does not provide any additional memory management features, meaning the programmer must manually allocate and deallocate memory.

### Advantages:

- Manual memory allocation/deallocation gives complete control.
- Minimal performance overhead compared to smart pointers.
- No runtime dependencies, making it ideal for embedded systems.
- Enables interoperability with C libraries and legacy systems.

### Problems:

- **Memory Leaks**: If memory is not properly deallocated, it leads to memory leaks.
- **Dangling Pointers**: Using a pointer after the memory has been freed leads to undefined behavior.

```cpp
int* ptr = new int(10);
// Forgetting to delete causes a memory leak
```
```cpp
int* ptr = new int(10);
delete ptr;
std::cout << *ptr; // Accessing deleted memory (dangling pointer)
```
---
## Wild Pointers

A wild pointer refers to a pointer that points to an invalid or uninitialized memory location. It can result in undefined behavior and serious bugs such as crashes or memory corruption.
Example:
```cpp
int* p;  // Wild pointer
*p = 12; // Undefined behavior: p points to unknown memory
```
```cpp
int main() {
    int* p;  // p is a wild pointer
    int a = 10;
    p = &a;  // p is now pointing to a valid memory location
}
```

---

## Data Inconsistency

Data inconsistency occurs when data across multiple locations or systems doesn't align. This can result from mismatched data, outdated versions, duplication, or lack of synchronization.

  **Mismatched Data**: Data in multiple locations does not match.
  
  **Different Versions of Data**: One part of the system uses an outdated value.
  
  **Data Duplication**: Failing to update all copies of data leads to inconsistency.
  
  **Lack of Synchronization**: Distributed systems can experience inconsistency if data isn't properly synchronized.
  
  **Concurrency Problems**: Multi-user systems may experience inconsistency when multiple users update the same data simultaneously.
  
---

## Buffer Overflow

A buffer overflow occurs when more data is written to a buffer than it can hold. This can overwrite adjacent memory and cause unpredictable behavior, including security vulnerabilities.

**Consequences**:

-Memory corruption, potentially overwriting critical data.


-Program crashes due to corrupted control structures.

-Security vulnerabilities like code injection or taking control of program flow.

```cpp
char buffer[10];
strcpy(buffer, "This is too long!"); // This causes a buffer overflow
```
---

## Ownership Models

C++ provides different models for managing the ownership of dynamically allocated memory. These models help prevent common memory management issues such as memory leaks and dangling pointers.

### std::unique_ptr

  **Ownership model**: Exclusive ownership. Only one std::unique_ptr can own a given resource. Ownership can be transferred using std::move().
  
  **When to Use**:

 Use when you need exclusive ownership and automatic memory management for a resource.
    
  ```cpp
  std::unique_ptr<int> ptr(new int(10)); // Ownership is exclusive
  ```

### std::shared_ptr


  **Ownership model**: Shared ownership. Multiple std::shared_ptr objects can share ownership of the same resource. The resource is deleted when the last shared_ptr goes out of scope.
  
  **When to Use**:

 Use when multiple parts of your program need access to a resource, and the resource should only be deleted when all owners are done with it.

  ```cpp
  std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
  std::shared_ptr<int> ptr2 = ptr1; // Both ptr1 and ptr2 share ownership
  ```

### std::weak_ptr

  **Ownership model**: Non-owning reference. A std::weak_ptr observes an object managed by a std::shared_ptr without affecting the reference count.
  
  **When to Use**:
  
 Use to avoid circular references or to observe an object without preventing its deletion.
    
  ```cpp
  std::weak_ptr<int> weak_ptr = ptr1; // weak_ptr does not affect reference count
  ```
---
### Output of Creating Smart Pointers

![](https://github.com/user-attachments/assets/5b71de0f-1385-4023-8b6c-127bfdaee869)


## CONTACT

For any issues or questions please reach out to Irem Aslan at iremaslan0420@hotmail.com.
