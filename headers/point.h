//
// Created by znjuko on 14.05.2020.
//

#ifndef KURS_POINT_H
#define KURS_POINT_H

template<typename Type>
class Point {
public:
    Point();

    Point(Type x, Type y, Type z);

    ~Point();

    Type GetX();

    Type GetY();

    Type GetZ();

    bool operator != (Point<Type> point);

    template<class T>
    friend std::ostream &operator<<(std::ostream &out, const Point<T> &point);

private:
    Type X;
    Type Y;
    Type Z;
};


#endif //KURS_POINT_H
