#include "Box.h"

static bool validateNumber(int num) {
    if (num > 0) {
        return true;
    }

    return false;
}

Box::Box(int width, int height, int length) {
    setWidth(width);
    setHeigth(height);
    setLength(length);
}

void Box::setWidth(int width) {
    while (!validateNumber(width)) {
        std::cout << "Invalid width! Enter a new one positive: ";
        std::cin >> width;
    }

    this->_width = width;
}

void Box::setHeigth(int height) {
    while (!validateNumber(height)) {
        std::cout << "Invalid height! Enter a new one positive: ";
        std::cin >> height;
    }

    this->_height = height;
}

void Box::setLength(int length) {
    while (!validateNumber(length)) {
        std::cout << "Invalid length! Enter a new one positive: ";
        std::cin >> length;
    }

    this->_length = length;
}

int Box::getWidth() const {
    return this->_width;
}

int Box::getHeight() const {
    return this->_height;
}

int Box::getLength() const {
    return this->_length;
}

void Box::printBox() const {
    std::cout << "Box size is. Width: " << this->getWidth() << ", Height: " << getHeight() << " and Length: "
        << this->getLength() << std::endl;
}

Box operator+(Box b1, Box b2) {
    int width = b1.getWidth() + b2.getWidth();
    return Box(width, b1.getHeight(), b1.getLength());
}

Box operator-(Box b1, Box b2) {
    int width = b1.getWidth() - b2.getWidth();
    return Box(width, b1.getHeight(), b1.getLength());
}
