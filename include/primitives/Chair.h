//
// Created by muhirwa gabo Oreste on 08/11/2025.
//
// Chair.h
#ifndef ARCHIVIZ_CHAIR_H
#define ARCHIVIZ_CHAIR_H

#include "../engine/CompositeObject.h"
#include "Cube.h"
#include "Cylinder.h"

class Chair : public CompositeObject {
public:
    Chair(const QVector3D &position = QVector3D(0,0,0), float scale = 1.0f);
    ~Chair() ;

    // We don't need to override generateGeometry() because CompositeObject
    // doesn't have a geometry of its own, it just positions other shapes.
    // However, we MUST override init() to initialize its children shapes.
    void init() override;
    void buildGeometry();

private:
    float m_scale;
};

#endif //ARCHIVIZ_CHAIR_H