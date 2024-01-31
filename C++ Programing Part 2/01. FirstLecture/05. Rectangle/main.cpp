#include <iostream>
#include <cmath>

class Rectangle {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4; // Coordinates of the four corners

public:
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        setCoordinates(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    // Set coordinates
    void setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {

        // Check if all coordinates are in the first quadrant
        if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x3 >= 0 && y3 >= 0 && x4 >= 0 && y4 >= 0) {

            // Check if all coordinates is under or equal of 20
            if (x1 <= 20 && y1 <= 20 && x2 <= 20 && y2 <= 20 && x3 <= 20 && y3 <= 20 && x4 <= 20 && y4 <= 20) {

                // Check if the coordinates form a rectangle
                if (isRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
                    this->x1 = x1;
                    this->y1 = y1;
                    this->x2 = x2;
                    this->y2 = y2;
                    this->x3 = x3;
                    this->y3 = y3;
                    this->x4 = x4;
                    this->y4 = y4;
                }
                else {
                    std::cerr << "Invalid coordinates: Do not form a rectangle.\n";
                }
            }
            else {
                std::cerr << "Invalid coordinates: Must be under 20. \n";
            } 
        }
        else {
            std::cerr << "Invalid coordinates: Must be in the first quadrant.\n";
        }
    }

    // Function to check if the coordinates form a rectangle
    bool isRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        double side1 = calculateDistance(x1, y1, x2, y2);
        double side2 = calculateDistance(x2, y2, x3, y3);
        double side3 = calculateDistance(x3, y3, x4, y4);
        double side4 = calculateDistance(x4, y4, x1, y1);

        // Check if the opposite sides are equal (rectangle property)
        return (side1 == side3) && (side2 == side4);
    }

    // Function to calculate the distance between two points
    double calculateDistance(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    // Function to calculate the length of the rectangle
    double calculateLength() {
        if (calculateDistance(x1, y1, x2, y2) > calculateDistance(x2, y2, x3, y3)) {
            return calculateDistance(x1, y1, x2, y2);
        }
        
        return calculateDistance(x2, y2, x3, y3);
    }

    // Function to calculate the width of the rectangle
    double calculateWidth() {
        if (calculateDistance(x1, y1, x2, y2) > calculateDistance(x2, y2, x3, y3)) {
            return calculateDistance(x2, y2, x3, y3);
        }
        return calculateDistance(x1, y1, x2, y2);
    }

    // Function to calculate the perimeter of the rectangle
    double calculatePerimeter(double &length, double &width) {
        return 2 * (length + width);
    }

    // Function to calculate the area of the rectangle
    double calculateArea(double& length, double& width) {
        return length * width;
    }

    // Predicate function to check if the rectangle is a square
    bool isSquare(double& length, double& width) {
        return length == width;
    }
};

int main() {
    //// Example usage
    //Rectangle myRectangle(0, 0, 0, 4, 3, 0, 3, 4);

    //double length = myRectangle.calculateLength();
    //double width = myRectangle.calculateWidth();
    //double perimeter = myRectangle.calculatePerimeter(length, width);
    //double area = myRectangle.calculateArea(length, width);

    //std::cout << "Length: " << length << std::endl;
    //std::cout << "Width: " << width << std::endl;
    //std::cout << "Perimeter: " << perimeter << std::endl;
    //std::cout << "Area: " << area << std::endl;

    //if (myRectangle.isSquare(length, width)) {
    //    std::cout << "The rectangle is a square.\n";
    //}
    //else {
    //    std::cout << "The rectangle is not a square.\n";
    //}

    Rectangle myRectangle2(21, 0, 0, 4, 3, 0, 3, 4);

    double length = myRectangle2.calculateLength();
    double width = myRectangle2.calculateWidth();
    double perimeter = myRectangle2.calculatePerimeter(length, width);
    double area = myRectangle2.calculateArea(length, width);

    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    if (myRectangle2.isSquare(length, width)) {
        std::cout << "The rectangle is a square.\n";
    }
    else {
        std::cout << "The rectangle is not a square.\n";
    }

    return 0;
}
