//
// Created by znjuko on 14.05.2020.
//

#ifndef KURS_LINE_H
#define KURS_LINE_H

#include "point.h"

template<typename Type>
class Line {
public:
    Line();

    Line(Point<Type> left, Point<Type> right);
    Point<Type> GetLeft();
    Point<Type> GetRight();
    Type GetLength();
    template<class T>
    friend std::ostream &operator<<(std::ostream &out, const Line<T> &line);

private:
    Point<Type> LefPoint;
    Point<Type> RightPoint;
    Point<Type> Guide;
    Type Length;
};

#endif //KURS_LINE_H
