//
// Created by muhirwa gabo Oreste on 08/11/2025.
//

// Chair.cpp

#include "Chair.h"
#include <QMatrix4x4>

Chair::Chair(const QVector3D &position, float scale)
    : CompositeObject(position), m_scale(scale)
{
    // Constructor of CompositeObject already sets m_position
    // Geometry is generated in init(), not here.
}

Chair::~Chair() {
    // CompositeObject destructor will handle deleting children shapes
}

void Chair::init() {
    // --- Define Dimensions Relative to a Unit Chair ---
    // All dimensions will be multiplied by m_scale

    // Seat dimensions
    float seatWidth = 10.0f * m_scale;
    float seatDepth = 10.0f * m_scale;
    float seatHeight = 1.0f * m_scale;

    // Backrest dimensions
    float backrestWidth = 9.0f * m_scale;
    float backrestDepth = 1.0f * m_scale;
    float backrestHeight = 12.0f * m_scale;

    // Leg dimensions
    float legRadius = 0.5f * m_scale;
    float legHeight = 15.0f * m_scale; // Legs go from ground up to seat bottom

    // --- 1. Create Seat ---
    Cube* seat = new Cube(QVector3D(0,0,0), 1.0f); // Cube is unit-sized initially
    seat->setColor(QVector4D(0.6f, 0.4f, 0.2f, 1.0f)); // Brownish

    QMatrix4x4 seatTransform;
    seatTransform.scale(seatWidth, seatHeight, seatDepth);
    // Position the seat above the legs. Its center should be at halfH + halfHeightOfSeat
    seatTransform.translate(0.0f, legHeight + (seatHeight / 2.0f), 0.0f);
    addShape(seat, seatTransform);

    // --- 2. Create Backrest ---
    Cube* backrest = new Cube(QVector3D(0,0,0), 1.0f);
    backrest->setColor(QVector4D(0.6f, 0.4f, 0.2f, 1.0f));

    QMatrix4x4 backrestTransform;
    backrestTransform.scale(backrestWidth, backrestHeight, backrestDepth);
    // Position behind the seat, relative to its center
    // Y-pos: seat top + half backrest height
    // Z-pos: half seat depth + half backrest depth (to be behind the seat)
    backrestTransform.translate(0.0f, legHeight + seatHeight + (backrestHeight / 2.0f), -(seatDepth / 2.0f + backrestDepth / 2.0f));
    addShape(backrest, backrestTransform);


    // --- 3. Create 4 Legs (Cylinders) ---
    // Leg positions are relative to the chair's center and its local coordinate system

    float legXOffset = seatWidth / 2.0f - legRadius;
    float legZOffset = seatDepth / 2.0f - legRadius;

    // Front-Left Leg
    Cylinder* legFL = new Cylinder(legRadius, legHeight, 16); // radius, height, segments
    legFL->setColor(QVector4D(0.5f, 0.3f, 0.1f, 1.0f)); // Slightly darker brown
    QMatrix4x4 legFLTransform;
    legFLTransform.translate(-legXOffset, legHeight / 2.0f, legZOffset); // Center of cylinder is at its height/2
    addShape(legFL, legFLTransform);

    // Front-Right Leg
    Cylinder* legFR = new Cylinder(legRadius, legHeight, 16);
    legFR->setColor(QVector4D(0.5f, 0.3f, 0.1f, 1.0f));
    QMatrix4x4 legFRTransform;
    legFRTransform.translate(legXOffset, legHeight / 2.0f, legZOffset);
    addShape(legFR, legFRTransform);

    // Back-Left Leg
    Cylinder* legBL = new Cylinder(legRadius, legHeight, 16);
    legBL->setColor(QVector4D(0.5f, 0.3f, 0.1f, 1.0f));
    QMatrix4x4 legBLTransform;
    legBLTransform.translate(-legXOffset, legHeight / 2.0f, -legZOffset);
    addShape(legBL, legBLTransform);

    // Back-Right Leg
    Cylinder* legBR = new Cylinder(legRadius, legHeight, 16);
    legBR->setColor(QVector4D(0.5f, 0.3f, 0.1f, 1.0f));
    QMatrix4x4 legBRTransform;
    legBRTransform.translate(legXOffset, legHeight / 2.0f, -legZOffset);
    addShape(legBR, legBRTransform);

    // CRITICAL: Initialize all child shapes' OpenGL resources
    // This MUST happen after all children are added and their geometry defined.
    for (const auto& entry : m_shapes) {
        if (entry.shape) {
            // NOTE: The base Shape::init() will call generateGeometry() if needed internally
            // but for Cube/Cylinder/Sphere it's done in their constructors.
            entry.shape->init();
        }
    }
}