# ITU SCT Autonomous Group
This repository contains solutions to weekly assignments given by ITU SCT Autonomous Group.

![](https://github.com/user-attachments/assets/3bd6bc5c-5c48-4853-8c19-b863d7f5a7c1)

#  ITU Solar Car Team - Autonomous Driving Training Journey

![ITU Solar Car Team](https://img.shields.io/badge/Team-ITU%20Solar%20Car-blue) ![Role-Autonomous%20Software](https://img.shields.io/badge/Role-Autonomous%20Software%20Developer-green) 

##  Overview

This repository documents my training journey as a member of the **ITU Solar Car Team - Autonomous Division**. 

The primary goal of the autonomous team is to develop software that enables our solar-powered vehicle to detect obstacles, navigate tracks, and complete competitions autonomously. To prepare for this complex task, I completed a series of **Weekly Assignments** designed to progressively build skills ranging from fundamental C++ logic to advanced memory management, Object-Oriented Programming (OOP), ROS 2 architecture, and finally, autonomous vehicle simulation.

This roadmap culminates in a **Lane Keeping Assist System (LKAS)** implementation within the **CARLA Simulator**.

---

##  Learning Roadmap & Projects

The training consisted of 5 main modules, increasing in complexity:

| Phase | Project | Key Concepts |
| :--- | :--- | :--- |
| **1** | [C++ Fundamentals](#1-c-fundamentals-matrix-calculator--point-structure) | Math logic, libraries, simple algorithms |
| **2** | [Advanced C++ Concepts](#2-advanced-c-variables--pointers) | Memory management, Smart Pointers, Optimization |
| **3** | [OOP & Logic Design](#3-object-oriented-design-restaurant-bot) | JSON parsing, Class hierarchy, User Interaction |
| **4** | [ROS 2 Introduction](#4-ros-2-path-planner-turtlesim) | Nodes, Topics, Publishers/Subscribers, Motion Planning |
| **5** | [Capstone: CARLA Simulation](#5-capstone-autonomous-lane-keeping-in-carla) | Computer Vision, Control Theory, Simulation |

---

## 1. C++ Fundamentals: Matrix, Calculator & Point Structure

The first phase focused on mastering C++ syntax and logical problem solving. This module contains three sub-projects:

1.  **Point Structure:** A 3D coordinate system implementation.
    * *Features:* Euclidean distance calculation, region classification (8 regions in 3D space).
    * 
    * *(See typical output below)*
    * ![](https://github.com/user-attachments/assets/50fe26f5-8b36-48b0-b867-db0a182fe049)

2.  **Calculator:** A command-line arithmetic tool.
    * *Features:* Basic operations (+, -, *, /) plus advanced math (Modulus, Exponentiation).
    * ![](https://github.com/user-attachments/assets/b58df821-75c8-47c9-ad58-b54ed25750f9)

3.  **Matrix Library:** A comprehensive library for linear algebra.
    * *Features:* Matrix inversion, transposition, determinant calculation, and multiplication. Critical for future control theory tasks.
    * ![](https://github.com/user-attachments/assets/40197fd1-e1cc-4499-ada8-853babc4d23d)

---

## 2. Advanced C++: Variables & Pointers

In autonomous driving, efficient memory usage is crucial. This module explored the depths of C++ memory management.

### Key Topics Covered:
* **Smart Pointers:** `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr` to prevent memory leaks.
* **Raw vs. Wild Pointers:** Understanding dangerous memory access patterns.
* **Numeric Limits & Fixed-Width Types:** Using `int32_t`, `uint64_t` for hardware-specific consistency.
* **Optimization:** Usage of `auto`, `const`, and `constexpr`.

**Memory Size Analysis:**
![](https://github.com/user-attachments/assets/fe93dadc-a182-4ea4-8968-5bffb8c853b1)

**Smart Pointer Execution:**
![](https://github.com/user-attachments/assets/5b71de0f-1385-4023-8b6c-127bfdaee869)

---

## 3. Object Oriented Design: Restaurant Bot

This project simulated a real-world application to practice **Object-Oriented Programming (OOP)** and **Data Handling**.

### Features:
* **Dynamic Menu:** Loads menu items from a `menu.json` file (JSON Parsing).
* **Customization:** Users can customize orders (e.g., "Extra shot", "No sugar").
* **Recommendation Engine:** Generates menu suggestions based on user taste profiles.
* **Logic:** Handles complex state management for user selections.

**User Interface:**
![](https://github.com/user-attachments/assets/113cf485-c647-4cb6-8274-9a77ba6519cf)

---

## 4. ROS 2 Path Planner (Turtlesim)

Transitioning from pure C++ to robotics, this project introduced the **Robot Operating System 2 (ROS 2)**.

### The Mission:
Create a node that autonomously drives a turtle to random targets while:
1.  **Avoiding Walls:** Ensuring the robot stays within bounds.
2.  **Minimum Distance Check:** Targets must be at least 3.0 units away.
3.  **Feedback Loop:** Subscribing to `/turtle1/pose` and publishing to `/turtle1/cmd_vel`.

**Technologies:** ROS 2 Humble, C++, CMake.

**Simulation Output:**
![](https://github.com/user-attachments/assets/0e30a518-1146-4768-a210-82d05191a4a1)

---

## 5. Capstone: Autonomous Lane Keeping in CARLA

The final and most challenging task of the training series. This project integrates all previous learnings (C++, Linear Algebra/Matrix, ROS 2) into a high-fidelity simulation.

### Project Description
Using the **CARLA Simulator**, I developed a software stack for an autonomous vehicle to perform **Lane Keeping**. The system processes sensor data to keep the vehicle centered in its lane on a winding track.

### Key Components:
* **Computer Vision:** Processing camera feed to detect lane lines (Canny Edge Detection, Hough Transform).
* **Control System:** Implementing PID controllers to adjust steering angle based on the vehicle's deviation from the lane center.
* **Simulation Environment:** Testing the vehicle's stability and response time in the CARLA physics engine.

*(Note: The full source code and detailed documentation for the Carla Lane Keeping project are hosted in a separate dedicated repository linked below.)*

 **[Link to CARLA Lane Keeping Repository]** *[https://github.com/IremSl/CARLA_autonomous-vehicle]*

---

##  Technologies & Tools

* **Languages:** C++ (C++11/14/17), Python
* **Frameworks:** ROS 2 (Humble/Foxy)
* **Simulation:** CARLA Simulator, Turtlesim
* **Build Systems:** CMake, GCC/G++
* **Version Control:** Git, GitHub
* **Libraries:** nlohmann/json, standard C++ libraries

---

##  Contact

If you have any questions about these projects or my journey in the ITU Solar Car Team, feel free to reach out:

**Irem Aslan**  Email: iremaslan0420@hotmail.com  
 LinkedIn: [www.linkedin.com/in/aslan-irem]

---
*This repository is a compilation of weekly assignments completed for the ITU Solar Car Team Autonomous Division.*





