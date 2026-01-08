//
// Created by muhirwa gabo Oreste on 08/11/2025.
//

// Chair.cpp

#include "../../include/primitives/Chair.h"
#include <QMatrix4x4>

Chair::Chair(const QVector3D &position, float scale)
    : CompositeObject(position), m_scale(scale){}

Chair::~Chair() {
    // CompositeObject destructor will handle deleting children shapes
}

void Chair::buildGeometry() {
    // Initialise les fonctions OpenGL pour ce contexte
    initializeOpenGLFunctions();

    // --- Dimensions relatives basées sur m_scale ---
    float seatWidth = 10.0f * m_scale;
    float seatDepth = 10.0f * m_scale;
    float seatHeight = 1.0f * m_scale;

    float backrestWidth = 9.0f * m_scale;
    float backrestHeight = 12.0f * m_scale;
    float backrestDepth = 1.0f * m_scale;

    float legRadius = 0.5f * m_scale;
    float legHeight = 15.0f * m_scale;

    // --- 1. Création du Siège (Seat) ---
    Cube* seat = new Cube();
    seat->setColor(QVector4D(0.6f, 0.4f, 0.2f, 1.0f));
    QMatrix4x4 seatT;
    seatT.translate(0.0f, legHeight + (seatHeight / 2.0f), 0.0f);
    seatT.scale(10.0f * m_scale, seatHeight, 10.0f * m_scale);
    addShape(seat, seatT);

    // --- 2. Création du Dossier (Backrest) ---
    Cube* backrest = new Cube();
    backrest->setColor(QVector4D(0.6f, 0.4f, 0.2f, 1.0f));

    QMatrix4x4 backrestTransform;
    // Positionné derrière le siège et vers le haut
    backrestTransform.translate(0.0f, legHeight + seatHeight + (backrestHeight / 2.0f), -(seatDepth / 2.0f + backrestDepth / 2.0f));
    backrestTransform.scale(backrestWidth, backrestHeight, backrestDepth);
    addShape(backrest, backrestTransform);

    // --- 3. Création des 4 Pieds (Cylinders) ---
    float legX = (seatWidth / 2.0f) - legRadius;
    float legZ = (seatDepth / 2.0f) - legRadius;

    // Positions des 4 coins
    QVector3D legPositions[4] = {
        QVector3D(-legX, legHeight / 2.0f,  legZ), // Avant-Gauche
        QVector3D( legX, legHeight / 2.0f,  legZ), // Avant-Droit
        QVector3D(-legX, legHeight / 2.0f, -legZ), // Arrière-Gauche
        QVector3D( legX, legHeight / 2.0f, -legZ)  // Arrière-Droit
    };

    for (int i = 0; i < 4; ++i) {
        Cylinder* leg = new Cylinder(legRadius, legHeight, 16);
        leg->setColor(QVector4D(0.5f, 0.3f, 0.1f, 1.0f)); // Marron foncé

        QMatrix4x4 legTransform;
        legTransform.translate(legPositions[i]);
        // Le cylindre est déjà créé avec le bon rayon/hauteur, pas besoin de scale ici
        addShape(leg, legTransform);
    }

    // --- CRITIQUE : Initialisation des ressources GPU pour chaque enfant ---
    // Cette boucle alloue les VBO/VAO sur la carte graphique pour chaque morceau
    for (const auto& entry : m_shapes) {
        if (entry.shape) {
            entry.shape->init();
        }
    }
}
void Chair::init() {
    // 1. Construire la hiérarchie (Logique spécifique à la chaise)
    buildGeometry(); // Fonction d'aide pour ajouter les cubes/cylindres

    // 2. Appeler l'initialisation parente (Logique générique OpenGL)
    // Cela va boucler sur tous les objets ajoutés dans buildGeometry et appeler leur init()
    CompositeObject::init();
}



