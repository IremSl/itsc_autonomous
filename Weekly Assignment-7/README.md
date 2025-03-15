
# Path Planner Node

## Overview
This is a ROS 2 (Robot Operating System 2) package that implements a path planner for Turtlesim. The node spawns a turtle at a predefined position and moves it to randomly generated targets while avoiding walls and ensuring the target is at least half the window size away from the initial position.

## Features
- Spawns a turtle in the Turtlesim environment
- Reads the turtle's current pose
- Generates a new target position that:
  - Is not too close to walls
  - Is at least 3.0 units away from the current position
- Moves the turtle towards the target
- Continuously selects new targets upon reaching the previous one

## Installation
### Prerequisites
Ensure that you have ROS 2 and the Turtlesim package installed:
```bash
sudo apt update && sudo apt install ros-humble-turtlesim
```
*(Replace `humble` with your ROS 2 distribution if different.)*

### Clone the Repository
Navigate to your ROS 2 workspace and clone the repository:
```bash
cd ~/ros2_ws/src
git clone <repository-url>
```

### Build the Package
After cloning, build the package:
```bash
cd ~/ros2_ws
colcon build --packages-select path_planner
```

### Source the Setup File
Before running the node, source your workspace:
```bash
source install/setup.bash
```

## Usage
### Launching the Node
To start the path planner node, run:
```bash
ros2 run path_planner path_planner_node
```
When prompted, enter `r` to start the movement.

### Expected Behavior
- The turtle starts at `(5.0, 5.0)`.
- It moves towards randomly generated targets that are at least 3.0 units away from its current position.
- The turtle avoids moving too close to the walls.
- After reaching a target, it pauses for 2 seconds before selecting a new one.

 ![](https://github.com/user-attachments/assets/0e30a518-1146-4768-a210-82d05191a4a1)
 

## Code Structure
```
path_planner/
├── include/
├── src/
    ├── path_planner.cpp  # Implementation of the node
    ├── CMakeLists.txt  # CMake build file
    ├── package.xml  # ROS 2 package metadata

```



## Contact
For any issues or questions please reach out to Irem Aslan at iremaslan0420@hotmail.com.
