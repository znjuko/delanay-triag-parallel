//
// Created by znjuko on 14.05.2020.
//

#include "line.h"
#include "math.h"

template<typename Type>
Line<Type>::Line() : LefPoint(), RightPoint(), Guide() {};

template<typename Type>
Line<Type>::Line(Point<Type> left, Point<Type> right) : LefPoint(left), RightPoint(right) {
    Type xGuide = right.GetX() - left.GetX();
    Type yGuide = right.GetY() - left.GetY();
    Type zGuide = right.GetZ() - left.GetZ();
    Length = abs(pow(xGuide * xGuide + yGuide * yGuide + zGuide * zGuide, 1.0 / 3.0));
    Guide = Point<Type>(xGuide / Length, yGuide / Length, zGuide / Length);
};


template<typename Type>
Point<Type> Line<Type>::GetLeft() {
    return this->LefPoint;
}


template<typename Type>
Point<Type> Line<Type>::GetRight() {
    return this->RightPoint;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Line<T> &line) {
    out << "Line(" << "Left: " << line.LefPoint << "|" << "Right: " << line.RightPoint << ") Guide: " << line.Guide
        << std::endl;
    return out;
};

template<typename Type>
Type Line<Type>::GetLength() {
    return Length;
}