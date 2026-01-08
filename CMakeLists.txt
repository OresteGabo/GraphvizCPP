cmake_minimum_required(VERSION 4.0)
project(ArchiViz)

# --- Configuration du Projet ---
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# --- Dépendances Qt6 ---
find_package(Qt6 COMPONENTS
        Core
        Gui
        OpenGL
        OpenGLWidgets
        Widgets
        REQUIRED
)

# --- Liste des Sources ---
set(ENGINE_FILES
        src/engine/DrawingArea.cpp
        include/engine/DrawingArea.h
        src/engine/Shape.cpp
        include/engine/Shape.h
        src/engine/CompositeObject.cpp
        include/engine/CompositeObject.h
)

set(PRIMITIVE_FILES
        src/primitives/Cube.cpp
        include/primitives/Cube.h
        src/primitives/Chair.cpp
        include/primitives/Chair.h
        src/primitives/Sphere.cpp
        include/primitives/Sphere.h
        src/primitives/Pyramid.cpp
        include/primitives/Pyramid.h
        src/primitives/Cylinder.cpp
        include/primitives/Cylinder.h
)

# --- Exécutable ---
add_executable(ArchiViz
        main.cpp
        ${ENGINE_FILES}
        ${PRIMITIVE_FILES}
        resources.qrc
)

# --- Liaison des Bibliothèques ---
target_link_libraries(ArchiViz
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGL
        Qt::OpenGLWidgets
)