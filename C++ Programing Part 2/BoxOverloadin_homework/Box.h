#pragma once

#include <iostream>

class Box {
    friend Box operator+(Box, Box);
    friend Box operator-(Box, Box);

public:

    Box(int, int, int);

    void setWidth(int);
    void setHeigth(int);
    void setLength(int);

    int getWidth() const;
    int getHeight() const;
    int getLength() const;

    void printBox() const;

private:

    int _width;
    int _height;
    int _length;
};
