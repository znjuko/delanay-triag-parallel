//
// Created by znjuko on 15.05.2020.
//

#include <tuple>
#include <vector>
#include "tetrahedron.h"


template<typename Type>
Tetrahedron<Type>::Tetrahedron(Point<Type> p1, Point<Type> p2, Point<Type> p3, Point<Type> p4) {
    Points = new Point<Type>[4]{p1, p2, p3, p4};

    Faces = new Triangle<Type>[4]{
            Triangle<Type>(p4, p3, p2),
            Triangle<Type>(p1, p3, p4),
            Triangle<Type>(p4, p2, p1),
            Triangle<Type>(p1, p2, p3),
    };

    Edges = new Line<Type>[6]{
            Line<Type>(p1, p2),
            Line<Type>(p1, p3),
            Line<Type>(p1, p4),
            Line<Type>(p2, p3),
            Line<Type>(p2, p4),
            Line<Type>(p3, p4),
    };

    std::vector<std::vector<Type>> volumeMatrix(4);

    std::vector<Type> fVec(4);
    fVec.push_back(p1.GetX());
    fVec.push_back(p1.GetY());
    fVec.push_back(p1.GetZ());
    fVec.push_back(1);
    volumeMatrix.push_back(fVec);

    std::vector<Type> sVec(4);
    sVec.push_back(p2.GetX());
    sVec.push_back(p2.GetY());
    sVec.push_back(p2.GetZ());
    sVec.push_back(1);
    volumeMatrix.push_back(sVec);

    std::vector<Type> tVec(4);
    tVec.push_back(p3.GetX());
    tVec.push_back(p3.GetY());
    tVec.push_back(p3.GetZ());
    tVec.push_back(1);
    volumeMatrix.push_back(tVec);

    std::vector<Type> fourVec(4);
    fourVec.push_back(p4.GetX());
    fourVec.push_back(p4.GetY());
    fourVec.push_back(p4.GetZ());
    fourVec.push_back(1);
    volumeMatrix.push_back(fourVec);

    Volume = 1 / 6 * Solve44(volumeMatrix);
    CircumRadius = ComputeCRadius();
    InRadius = ComputeIRadius();
    Quality = GetQuality();
};

template<typename Type>
Tetrahedron<Type>::~Tetrahedron() {
    delete[] Points;
    delete[] Faces;
    delete[] Edges;
}

template<typename Type>
float Tetrahedron<Type>::ComputeCRadius() {

    Type a = Edges[0].GetLength();
    Type a1 = Edges[5].GetLength();
    Type b = Edges[1].GetLength();
    Type b1 = Edges[4].GetLength();
    Type c = Edges[2].GetLength();
    Type c1 = Edges[3].GetLength();
    Type p = 1 / 2 * (a * a1 + b * b1 + c * c1);
    return sqrt(p * (p - a * a1) * (p - b * b1) * (p - c * c1));
};

template<typename Type>
float Tetrahedron<Type>::ComputeIRadius() {
    return float(3 * Volume / (Faces[0].GetArea() + Faces[1].GetArea() + Faces[2].GetArea() + Faces[3].GetArea()));
}

template<typename Type>
float Tetrahedron<Type>::GetQuality() {

    float hs = 0;
    for (unsigned int i = 0; i < 6; i++) {
        hs += Edges[i].GetLength() * Edges[i].GetLength();
    }

    hs = sqrt(hs);

    return sqrt(3) / 216 * pow(hs, 3) / Volume;
};