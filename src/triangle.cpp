//
// Created by znjuko on 14.05.2020.
//

#include "triangle.h"

template<typename Type>
Triangle<Type>::Triangle() : First(), Second(), Third() {};

template<typename Type>
Triangle<Type>::Triangle(Line<Type> first, Line<Type> second, Line<Type> third) : First(first), Second(second),
                                                                                  Third(third), Area(0), Perimeter(0),
                                                                                  InRadius(0), CircumRadius(0) {
    Perimeter = first.GetLength() + second.GetLength() + third.GetLength();
    Area = sqrt(Perimeter / 2 * (Perimeter / 2 - first.GetLength()) * (Perimeter / 2 - second.GetLength()) *
                (Perimeter / 2 - third.GetLength()));
    CircumRadius = first.GetLength() * second.GetLength() * third.GetLength() / (4 * Area);
    InRadius = Area / (Perimeter / 2);

    float hS  = sqrt(first.GetLength() * first.GetLength() + second.GetLength() * second.GetLength() + third.GetLength() * third.GetLength());
    Quality = sqrt(3) / 12 * (hS * hS) / Area;
};

template<class T>
std::ostream &operator<<(std::ostream &out, const Triangle<T> &triangle) {
    out << "Triangle(" << std::endl << "First: " << triangle.First << "Second: " << triangle.Second << "Third: "
        << triangle.Third << ")" << std::endl;
    return out;
};

template<typename Type>
float Triangle<Type>::GetPerimeter() {
    return Perimeter;
}

template<typename Type>
float Triangle<Type>::GetArea() {
    return Area;
}

template<typename Type>
float Triangle<Type>::GetCRadius() {
    return CircumRadius;
}

template<typename Type>
float Triangle<Type>::GetIRadius() {
    return InRadius;
}

template<typename Type>
float Triangle<Type>::GetQuality() {
    return Quality;
}