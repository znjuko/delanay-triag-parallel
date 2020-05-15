//
// Created by znjuko on 14.05.2020.
//

#include "point.h"

template<typename Type>
Point<Type>::Point() : X(0), Y(0), Z(0) {};

template<typename Type>
Point<Type>::Point(Type x, Type y, Type z) : X(x), Y(y), Z(z) {};

template<typename Type>
Point<Type>::~Point<Type>() {
    X = 0;
    Y = 0;
    Z = 0;
};

template<typename Type>
Type Point<Type>::GetX() {
    return this->X;
};

template<typename Type>
Type Point<Type>::GetY() {
    return this->Y;
};

template<typename Type>
Type Point<Type>::GetZ() {
    return this->Z;
};

template<typename Type>
bool Point<Type>::operator != (Point<Type> point) {

    if(this->X != point.X || this->Z != point.Z || this->Z != point.Z) {
        return true;
    }

    return false;
};

template<class T>
std::ostream &operator<<(std::ostream &out, const Point<T> &point) {
    out << "Point(" << "X:" << point.X << "|" << "Y:" << point.Y << "|" << "Z:" << point.Z << ")";
    return out;
};