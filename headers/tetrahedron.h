//
// Created by znjuko on 15.05.2020.
//

#ifndef KURS_TETRAHEDRON_H
#define KURS_TETRAHEDRON_H

#endif //KURS_TETRAHEDRON_H

template<typename Type>
class Tetrahedron {
public :
    Tetrahedron(Point<Type> p1, Point<Type> p2, Point<Type> p3, Point<Type> p4);

    ~Tetrahedron();

private :


    float ComputeCRadius();

    float ComputeIRadius();

    float GetQuality();

    Point<Type> *Points;
    Triangle<Type> *Faces;
    Line<Type> *Edges;
    float Volume;
    float InRadius;
    float CircumRadius;
    float Quality;
};