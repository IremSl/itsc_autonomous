#include <iostream>
#include <cmath>


enum class Region {
    First,    // x > 0, y > 0, z > 0
    Second,   // x < 0, y > 0, z > 0
    Third,    // x < 0, y < 0, z > 0
    Fourth,   // x > 0, y < 0, z > 0
    Fifth,    // x > 0, y > 0, z < 0
    Sixth,    // x < 0, y > 0, z < 0
    Seventh,  // x < 0, y < 0, z < 0
    Eighth,   // x > 0, y < 0, z < 0
    Origin    // x == 0, y == 0, z == 0
};


struct Point {
    float x, y, z;

    
    Point(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

   
    float zero_distance() const {
        return std::sqrt(x * x + y * y + z * z);
    }

   
    static float distance(const Point& p1, const Point& p2) {
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                         (p1.y - p2.y) * (p1.y - p2.y) +
                         (p1.z - p2.z) * (p1.z - p2.z));
    }

    
    static Point compare(const Point& p1, const Point& p2) {
        return (p1.zero_distance() > p2.zero_distance()) ? p1 : p2;
    }

    
    Region region() const {
        if (x == 0 && y == 0 && z == 0) return Region::Origin;
        if (x > 0 && y > 0 && z > 0) return Region::First;
        if (x < 0 && y > 0 && z > 0) return Region::Second;
        if (x < 0 && y < 0 && z > 0) return Region::Third;
        if (x > 0 && y < 0 && z > 0) return Region::Fourth;
        if (x > 0 && y > 0 && z < 0) return Region::Fifth;
        if (x < 0 && y > 0 && z < 0) return Region::Sixth;
        if (x < 0 && y < 0 && z < 0) return Region::Seventh;
        if (x > 0 && y < 0 && z < 0) return Region::Eighth;
        return Region::Origin; // Default (shouldn't be reached)
    }

    
    static bool is_in_same_region(const Point& p1, const Point& p2) {
        return p1.region() == p2.region();
    }

    
    static std::string region_to_string(Region r) {
        switch (r) {
            case Region::First: return "First";
            case Region::Second: return "Second";
            case Region::Third: return "Third";
            case Region::Fourth: return "Fourth";
            case Region::Fifth: return "Fifth";
            case Region::Sixth: return "Sixth";
            case Region::Seventh: return "Seventh";
            case Region::Eighth: return "Eighth";
            case Region::Origin: return "Origin";
            default: return "Unknown";
        }
    }
};

int main() {
    
    Point p1(3, 4, 5);
    Point p2(5, 12, 13);
    Point p3(1, 1, 1);
    Point p4(0, 0, 0);

    
    std::cout << "Distance of p1 from origin: " << p1.zero_distance() << std::endl;
    std::cout << "Distance between p1 and p2: " << Point::distance(p1, p2) << std::endl;

    Point further = Point::compare(p1, p2);
    std::cout << "Point further from origin: (" << further.x << ", " << further.y << ", " << further.z << ")" << std::endl;

    std::cout << "Region of p1: " << Point::region_to_string(p1.region()) << std::endl;
    std::cout << "Region of p2: " << Point::region_to_string(p2.region()) << std::endl;
    std::cout << "Are p1 and p2 in the same region? " << (Point::is_in_same_region(p1, p2) ? "Yes" : "No") << std::endl;

    return 0;
}
