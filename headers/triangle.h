//
// Created by znjuko on 14.05.2020.
//

#ifndef KURS_TRIANGLE_H
#define KURS_TRIANGLE_H

#include "line.h"

template<typename Type>
class Triangle {
public:
    Triangle();

    Triangle(Line<Type> first, Line<Type> second, Line<Type> third);
    float GetArea();
    float GetPerimeter();
    float GetCRadius();
    float GetIRadius();
    float GetQuality();
    template<class T>
    friend std::ostream &operator<<(std::ostream &out, const Triangle<T> &triangle);

private:
    Line<Type> First;
    Line<Type> Second;
    Line<Type> Third;
    float Perimeter;
    float Area;
    float CircumRadius;
    float InRadius;
    float Quality;
};

#endif //KURS_TRIANGLE_H
