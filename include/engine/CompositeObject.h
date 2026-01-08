//
// Created by muhirwa gabo Oreste on 08/11/2025.
//

#ifndef ARCHIVIZ_COMPOSITEOBJECT_H
#define ARCHIVIZ_COMPOSITEOBJECT_H


// CompositeObject.h
#pragma once
#include "Shape.h"
#include <QList>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>


// Hériter de Shape permet à CompositeObject d'avoir m_position et d'être traité comme n'importe quel objet
class CompositeObject : public Shape {
public:
    CompositeObject(const QVector3D &pos = QVector3D(0,0,0)) : Shape(pos) {}
    virtual ~CompositeObject();

    void addShape(Shape* shape, const QMatrix4x4 &transform);

    // On surcharge le draw de Shape
    void draw(QOpenGLShaderProgram *program, QMatrix4x4 viewProjection);

    // Obligatoire car Shape est abstraite
    void generateGeometry() override {}
    void init() override; // Implémentation de base pour les objets composites

protected:
    struct Entry { Shape* shape; QMatrix4x4 transform; };
    QList<Entry> m_shapes;
};




#endif //ARCHIVIZ_COMPOSITEOBJECT_H